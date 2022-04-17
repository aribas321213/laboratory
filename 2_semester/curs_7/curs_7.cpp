#include <stdio.h>
#include <stdlib.h>

// convert full to short
void ftosh(float ** matrix, int n, int m, int *cip, int *pi, float *ye){
    int k = 0;
    for (int i = 0; i<n; i++){
        int was_no_zero = 0;
        for (int j = 0; j<m; j++){
            if (matrix[i][j]!=0){
                ye[k] = matrix[i][j];
                pi[k] = j;
                if (!was_no_zero){
                    was_no_zero = 1;
                    cip[i] = k;
                }
                k++;
            }
        }
        if (!was_no_zero){
            cip[i] = -1;
        }
    }
}

// convert short to full
void shtof (float ** matrix, int n, int *cip, int *pi, float *ye , int k){
    int s;
    int start, last_i;
    for (s = 0; cip[s] == -1 && s<n; ++s);
    
    for (int i = s; i<n; ++i){
        start = cip[i];
        if (start == -1){
            continue;
        }
        int j;
        for (j = i+1; cip[j] == -1 && j<n-1; j++);
        last_i = i;
        for (int l = start; l < cip[j]; l++){
            matrix[i][pi[l]] = ye[l];
        }
    }
    for (int l = cip[last_i]; l < k; l++){
        matrix[last_i][pi[l]] = ye[l];
    }
    
}

// convert full matrix
void print_f_matrix(float ** matrix, int n, int m){
    printf("Full matrix:\n");
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            printf("%2.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// convert short matrix
void print_sh_matrix(int *cip, int *pi, float *ye, int k, int n){
    printf("Short matrix:\n");
    printf("CIP: ");
    for (int i = 0; i<n; i++){
        printf("%d ", cip[i]);
    }
    printf("\n");
    printf("PI: ");
    for (int i = 0; i<k+1; i++){
        printf("%d ", pi[i]);
    }
    printf("\n");
    printf("YE: ");
    for (int i = 0; i<k; i++){
        printf("%2.2f ", ye[i]);
    }
    printf("\n");
}

// transform matrix matrix
void transform_matrix(float ** matrix, int n, int m, int max_v){
    for (int i = 0; i< n; ++i){
        for (int j = 0; j< m; ++j){
            if (matrix[i][j] == max_v || matrix[i][j] == -max_v){
                for (int c = 0; c< m; ++c){
                    matrix[i][c] /= max_v;
                }
                break;
            }
        }
    }
}

int main(){
    float **matrix, *ye;
    int *cip, *pi;
    int n, m, k;
    printf("Input n = \n"); scanf("%d",&n); 
    printf("Input m =\n"); scanf("%d",&m);
    printf("Input k =\n"); scanf("%d",&k);
    matrix = new float*[n];
    pi = new int[k+1];
    ye = new float[k];
    cip = new int[n];
    int max_v = 0;

    for (int i = 0; i<n; i++){
        matrix[i] = new float[m];
    }

    printf("Input short matrix:\n");
    printf("CIP: ");
    for (int i = 0; i<n; i++){
        scanf("%d", &cip[i]);
    }
    printf("\n");
    printf("PI: ");
    for (int i = 0; i<k+1; i++){
        scanf("%d", &pi[i]);
    }
    printf("\n");
    printf("YE: ");
    for (int i = 0; i<k; i++){
        scanf("%f", &ye[i]);
        if (ye[i] > max_v || -ye[i] > max_v){
            max_v = ye[i];
        }
    }

    if (max_v < 0) max_v = -max_v;


    printf("\n");
    printf("\n");
    print_sh_matrix(cip, pi, ye, k, n);
    shtof (matrix, n, cip, pi, ye, k);
    print_f_matrix(matrix, n, m);
    transform_matrix(matrix, n, m, max_v);

    printf("\n");
    printf("After transform:\n");
    printf("\n");
    print_f_matrix(matrix, n, m);
    ftosh(matrix, n, m, cip, pi, ye);
    print_sh_matrix(cip, pi, ye, k, n);

    return 0;

}
