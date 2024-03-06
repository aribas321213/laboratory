import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm, t, chi2
import statsmodels.api as sm
from sympy import symbols, Matrix, sqrt

class Model:
    '''
    ## Класс для модели наблюдений. 
    ### Описывается следющим
    и параметрами:
    - m: теоретический порядок многочлена
    - thetha: теоретические параметры модели
    - sigma: дисперсия отклонений ошибок наблюдений
    - normal_eps: булевая переменная. Принимает True если ошибки распределены нормально, иначе False (по умолчанию True)
    - n: количество наблюдений (по умолчанию 40)
    '''
    def __init__(self, m:int, theta:list[float], sigma:float, normal_eps:bool=True, n:int=40):
        self.m = m
        self.n = n
        self.theta = theta
        np.random.seed(42)
        self.sigma = sigma
        if normal_eps:
            self.eps = np.random.normal(0, sigma, n)
        else: 
            self.eps = np.random.uniform(-3*np.sqrt(sigma), 3*np.sqrt(sigma), n)
        self.x_k = np.array([-4 + k*(8/n) for k in range(1,n+1)])

        self.estimate_coefficients = []
        

    @property
    def params(self):
        assert len(self.estimate_coefficients) != 0, "Коэффициенты не найдены"
        return self.estimate_coefficients
    
    @property
    def mse(self) -> float:
        y_obs = self.phi(self.x_k)+self.eps
        y_pred = self.predict(self.x_k)
        residuals = y_obs - y_pred
        mse = np.sum(residuals ** 2) / (self.n - len(self.params))
        return mse
    
    @property
    def y_obs(self):
        return self.phi(self.x_k)+self.eps

    def phi(self, x) -> float:
        '''
        ## Теоретическая функция полезного сигнала
        '''
        return sum([self.theta[i]*(x**i) for i in range(self.m+1)])

    def predict(self, x) -> float:
        '''
        ## Функция оценки полезного сигнала
        ''' 
        return sum([self.params[i]*(x**i) for i in range(len(self.estimate_coefficients))])
    
    def fit(self, degree:int):
        '''
        ## Функция для оценки коэффициентов многочлена
        ### Параметры: 
        - degree: порядок многочлена
        '''
        X = np.vander(self.x_k, degree+1, increasing=True)
        y = self.phi(self.x_k)+self.eps
        self.estimate_coefficients = np.linalg.inv(X.T @ X) @ X.T @ y
        return self.estimate_coefficients
    

    def parameters_confidence_intervals(self, alpha = 0.05):
        '''
        ## Расчет доверительного интервала для найденных параметров
        ### Параметры: 
        - alpha: уровень значимости (по умолчанию 0.05)
        '''

        # расчет стандартных ошибок параметров
        X = np.vander(self.x_k, len(self.params), increasing=True)
        std_errors = np.sqrt(np.diagonal(self.mse * np.linalg.inv(np.dot(X.T, X))))

        # Определение степеней свободы
        degrees_of_freedom = self.n - len(self.params)

        # Определение критического значения t для уровня значимости и степеней свободы
        t_critical = t.ppf(1 - alpha/2, df=degrees_of_freedom)

        # Построение доверительных интервалов
        confidence_intervals = []
        for i in range(len(self.params)):
            lower_bound = self.params[i] - t_critical * std_errors[i]
            upper_bound = self.params[i] + t_critical * std_errors[i]
            confidence_intervals.append((lower_bound, upper_bound))
        
        return confidence_intervals
       
    def prediction_interval(self, x_pred, alpha=0.05):
        '''
        ## Расчет предсказательного интервала
        ### Параметры: 
        - x_pred: значение для предсказания
        - alpha: уровень значимости (по умолчанию 0.05)
        '''

        def vandermonde_matrix(variables, n):
            """
            Создает вендермондову матрицу для заданных переменных и степени n.
            """
            return Matrix([[var**i for i in range(n)] for var in variables])

        # Определяем матрицу
        x = symbols('x')
        A = vandermonde_matrix([x], len(self.params))

        X = np.vander(self.x_k, len(self.params), increasing=True) 
        
        # Критическое значение t для выбранного уровня доверия
        t_value = t.ppf(1 - alpha / 2, df=self.n-len(self.params))
        
        # Стандартная ошибка предсказания для нового наблюдения
        B = np.linalg.inv(np.dot(X.T, X))

        f = ((self.mse * ((A * B) * A.T)).applyfunc(sqrt))

        betas = Matrix(self.params)
        pred = A * betas
        low_edge = pred - t_value * f
        high_edge = pred + t_value * f
        print(f'{(1-alpha)*100}% interval: ({low_edge[0]},{high_edge[0]})' )
        l, h = [], []
        for x_val in x_pred:
            l.append(low_edge.subs({x:x_val})[0])
            h.append(high_edge.subs({x:x_val})[0])

        return np.array(l).astype(float), np.array(h).astype(float)

    def vizualize_data_1(self):
        '''
        ## Функция визуализации истинной функции и набора наблюдений 
        '''
        x = np.linspace(-4, 4, 100)
        plt.figure(figsize=(8, 4))
        plt.plot(x, self.phi(x), color='red', label='Истинная функция сигнала')
        plt.scatter(self.x_k, self.phi(self.x_k)+self.eps, color='blue', label='Набор наблюдений')
        plt.xlabel('x')
        plt.ylabel('y')
        plt.legend()
        plt.show()


    def vizualize_data_2(self):
        '''
        ## Функция визуализации истинной функции и оценки функции 
        '''
        x = np.linspace(-4, 4, 100)
        plt.figure(figsize=(8, 4))
        plt.plot(x, self.phi(x), color='red', label='Истинная функция сигнала')
        plt.plot(x, self.predict(x), color='blue', label='Оценка функции сигнала')
        plt.xlabel('x')
        plt.ylabel('y')
        plt.legend()
        plt.show()


    def build_hist(self):
        '''
        ## Построение гистограммы распределения остатков
        '''

        y_estimate = self.predict(self.x_k)

        # Расчет остатков
        residuals = self.y_obs - y_estimate

        # Выбор количества интервалов (бинов)
        num_bins = int(3.32*np.log10(self.n)+1)

        # Разделение данных на интервалы
        hist, bin_edges = np.histogram(residuals, bins=num_bins, density=True)
        hist_for_print, _ = np.histogram(residuals, bins=num_bins, density=False)
        # Вычисление ширины интервала
        bin_width = bin_edges[1] - bin_edges[0]
        expected_freq = np.diff([0]+ list(norm.cdf(bin_edges, loc=0, scale=(np.sum(residuals**2) / (self.n))))+[1])
        estimated_freq = [0] + list(hist*bin_width) + [0]

        chi2_statistic = len(self.x_k)*np.sum((estimated_freq - expected_freq) ** 2 / expected_freq)
        p_value = 1 - np.sum(chi2.cdf(chi2_statistic, df=len(bin_edges) - 1))
        # Построение гистограммы

        plt.figure(figsize=(8, 4))
        plt.hist(residuals, bins=num_bins, density=True, color='skyblue', edgecolor='black')
        x_range = np.linspace(bin_edges[0], bin_edges[-1], 100)
        normal_distribution = norm.pdf(x_range, 0, np.std(residuals))
        plt.plot(x_range, normal_distribution, color='red', label='Нормальное распределение')

        # Добавление подписей и оформление
        plt.title('Гистограмма распределения данных')
        plt.xlabel('Значения')
        plt.ylabel('Относительная частота')
        plt.legend()
        plt.show()

        return p_value, chi2_statistic

    
    
