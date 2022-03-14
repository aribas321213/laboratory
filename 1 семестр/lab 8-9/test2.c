#include <stdio.h>
int main () {
    int a, b, c;
    scanf ("%d%d%d", &a, &b, &c);
    while(c>0){
        a *= b;
        printf ("%u\n", a);
        c -= 1;
    }
    return 0;
}