#include <stdio.h>
#include <stdlib.h>
#include <random>
#include "stack1.h"

void Sort(Stack &S){
    for(int i = Size(S); i>0; i--){
        int q = Del_max(S, i);
        Stack tmp;
        Init(tmp);
        while (!Empty(S)){
            Push(tmp, Pop(S));
        }
        Push(S, q);
        while (!Empty(tmp)){
            Push(S, Pop(tmp));
        }
    }
}

int main()
{
    srand(time(0));
    Stack S;
    Init(S); Tvalue v; int k;
    while(1){
        printf("-----------Menu----------\n");
        printf("| 1) Make random stack  |\n");
        printf("|    2) Print stack     |\n");
        printf("|     3) Push value     |\n");
        printf("|     4) Pop value      |\n");
        printf("|   5) Read top value   |\n");
        printf("|   6) Size of stack    |\n");
        printf("|  7) Sorting of stack  |\n");
        printf("|     8) Print Menu     |\n");
        printf("|        9) Exit        |\n");
        printf("-------------------------\n");
        printf("Choose an action ===> ");
        scanf("%d", &k);
        switch (k){
            case 1:{
                int s; 
                printf("\nType length of stack (<100): "); 
                scanf("%d",&s);
                printf("\n"); 
                while(s--){
                    Push(S,rand()%100);
                }
                break;
            }
            case 2:{
                printf("\n");
                Display(S);
                printf("\n");
                break;
            }
            case 3:{
                Tvalue s; 
                printf("\n");
                printf("Type value: "); 
                scanf("%d",&s);
                printf("\n");
                Push(S,s);
                break;
            }
            case 4:{
                Tvalue q = Pop(S);
                printf("\n%d was popped!\n\n", q);
                break;
            }
            case 5:{
                printf("\nTop value = %d\n\n", Top(S));
                break;
            }
            case 6:{
                printf("\nSize of stack = %d\n\n", Size(S));
                break;
            }
            case 7:{
                Sort(S);
                break;
            }
            case 8:{
                break;
            }
            case 9: return 0;
        }
    }
    return 0;
}