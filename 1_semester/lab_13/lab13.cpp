#include <stdio.h>
#include "Set.h"
#define n 30

// Выводит длину сета
int Len(char S[]){
  int l = 0;
  for(int i = 0; i<2*N; i++){
    if (S[i] == 1){
      l++;
    }
  }
  return l;
}

// Сравнение двух сетов
int checker(char W1[], char W2[]){
    char cur_set[N*2], last_set[N*2];
    CreateSet(W1, cur_set); CreateSet(W2, last_set);
    int l1 = Len(cur_set); int l2 = Len(last_set);
    if ((l1 - l2 == 1) || (l2 - l1 == 1)){
        return 1;
    }
    return 0;
}

// Копирует слово W1 в W2
void copy(char W1[], char W2[]){
    for(int i = 0; i<n; ++i){
        W2[i] = W1[i];
    }
}

// Выводит слово
void PrintWord(char W[]){
    char c;
    for (int i=0; c = W[i]; i++){
        printf("%c", c);
    }
    printf(" ");
}

int main(){
    char s0 = ' ', s=' ', cur_word[n], last_word[n];
    int c = 0, count = 0;
    last_word[0]='\0';
    while (s != EOF){
        s = getchar();
        if (!Letter(s0) && Letter(s)){
            c = 0;
            cur_word[c] = s;
        }
        else if (Letter(s0) && Letter(s)){
            cur_word[++c] = s;
        }
        else if (Letter(s0) && !Letter(s)){
            cur_word[++c] = '\0';
            if (last_word[0] != '\0'){
                if(checker(cur_word, last_word)){
                    printf("Встретилась следующая пара слов: ");
                    PrintWord(last_word); PrintWord(cur_word);
                    printf("\n");
                    count++;
                }
            }
            copy(cur_word, last_word);
        }
        s0 = s;
    }
    printf ("Всего встретилось %d пар\n", count);    
    return 0;
}