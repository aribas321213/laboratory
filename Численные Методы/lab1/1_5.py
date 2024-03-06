"""
Реализовать алгоритм QR – разложения матриц в виде программы.
На его основе разработать программу, реализующую QR – алгоритм
решения полной проблемы собственных значений произвольных матриц,
задавая в качестве входных данных матрицу и точность вычислений.
С использованием разработанного программного обеспечения найти
собственные значения матрицы.

Вариант: 26
"""

import numpy as np


def qr_decomposition(matrix):
    m, n = matrix.shape
    q = np.zeros((m, n))
    r = np.zeros((n, n))

    for i in range(n):
        v = matrix[:, i]
        for j in range(i):
            r[j, i] = np.dot(q[:, j], matrix[:, i])
            v -= r[j, i] * q[:, j]

        r[i, i] = np.linalg.norm(v)
        q[:, i] = v / r[i, i]

    return q, r


def qr_algorithm(matrix, epsilon=1e-6, max_iterations=1000):
    current_matrix = matrix.copy()

    for _ in range(max_iterations):
        q, r = qr_decomposition(current_matrix)
        current_matrix = np.dot(r, q)

        if np.linalg.norm(np.triu(current_matrix, k=1)) < epsilon:
            break

    eigenvalues = np.diag(current_matrix)

    return eigenvalues


if __name__ == "__main__":
    A = np.array([[-9, -9, -3],
                  [-9, 0, -2],
                  [-5, -1, -4]], dtype=float)

    eigenvalues = qr_algorithm(A)
    print("Собственные значения матрицы:", eigenvalues)
