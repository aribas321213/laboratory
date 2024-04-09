import numpy as np


def simple_iteration_system(F, x0, tol, max_iter=50):
    """
    Метод простой итерации для решения системы нелинейных уравнений F(x) = 0.
    
    Параметры:
    F (функция): Система нелинейных уравнений в виде функции, возвращающей 
    вектор значений.
    x0 (numpy.ndarray): Начальное приближение корней.
    tol (float): Требуемая точность вычислений.
    max_iter (int): Максимальное количество итераций.
    
    Возвращает:
    roots (numpy.ndarray): Приближенные значения корней.
    iterations (int): Количество выполненных итераций.
    """

    x = x0.copy()
    for i in range(max_iter):
        print(x)
        x_new = x - 0.01*F(x)
        if np.linalg.norm(x_new - x) < tol:
            return x_new, i + 1
        x = x_new
    return x, max_iter


def newton_method_system(F, J, x0, tol, max_iter=100):
    """
    Метод Ньютона для решения системы нелинейных уравнений F(x) = 0.
    
    Параметры:
    F (функция): Система нелинейных уравнений в виде функции, возвращающей 
    вектор значений.
    J (функция): Функция, возвращающая матрицу Якоби для системы F(x).
    x0 (numpy.ndarray): Начальное приближение корней.
    tol (float): Требуемая точность вычислений.
    max_iter (int): Максимальное количество итераций.
    
    Возвращает:
    roots (numpy.ndarray): Приближенные значения корней.
    iterations (int): Количество выполненных итераций.
    """
    x = x0.copy()
    for i in range(max_iter):
        J_x = J(x)
        if np.linalg.det(J_x) == 0:
            print("Матрица Якоби вырождена. Метод не может быть применен.")
            return None, i
        F_x = F(x)
        delta_x = np.linalg.solve(J_x, -F_x)
        x_new = x + delta_x
        if np.linalg.norm(x_new - x) < tol:
            return x_new, i + 1
        x = x_new
    return x, max_iter


# Пример использования
def F(x):
    return np.array([
        2*(x[0]**2) - x[1] + x[1]**2 - 2,
        x[0] - np.sqrt(x[1]+2) + 1
    ])


def J(x):
    return np.array([
        [4*x[0], 2*x[1]-1],
        [1, -1/(2*np.sqrt(x[1]+2))]   
    ])


tol = 1e-10
x0 = np.array([0.8, 1.40])  # Начальное приближение, определенное графически

# Метод простой итерации
roots, iterations = simple_iteration_system(F, x0, tol)
print(f"Метод простой итерации: Корни = {roots}, Итераций = {iterations}")


x0 = np.array([0, 1])  # Начальное приближение, определенное графически

# Метод Ньютона
roots, iterations = newton_method_system(F, J, x0, tol)
print(f"Метод Ньютона: Корни = {roots}, Итераций = {iterations}")