#include <stdio.h>
int reverse(int a){
    int b = 0;
    while(a>0){
        int c = a%10;
        b = b*10 + c;
        a /= 10;
    }
    return b;
}
int main(){
    int n, s1 = 0, s2 = 0, s3 = 0;
    scanf("%i", &n);
    while (n>0){
        int a = (n%10);
        if (a%3==0){
            s1 = s1*10 + a;
        }
        if (a%3==1){
            s2 = s2*10 + a;
        }
        if (a%3==2){
            s3 = s3*10 + a;
        }
        n /= 10;
    }
    s1 = reverse(s1);
    s2 = reverse(s2);
    s3 = reverse(s3);
    printf("--------\nПервое число: %d;\nВторое число: %d;\nТретье число: %d;\nСумма чисел: %d;\n", s1, s2, s3, s1+s2+s3);
    return 0;
}