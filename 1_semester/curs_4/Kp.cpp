#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define eps 0.00000001

double function_1(double x){
    return 3*x - 4*log(x) - 5;
}
double Function_1(double x){
    return (4*log(x) + 5)/3;
}

double derivative_1(double x){
    return 3 - 4/x;
}

double function_2(double x){
    return 3*x - sin(2*x)+cos(4*x)-6;
}
double Function_2(double x){
    return (sin(2*x)-cos(4*x)+6)/3;
}

double derivative_2(double x){
    return 3 - 2*cos(2*x)-4*sin(4*x);
}

double function_3(double x){
    return 3*log(1/x)-cos(x)+5*x-13;
}
double Function_3(double x){
    return (cos(x)+13-3*log(1/x))/5;
}

double derivative_3(double x){
    return  (-3)/x + sin(x) + 5;
}

double dichotomy(double function(double), double left, double right){
    double result;
    while(fabs(left - right) > eps)
    {
        result = (right + left) / 2;
        if (function(left) * function(result) > 0) left = result;
        else right = result;
    }
    return result;
}

double iteration(double function(double), double left, double right){
    double x = (left + right) / 2;
    double previousX = 0;
    while(fabs(x - previousX) > eps)
    {
        previousX = x;
        x = function(x);
    }
    return x;
}

double newton(double function(double), double derivative(double), double left, double right){
    double x = (left + right) / 2;
    double previousX = 0;
    while(fabs(x - previousX) > eps){
        previousX = x;
        x = x - function(x) / derivative(x);
    }
    return x;
}


double chord(double f(double), double a, double b) {
    double prevX = b, ya = f(a), yb = f(b);
    double x = (ya*b-yb*a)/(ya-yb);
    while(fabs(prevX - x) > eps) {
        if(ya*f(x) > 0) a = x;
        else b = x;
        ya = f(a), yb = f(b);
        prevX = x;
        x = (ya*b-yb*a)/(ya-yb);
    }
    return x;
}



int main() {
    printf("------------------------------------------------------------------------------\n");
    printf("|           Уравнение             | Отрезок |   Метод   |     Результат      |\n");
    printf("------------------------------------------------------------------------------\n");
    
    printf("| 3 * x - 4 * log(x) - 5 = 0      |  [2;4]  | Дихотомии | %.16f |\n", dichotomy(function_1, 2, 4));
    printf("|                                 |         |  Итераций | %.16f |\n", iteration(Function_1, 2, 4));
    printf("|                                 |         |  Ньютона  | %.16f |\n", newton(function_1,  derivative_1, 2, 4));
    printf("|                                 |         |    Хорд   | %.16f |\n", chord(function_1, 2, 4));
    printf("------------------------------------------------------------------------------\n");

    printf("| 3*x - sin(2x)+cos(4x)-6 = 0     |  [1;2]  | Дихотомии | %.16f |\n", dichotomy(function_2, 1, 2));
    printf("|                                 |         |  Итераций | %.16f |\n", iteration(Function_2, 1, 2));
    printf("|                                 |         |  Ньютона  | %.16f |\n", newton(function_2,  derivative_2, 2, 2));
    printf("|                                 |         |    Хорд   | %.16f |\n", chord(function_2, 1, 2));
    printf("------------------------------------------------------------------------------\n");

    printf("| 3*log(1/x)-cos(x)+5*x-13 = 0    |  [3;4]  | Дихотомии | %.16f |\n", dichotomy(function_3, 3,4));
    printf("|                                 |         |  Итераций | %.16f |\n", iteration(Function_3, 3,4));
    printf("|                                 |         |  Ньютона  | %.16f |\n", newton(function_3,  derivative_3, 3,4));
    printf("|                                 |         |    Хорд   | %.16f |\n", chord(function_3, 3,4));
    printf("------------------------------------------------------------------------------\n");

    return 0;

}

