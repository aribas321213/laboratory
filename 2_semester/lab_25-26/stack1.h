// Реализация на массивах


#define N 100
#define Tvalue int

struct Stack{
    int first;
    Tvalue body[N];
};

void Init(Stack &S){
    S.first = 0;
}

int Empty(Stack S){
    return S.first == 0;
}

void Push(Stack &S, Tvalue V){
    if (S.first == N){
        printf("Stack is overflow!!!");
    }
    else{
        S.body[S.first++] = V;
    }
}

Tvalue Pop(Stack &S){
    if (!Empty(S)){
        return S.body[--S.first];
    }
    else{
        printf("Stack is Empty!!!");
        return 0;
    }
}

Tvalue Top(Stack &S){
    if (!Empty(S)){
        return S.body[S.first - 1];
    }
    else{
        printf("Stack is Empty!!!");
        return 0;
    }
}

int Size(Stack S){
    return S.first;
}

void Display(Stack S){
    printf("[ ");
    for (int i = 0; i < S.first; i++){
        printf("%d ", S.body[i]);
    }
    printf("]\n");
}

Tvalue Del_max(Stack &S, int n){
    Tvalue mx = 0;
    Stack tmp;
    Init(tmp);
    for (int i = 0; i<n; i++){
        if (Top(S)>mx) mx = Top(S);
        Push(tmp, Pop(S));
    }
    while (!Empty(tmp) && Top(tmp)!=mx){
        Push(S,Pop(tmp));
    }
    if(Top(tmp)==mx){
        Pop(tmp);
    }
    while (!Empty(tmp)){
        Push(S,Pop(tmp));
    }

    return mx;
}