def iterative_t_test(X, y, n, alpha=0.05):
    
    X_with_intercept = np.vander(X, n+1, increasing=True)
    
    num_samples, num_features = X_with_intercept.shape
    
    # Инициализация массива для хранения t-статистик
    t_stats = np.zeros(num_features)
    
    # Оценка коэффициентов регрессии с помощью метода наименьших квадратов
    betas = np.linalg.inv(X_with_intercept.T.dot(X_with_intercept)).dot(X_with_intercept.T).dot(y)
    
    # Оценка дисперсии ошибок
    y_pred = X_with_intercept.dot(betas)
    residuals = y - y_pred
    error_variance = np.sum(residuals ** 2) / (num_samples - num_features)
    
    # Вычисление стандартных ошибок оценок коэффициентов
    se_betas = np.sqrt(np.diag(error_variance * np.linalg.inv(X_with_intercept.T.dot(X_with_intercept))))
    
    # Вычисление t-статистик
    t_stats = betas / se_betas
    
    # Вычисление p-значений
    degrees_freedom = num_samples - num_features
    p_values = 2 * (1 - t.cdf(np.abs(t_stats), df=degrees_freedom))
    
    flag = True
        # Проверка на значимость коэффициента при заданном уровне значимости
    if p_values[n] < alpha:
        print(f"theta_{n} является статистически значимым.")
    else:
        print(f"theta_{n} не является статистически значимым.")
        flag = False
    return flag