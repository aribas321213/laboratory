#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// F(x) = arctan(x)

int main(){
    double eps = 1, x, S, p, a =0, b = 0.5, step = (b-a)/10.;
    int n;
    while(1+eps>1) eps/=2.;
    printf("\neps=%21.19f\n",eps);
    printf("\n------------------------------------------------------------------------------\n");
    printf("|    x     |              S              |         arctg(x)         |    n   |\n");
    printf("|----------------------------------------------------------------------------|\n");
    for(x=a; x<=b+0.001; x+=step) {
        S=p=x; n=1;
        while(p>eps||-p>eps){          
            p=-p*x*x;   
            S+=p/(2*n+1);          
            n++;
        }
        printf("|    %4.2f  |    %21.19f    |   %21.19f  |   %3d  |\n", x, S, atan(x), n);
    }
    printf("------------------------------------------------------------------------------\n");
}