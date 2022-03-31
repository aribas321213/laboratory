#include<stdio.h>
#include<string.h>
#include<errno.h>

#include "student.h"

void usage(){
    printf("Usage: programm input_filename output_filename\n");
}


int main(int argc, char *argv[]){
    if (argc != 3){
        usage();
        return 1;
    }
    student s;
    FILE *fi, *fo;
    fi = (fi=fopen(argv[1],"r"));
    if (!fi){
        perror("Can`t open input file");
        return 2;
    }
    fo = (fo=fopen(argv[2],"wb"));
    if (!fo){
        perror("Can`t open output file");
        return 2;
    }
    while(!feof(fi)){
        fscanf(fi,"%s %s %s %s %d %d\t%d\n", s.surname, s.initsial, s.is_entrant, s.is_medal, &s.math, &s.inf, &s.fiz);
        fwrite(&s, sizeof(s), 1,fo);
    }
    
    return 0;
}