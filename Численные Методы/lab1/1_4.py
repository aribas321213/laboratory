"""
Реализовать метод вращений в виде программы, задавая
в качестве входных данных матрицу и точность вычислений.
Используя разработанное программное обеспечение, найти
собственные значения и собственные векторы симметрических
матриц. Проанализировать зависимость погрешности вычислений
от числа итераций.

Вариант: 26
"""

import numpy as np


def jacobi_rotation(A, tol=1e-10, max_iter=1000):
    n = len(A)
    eigenvectors = np.eye(n)

    for _ in range(max_iter):
        max_off_diag = 0
        p = 0
        q = 0

        for i in range(n):
            for j in range(i+1, n):
                if abs(A[i, j]) > max_off_diag:
                    max_off_diag = abs(A[i, j])
                    p = i
                    q = j

        if max_off_diag < tol:
            break

        if A[p, p] == A[q, q]:
            theta = np.pi / 4
        else:
            theta = 0.5 * np.arctan(2 * A[p, q] / (A[p, p] - A[q, q]))

        c = np.cos(theta)
        s = np.sin(theta)

        R = np.eye(n)
        R[p, p] = c
        R[p, q] = -s
        R[q, p] = s
        R[q, q] = c

        A = np.dot(np.dot(R.T, A), R)
        eigenvectors = np.dot(eigenvectors, R)

    eigenvalues = np.diag(A)

    return eigenvalues, eigenvectors


if __name__ == "__main__":
    A = np.array([[4, -1, -7],
                  [1, 9, 1],
                  [-7, 1, 7]])
    eigenvalues, eigenvectors = jacobi_rotation(A)
    print("Eigenvalues:", eigenvalues)
    print("Eigenvectors:", eigenvectors)
