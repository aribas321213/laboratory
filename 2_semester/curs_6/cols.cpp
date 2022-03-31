#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include "student.h"

void usage(){
    printf("Usage: programm [-key] input_filename output_filename\n");
    printf("Keys: \n");
    printf("-f output all data \n");
    printf("-t complete the task \n");
}

int main(int argc, char *argv[]){
    if (argc != 4){
        usage();
        return 1;
    }
    student s;
    FILE *fi = (fi=fopen(argv[2],"r"));
    if (!fi){
        perror("Can`t open input file");
        return 2;
    }
    FILE *fo = (fo=fopen(argv[3],"wb"));
    if (!fo){
        perror("Can`t open output file");
        return 2;
    }
    if(!strcmp(argv[1], "-f")){
        printf("========================================================\
=========\n");
        printf("|  Surname and initials  |Is entrant|Is medal| Math | Inf | Fiz |\n");
        printf("=================================================================\n");
        while(!feof(fi)){
            fread(&s, sizeof(s), 1, fi);
            fprintf(fo,"surname=%s initsial=%s initsial=%s is_medal=%s math=%d inf=%d fiz=%d\n", s.surname, s.initsial, s.is_entrant, s.is_medal, s.math, s.inf, s.fiz);
            printf("|      %-10s %2s     |   %3s    |  %3s   |  %1d   |  %1d  |  %1d  |\n", s.surname, s.initsial, s.is_entrant, s.is_medal, s.math, s.inf, s.fiz);
            printf("-----------------------------------------------------------------\n");
        }
    }
    else{
        if (!strcmp(argv[1], "-t")){
            printf("=================================================================\n");
            printf("|  Surname and initials  |Is entrant|Is medal| Math | Inf | Fiz |\n");
            printf("=================================================================\n");
            while(!feof(fi)){
                fread(&s, sizeof(s), 1, fi);
                if (!strcmp(s.is_entrant, "yes") 
                    && !strcmp(s.is_medal, "yes") 
                    && (s.math < 3)){
                    fprintf(fo,"surname=%s initsial=%s initsial=%s is_medal=%s math=%d inf=%d fiz=%d\n", s.surname, s.initsial, s.is_entrant, s.is_medal, s.math, s.inf, s.fiz);
                    printf("|      %-10s %2s     |   %3s    |  %3s   |  %1d   |  %1d  |  %1d  |\n", s.surname, s.initsial, s.is_entrant, s.is_medal, s.math, s.inf, s.fiz);
                    printf("-----------------------------------------------------------------\n");
                }
            }
        }
        else{
            perror("Invalid key");
            return 1;
        }
    }
}