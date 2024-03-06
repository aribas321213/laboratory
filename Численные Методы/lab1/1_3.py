"""
Реализовать метод простых итераций и метод Зейделя в виде программ,
задавая в качестве входных данных матрицу системы, вектор правых частей
и точность вычислений. Используя разработанное программное обеспечение,
решить СЛАУ. Проанализировать количество итераций, необходимое для достижения
заданной точности.

Вариант: 26
"""


def simple_iteration_method(A: list[list[int]], b: list[int], x0: list[int],
                            tolerance=1e-10, max_iterations=1000):
    """Метод простых итераций для решения системы линейных уравнений

    Args:
        - A (list[list[int]]): Матрица системы
        - b (list[int]): Вектор правых частей
        - x0 (list[int]): Начальное приближение
        - tolerance (float, optional): Точность вычислений. Defaults to 1e-10.
        - max_iterations (int, optional): Максимальное количество итераций.
        Defaults to 1000.

    Raises:
        Exception: Метод не сошелся

    Returns:
        tuple[list[int], int]: Решение системы и количество итераций
    """
    n = len(b)
    C = [[-A[i][j] / A[i][i] if i != j else 0 for j in range(n)]
         for i in range(n)]
    d = [b[i] / A[i][i] for i in range(n)]

    X0 = x0.copy()
    iteration = 0
    while iteration < max_iterations:
        X = [sum(C[i][j] * X0[j] for j in range(n)) + d[i] for i in range(n)]

        if max([abs(X[i] - X0[i]) for i in range(n)]) <= tolerance:
            return X, iteration + 1
        X0 = X.copy()
        iteration += 1

    raise Exception("Метод не сошелся за максимальное количество итераций")


def gauss_seidel(A: list[list[int]], b: list[int], x0: list[int],
                 tolerance=1e-10, max_iterations=1000):
    """Метод Зейделя для решения системы линейных уравнений

    Args:
        - A (list[list[int]]): Матрица системы
        - b (list[int]): Вектор правых частей
        - x0 (list[int]): Начальное приближение
        - tolerance (float, optional): Точность вычислений. Defaults to 1e-10.
        - max_iterations (int, optional): Максимальное количество итераций.
        Defaults to 1000.

    Raises:
        Exception: Метод не сошелся

    Returns:
        tuple[list[int], int]: Решение системы и количество итераций
    """
    n = len(b)
    x = x0.copy()
    iteration = 0
    while iteration < max_iterations:
        for i in range(n):
            sum1 = sum(A[i][j] * x[j] for j in range(i))
            sum2 = sum(A[i][j] * x[j] for j in range(i + 1, n))
            x[i] = (b[i] - sum1 - sum2) / A[i][i]

        residual = [b[i] - sum(A[i][j] * x[j] for j in range(n))
                    for i in range(n)]
        if max(abs(residual[i]) for i in range(n)) < tolerance:
            return x, iteration + 1

        iteration += 1

    raise Exception("Метод не сошелся за максимальное количество итераций")


if __name__ == "__main__":
    A = [[18, 0, -2, 7],
         [-1, 14, -3, 2],
         [5, 5, 26, 7],
         [-2, -6, 9, 24]]

    b = [50, 2, 273, 111]
    x0 = [0, 0, 0, 0]

    # Решение методом простых итераций
    solution_s_i, iterations_s_i = simple_iteration_method(A, b, x0)
    print("Метод простых итераций:")
    print("Решение:", solution_s_i)
    print("Количество итераций:", iterations_s_i)

    # Решение методом Зейделя
    solution_gauss_seidel, iterations_gauss_seidel = gauss_seidel(A, b, x0)
    print("\nМетод Зейделя:")
    print("Решение:", solution_gauss_seidel)
    print("Количество итераций:", iterations_gauss_seidel)
