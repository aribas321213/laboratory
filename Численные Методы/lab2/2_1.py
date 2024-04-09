"""
Реализовать методы простой итерации и Ньютона
решения нелинейных уравнений в виде программ,
задавая в качестве входных данных точность вычислений.
С использованием разработанного программного
обеспечения найти положительный корень нелинейного
уравнения (начальное приближение определить графически).
Проанализировать зависимость погрешности вычислений от количества итераций.
"""

import numpy as np


def simple_iteration(f, x0, eps=1e-8, alpha=0.1, max_iter=1000):
    x = x0
    dif_x = []
    for iter in range(max_iter):
        x_new = x - alpha * f(x)  # Выбор подходящего коэффициента
        dif_x.append(abs(x - x_new))
        if abs(x_new - x) < eps:
            break
        x = x_new

    return x, dif_x


def newton_method(f, df, x0, tol, max_iter=100):
    x = x0
    for i in range(max_iter):
        if df(f, x) == 0:
            print("Производная равна нулю. Метод не может быть применен.")
            return None, i
        x_new = x - f(x) / df(f, x)
        if abs(x_new - x) < tol:
            return x_new, i + 1
        x = x_new
    return x, max_iter


def f(x):
    # return 2**x - x**2 - 0.5
    return np.log10(x+1) - x + 0.5


# Её производная
def df(f, x):
    eps = 1e-10
    return (f(x+eps)-f(x))/eps

# Найдем корень с помощью простого метода итерации


epsilon = 1e-6  # точность
max_iter = 1000  # максимальное количество итераций

x0_simple = -0.5  # начальное приближение
root_simple, iter_simple = simple_iteration(f, x0_simple)
print("Простой метод итерации: корень =", root_simple)

# Теперь найдем корень с помощью метода Ньютона
x0_newton = -0.5  # начальное приближение
root_newton, iter_newton = newton_method(f, df, x0_newton, epsilon, max_iter)
print("Метод Ньютона: корень =", root_newton)

