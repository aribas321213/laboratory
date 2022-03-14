#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Инициализация массива
void INIT_mas(int ** &a, int n){
    a = new int* [n]; 
    for (int i = 0; i < n; i++){
        a[i] = new int [n];
        for (int j = 0; j < n; j++){
            a[i][j] = (rand()%(n*n) + 1);
        }
    }
}

// Вывод массива
void PRINT_mas(int **a, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Подсчет суммы в массиве по данной строке
int SUMM(int **a, int n, int index){
    int s = 0;
    for (int i = 0; i<n; i++){
        s += a[index][i];
    }
    return s;
}


// Функция с решением 
void SOLVE(int **a, int n){
    int max_element = -1, min_index = n+1;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (a[i][j] > max_element){
                max_element =  a[i][j];
                min_index = i;
            }
        }
    }
    printf("\nMax element: %d, min str index: %d", max_element, min_index);
    printf("\nResult: %d\n", SUMM(a, n, min_index));
}
 
int main(){
    int **a, n;
    printf("Enter matrix size: ");
    scanf("%d", &n);
    INIT_mas(a, n);
    printf("\nMassive is created!\n");
    PRINT_mas(a, n);
    SOLVE(a, n);
    return 0;
}

