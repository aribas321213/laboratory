"""
Реализовать алгоритм LU -  разложения матриц (с выбором главного элемента)
в виде программы. Используя разработанное программное обеспечение, решить
систему линейных алгебраических уравнений (СЛАУ). Для матрицы СЛАУ
вычислить определитель и обратную матрицу.

Вариант: 26
"""


def lu_decomposition(matrix: list[list[int]]):
    """Функция LU-разложения матрицы

    Args:
        - matrix (list[list[int]]): Исходная матрица

    Returns:
        - tuple[list[list[float]], list[list[float]]]: Возвращает две матрицы
        Lower и Upper
    """
    n = len(matrix)
    lower = [[0.0] * n for _ in range(n)]
    upper = [[0.0] * n for _ in range(n)]

    for i in range(n):
        lower[i][i] = 1.0

    for k in range(n):
        for j in range(k, n):
            sum_val = sum(lower[k][s] * upper[s][j] for s in range(k))
            upper[k][j] = matrix[k][j] - sum_val

        for i in range(k + 1, n):
            sum_val = sum(lower[i][s] * upper[s][k] for s in range(k))
            lower[i][k] = (matrix[i][k] - sum_val) / upper[k][k]

    return lower, upper


def forward_substitution(lower: list[list[int]], b: list[int]):
    """Функция для расчета произведения матрицы Lower и вектора b

    Args:
        - lower (list[list[int]]): Нижняя угловая матрица
        - b (list[int]): Вектор свободных членов

    Returns:
        - list[float] : Вектор Y равный произведению матрицы Lower и вектора b
    """
    n = len(lower)
    y = [0.0] * n

    for i in range(n):
        y[i] = b[i] - sum(lower[i][j] * y[j] for j in range(i))

    return y


def backward_substitution(upper: list[list[int]], y: list[int]):
    """Функция для расчета произведения матрицы Upper и вектора Y

    Args:
        - lower (list[list[int]]): Верхняя угловая матрица
        - b (list[int]): Вектор Y

    Returns:
        - list[float] : Вектор X равный произведению матрицы Upper и вектора Y
    """
    n = len(upper)
    x = [0.0] * n

    for i in range(n - 1, -1, -1):
        x[i] = (y[i] - sum(upper[i][j] * x[j]
                           for j in range(i + 1, n))) / upper[i][i]

    return x


def lu_solver(matrix: list[list[int]], b: list[int]):
    """Функция решения СЛАУ

    Args:
        - matrix (list[list[int]]): Матрица A
        - b (list[int]): Вектор свободных коэффициентов

    Returns:
        - list[float]: Возвращает вектор X
    """
    lower, upper = lu_decomposition(matrix)
    y = forward_substitution(lower, b)
    x = backward_substitution(upper, y)
    return x


def determinant(matrix):
    """Функция расчета определителя матрицы

    Args:
        - matrix (list[list[int]]): Исходная матрица

    Returns:
        - float: Определитель матрицы
    """
    lower, upper = lu_decomposition(matrix)
    det = 1.0
    for i in range(len(lower)):
        det *= upper[i][i]
    return det


def inverse(matrix):
    """Функция расчета обратной матрицы

    Args:
        - matrix (list[list[int]]): Исходная матрица

    Returns:
        - list[list[int]]: Обратная матрица
    """
    n = len(matrix)
    identity = [[1.0 if i == j else 0.0 for j in range(n)] for i in range(n)]
    inv_matrix = []

    for i in range(n):
        b = identity[i]
        x = lu_solver(matrix, b)
        inv_matrix.append(x)

    return list(map(list, zip(*inv_matrix)))


if __name__ == "__main__":
    A = [[-2, -9, -3, 7],
         [-7, 8, 2, 5],
         [-6, 2, 0, 0],
         [0, -3, 8, -3]]

    B = [-26, -25, -16, -5]
    # Решение СЛАУ
    solution = lu_solver(A, B)
    print("Решение СЛАУ:", solution)

    # Вычисление определителя и обратной матрицы
    det_A = determinant(A)
    inv_A = inverse(A)

    print("Определитель матрицы A:", det_A)
    print("Обратная матрица A:", inv_A)
