#include <stdio.h>

bool is_in_circle(int x, int y){
    if (((x + 10)*(x + 10) + (y + 10)*(y + 10) <= 10*10) && ((x + 20)*(x + 20) + (y + 20)*(y + 20) <= 10*10)){
        return true;
    }
    return false;
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

int main(){
    int i = 7, j = -4, l = -10, k = 0;

    while(!(is_in_circle(i,j)) && k<50){
        int z = i, x =  j, c = l;
        i = max(47 * z % 25, min(47 *x % 30, 47 * c % 30)) - k % 15;
        j = min(max(47 * z % 25, 47 * x % 25), 47 * c % 30) + k % 5;
        l = 47 * z * x * c % 25 + k % 5;
        k++;
    }
    if (is_in_circle(i,j) && (k<=50)){
        printf("Точка с координатами (%d,%d) с динамическим параметром %d на %d-ом шаге попала в данную область. \n", i, j, l, k);
    }
    else{
        printf("Точка не попала в заданную область. Конечные координаты (%d,%d), динамический параметр: %d, шаг: %d \n", i, j, l, k);
    }
    return 0;

}