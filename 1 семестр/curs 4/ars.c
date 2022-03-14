#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1024
#define DEL " .,:;\n\t!?-"

typedef struct ELT
{
    int data;
    struct ELT *next;
}ELT;

void Create(ELT **phead, ELT **plast)
{
    *phead = (ELT*)malloc(sizeof(ELT));
    (*phead) -> next = NULL;
    *plast = *phead;
}

int Is_Q(int a)
{
    while (a > 1)
    {
        if (a % 3 != 0) return 0;
        a/=3;
    }
    return 1;
}

int Is_T(int a)
{
    while (a)
    {
        if (a % 10 == 5)
            return 0;
        a /= 10;
    }
    return 1;
}

void Add(ELT **last, int a)
{
    ELT *k;
    k = (ELT*)malloc(sizeof(ELT));
    k->data = a;
    k->next = NULL;
    (*last)->next = k;
    *last = k;
}

int ReadFile(char* fname, ELT** last)
{
    FILE*f;
    char str[N], *word;
    int i, j, k, flag[256] = { 0 };
    if((f = fopen(fname,"r")) == NULL)
        return 1;
    for (i = 0; DEL[i]; i++)
        flag[DEL[i]] = 1;
    while (fgets(str, N, f) != NULL)
    {
        for (i = 0; str[i] && flag[str[i]]; i++)
            ;
        while (str[i])
        {
            word = str + i;
            while (str[i] && !flag[str[i]])
                i++;
            j = i;
            while (str[i] && flag[str[i]])
                i++;
            str[j] = '\0';
            Add(last, atoi(word));
        }

    }
    fclose(f);
    return 0;
}

void Del(ELT **last, ELT *head)
{
    ELT *q, *buf;
    q = head;
    while(q->next != NULL)
    {
        if(Is_T(q->next->data))
        {
            buf = q->next;
            q->next = buf->next;
            free(buf);
        }
        else q = q -> next;
    }
    *last = q;
}

void Print(ELT *head)
{
    if(head != NULL)
    {
        printf("%d->",head->data);
        Print(head->next);
    }
}

void Distruct(ELT *head, ELT **last)
{
    ELT *q, *buf;
    q = head -> next;
    while(q != NULL)
    {
        buf = q;
        q = q->next;
        free(buf);
    }
    head ->next = NULL;
    *last = head;
}

int Cnt_of_Q(ELT *head)
{
    ELT *q;
    int Cnt = 0;
    q = head->next;
    for(q = q->next; q != NULL; q = q->next)
        if(Is_Q(q->data))
            Cnt++;
    return Cnt;
}

int main()
{
    ELT *head, *last;
    Create(&head, &last);
    ReadFile("file1.txt", &last);
    printf("Список до удаления элементов: ");
    Print(head->next);printf("NULL");puts("");
    Del(&last, head);
    printf("Список после удаления элементов: ");
    Print(head->next);printf("NULL");
    printf("\nКол-во чисел, удовлетворяющих условию Q: %d\n",Cnt_of_Q(head));
    Distruct(head, &last);
    Print(head->next);
    free(head);
    return 0;
}
