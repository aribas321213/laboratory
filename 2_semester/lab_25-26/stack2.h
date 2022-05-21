// Реализация на динамических структурах 

#define N 100
#define Tvalue int

struct St{ 
    Tvalue Value;
    St *next;
};

struct Stack{
    St *first;
    int size;
};

void Init(Stack &S){ 
    S.first=0; 
    S.size=0; 
}

int Empty(Stack S){
    return S.first==0;
}

void Push(Stack &S, Tvalue V){
    if (S.size == N){
        printf("\nStack is overflow!!!\n");
    }
    else{
        St *t = new St;
        t->next = S.first; 
        S.first=t;
        S.first->Value = V; 
        S.size++;
    }    
}

Tvalue Pop(Stack &S){
    if(!Empty(S)){
        Tvalue V = S.first->Value;
        St *elem = S.first;
        S.first = S.first->next;
        delete elem;
        S.size--;
        return V;
    }
    else{  
        printf("\nStack is Empty!!!\n");
        return 0;
    }
}

Tvalue Top(Stack &S){
    if(!Empty(S)){
        return S.first->Value;
    }
    else{  
        printf("\nStack is Empty!!!\n");
        return 0;
    }
}

int Size(Stack S){
    return S.size;
}

void Display(Stack S){  
    if(Empty(S)){
        printf("\nStack is Empty!!!\n");
    }
    else{
        printf("[ ");
        St *t = S.first;
        while(t) {
            printf("%d ",t->Value); 
            t=t->next;
        }
	    printf("]\n");
    }
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
