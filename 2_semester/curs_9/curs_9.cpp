#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_sorted = 0;

struct Row{
    int key;
    char *string;
};

int get_size(FILE *input){
    int n = 0;
    char* buffer = new char[128];
    size_t l = sizeof(buffer);
    while(!feof(input)){
        getline(&buffer, &l, input);
        n++;
    }
    delete [] buffer;
    rewind(input);
    return n;
}

void print_table(Row *table, int size){
    printf("-----------------------------\
------------------------------\n");
    printf("| Key |                       Data\
                        |\n");
    printf("------------------------------\
-----------------------------\n");
    for(int i = 0; i<size; ++i){
        printf("|%3d  | %s", table[i].key, table[i].string);
        printf("--------------------------\
---------------------------------\n");
    }
    printf("\n");
}

Row * make_table(FILE *keys, FILE *data, int size){
    Row * table = new Row[size];
    for (int i = 0; i < size; ++i){
        table[i].string = new char[128];
    }
    for (int i = 0; i < size; ++i){
        fscanf(keys, "%d", &table[i].key);
        fgets(table[i].string, 128, data);
    }
    return table;
}

void swap_strings(Row * table, int a, int b){
    Row tmp;
    tmp = table[a];
    table[a] = table[b];
    table[b] = tmp;
}

void siftDown(Row *table, int root, int bottom){
    int maxChild;
    int done = 0;
    while ((root*2 <= bottom) && (!done)){
        if (root*2 == bottom)
        maxChild = root*2;
        else if (table[root*2].key > table[root*2+1].key){
            maxChild = root*2;
        }
        else{
            maxChild = root*2+1;
        }
        if (table[root].key < table[maxChild].key){
            swap_strings(table, root, maxChild);
            root = maxChild;
        }
        else done = 1;
    }
}

void heapSort(Row *table, int size){
    for (int i = (size / 2); i >= 0; i--){
        siftDown(table, i, size - 1);
    }
    for (int i = size - 1; i >= 1; i--){
        swap_strings(table, 0, i);
        siftDown(table, 0, i - 1);
    }
}

void sort_table(Row * table, int size){
    is_sorted = 1;
    heapSort(table, size);
}

void mix_table(Row * table, int size){
    is_sorted = 0;
    int a, b;
    for(int i = 0; i<size; ++i){
        a = rand() % size;
        b = rand() % size;
        swap_strings(table, a, b);
    }
}

int bin_search(Row * table, int key, int size){
    int l = 0, r = size - 1, mid;
    while (l<=r){
        mid = (r + l)/2;
        if (key == table[mid].key){
            return mid;
        }
        else if(key < table[mid].key){
            r = mid;
        }
        else if(key > table[mid].key){
            l = mid+1;
        }
    }
    return -1;
}

void reverse_strings(Row * table, int size){
    is_sorted = 0;
    for(int i = 0, j = size - 1; i < j; ++i, --j){
        swap_strings(table, i, j);
    }
}

int main(){
    srand(time(0));
    FILE* file1 = fopen("in1", "r");
    if (file1 == NULL ){
        printf("Can not open file1\n");
        return 0;
    }
    FILE* file2 = fopen("in2", "r");
    if (file2 == NULL ){
        printf("Can not open file2\n");
        return 0;
    }
    int n = get_size(file1), action;
    Row *table = make_table(file1, file2, n);
    fclose(file1);
    fclose(file2);
    print_table(table, n);
    while(1){
        printf("Menu\n");
        printf("1) Print table\n");
        printf("2) Binary search\n");
        printf("3) Sort table\n");
        printf("4) Mix table\n");
        printf("5) Reverse table\n");
        printf("6) Exit\n");
        printf("Choose an action ===> ");
        scanf("%d", &action);
        switch (action){
            case 1:{
                print_table(table, n);
                break;
            }
            case 2:{
                if(is_sorted){
                    printf("Enter the key: ");
                    int k;
                    scanf("%d", &k);
                    int search;
                    printf("\n");
                    search = bin_search(table, k, n);
                    if (search == -1){
                        printf("Element with such key is not found!\n");
                        break;
                    }
                    printf("Found the string:\n %s", table[search].string);
                }
                else printf("Table is not sorted!\n");
                break;
            }
            case 3:{
                sort_table(table, n);
                break;
            }
            case 4:{
                mix_table(table, n);
                break;
            }
            case 5:{
                reverse_strings(table, n);
                break;
            }
            case 6: return 0;
        }
    }
}
