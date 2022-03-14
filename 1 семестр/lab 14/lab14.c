#include <stdio.h>
#define N 100

// Инициализация массива
void InitMas(int mas[N][N], int n){
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<n; ++j){
            mas[i][j] = (i+1)*10+j+1;
        }
    }
}

// Вывод массива
void PrintMas(int mas[N][N], int n){
    printf("\nComplited matrix:\n");
    for (int i = 0; i<n; ++i){
        for (int j = 0; j<n; ++j){
            printf("%d ", mas[i][j]);
        }
        printf("\n");
    }
}

// Результат
void Result(int mas[N][N], int n){
    int cnt = 1, i = (n+1)/2 - 1, j = (n+1)/2 - 1, g = 0, c = 0;
    printf("\nResult:\n");
    printf("%d ", mas[i][j]);
    while (cnt < n*n){
        for(c = ++g;   c && cnt < n*n; c--){
            printf("%d ", mas[++i][j]);
            cnt++;
        }
        for(c = g; c && cnt < n*n; c--){
            printf("%d ", mas[i][++j]);
            cnt++;
        }
        for(c = ++g;c && cnt < n*n; c--){
            printf("%d ", mas[--i][j]);
            cnt++;
        } 
        for(c = g; c && cnt < n*n; c--){
            printf("%d ", mas[i][--j]);
            cnt++;
        } 
        
    }
    printf("\n");
}


int main(){
    int mas[N][N], n = 0;
    printf("Input a size of matrix (n>=100): ");
    scanf("%d", &n);
    InitMas(mas, n);
    PrintMas(mas, n);
    Result(mas, n);
    return 0;
}
