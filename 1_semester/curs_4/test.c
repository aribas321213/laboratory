#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
 

struct Rec1
{
	int nomer; 
	char mark[20]; 
	int diag;       //!!!! диагональ в дюймах	
	char matrix[20]; // тип матрицы
	float price;
};
 

struct Rec2
{
	char mark[20]; 
	int diag; 
	char matrix[20];
	float price;
};
 

int Menu(void)
{
	int select;
 
	do
	{
		printf("1 - СОЗДАНИЕ ДВОИЧНОГО ФАЙЛА ДАННЫХ");
		printf("\n2 - ДОБАВИТЬ ЗАПИСЬ В КОНЕЦ ДВОИЧНОГО ФАЙЛА");
		printf("\n3 - ПРОСМОТР ВСЕХ ЗАПИСЕЙ ВХОДНОГО ДВОИЧНОГО ФАЙЛА");
		printf("\n4 - ОБРАБОТКА ДАННЫХ ИЗ ДВОИЧНОГО ФАЙЛА");
		printf("\n5 - ПРОСМОТР ВСЕХ ЗАПИСЕЙ ВЫХОДНОГО ДВОИЧНОГО ФАЙЛА");
		printf("\n6 - ВЫХОД ИЗ ПРОГРАММЫ");
		printf("\n\tВыбор: ");
		scanf("%d", &select);
	}
	while((select < 1) || (select > 6));
 
	return select;
}
 
void CreateFileIn(char *fileName)
{
	FILE *f;
	int mark_count;
	int i;
	struct Rec1 mon;
 
	f = fopen(fileName, "wb");
	printf("\nВведите количество мониторов ");
	scanf("%d", &mark_count);
 
	for(i = 0; i < mark_count; i++)
	{
		fflush(stdin);
		mon.nomer = i + 1;
		printf("\nВвод информации о Мониторе №%d\n", i + 1);
		printf("\t - введите производителя монитора: ");
		scanf ("%s", &mon.mark);
		printf("\t - введите диагональ в дюймах: ");
		scanf("%d", &mon.diag);
		printf("\t - введите тип матрицы: ");
		scanf("%s", &mon.matrix);
		printf("\t - введите цену: ");
		scanf("%f", &mon.price);
		fwrite(&mon, sizeof(struct Rec1), 1, f);
	}
	fclose(f);
}
 

void AddFileIn(char *fileName)
{
	struct Rec1 mon;
	FILE *f;
	fflush(stdin);
	f = fopen(fileName, "ab");
	fseek(f, 0, SEEK_END);
	mon.nomer = ftell(f) / sizeof(struct Rec1) + 1; //порядковый номер монитора
	printf("\t - введите производителя монитора: ");
	scanf ("%s", &mon.mark);
	printf("\t - введите диагональ в дюймах: ");
	scanf("%d", &mon.diag);
	printf("\t - введите тип матрицы: ");
	scanf("%s", &mon.matrix);
	printf("\t - введите цену: ");
	scanf("%f", &mon.price);
	fwrite(&mon, sizeof(struct Rec1), 1, f);
 
	fclose(f);
}
 

void ReadFileIn(char *nameFile)
{
	struct Rec1 mon;
	FILE *f;
	fflush(stdin);
	f = fopen(nameFile, "rb");
	printf("\t---------------------------------------------------------------------------------------\n");
	printf("\t| # |    Производитель монитора     | Диагональ     |     Тип Матрицы   |     Цена    |\n");
	printf("\t---------------------------------------------------------------------------------------\n");
	while(fread(&mon, sizeof(struct Rec1), 1, f))
		printf("\t| %d | %23s | %16d |  %8s | %12.2f |\n", mon.nomer, mon.mark,mon.diag, mon.matrix, mon.price);
	printf("\t---------------------------------------------------------------------------------------\n");
	fclose(f);
}


void CreateFileOut(char *fileName1, char *fileName2)
{
	FILE *fin, *fout;
	int max_diag = 0;
	struct Rec1 mon_in;
	struct Rec2 mon_out;
	fin = fopen(fileName1, "rb");
	while(fread(&mon_in, sizeof(struct Rec1), 1, fin))
		if(mon_in.diag > max_diag)
			max_diag = mon_in.diag;
	rewind(fin);
	
	fout = fopen(fileName2, "wb");
	while(fread(&mon_in, sizeof(struct Rec1), 1, fin)){
		if(mon_in.diag == max_diag){
			mon_out.diag = mon_in.diag;
			mon_out.price = mon_in.price;
			strcpy(mon_out.mark, mon_in.mark);
			fwrite(&mon_out, sizeof(struct Rec2), 1, fout);
		}}
	fclose(fin);
	fclose(fout);
}


void ReadFileOut(char *nameFile)
{
	struct Rec2 mon;
	FILE *f;
 
	f = fopen(nameFile, "rb");
	printf("\t------------------------------------------------------------------------------------\n");
	printf("\t|    Производитель монитора     |  Диагональ  |      Тип Матрицы    |     Цена     |\n");
	printf("\t------------------------------------------------------------------------------------\n");
	while(fread(&mon, sizeof(struct Rec2), 1, f))
		printf("\t| %23s | %16d | %8s | %12.2f |\n", mon.mark,mon.diag, mon.matrix, mon.price);
	printf("\t------------------------------------------------------------------------------------\n");
	fclose(f);
}
 

int main(void)
{
	int select;					
	setlocale(LC_ALL, "");	 
	do
	{
		select = Menu();		// вызов меню
		switch(select)
		{
		case 1:
			{
				CreateFileIn("in.bin");
				printf("\nИнформация успешно добавлена в двоичный файл.\n");
				break;
			}
		case 2:
			{
				AddFileIn("in.bin");
				printf("\nИнформация успешно добавлена в конец двоичного файла.\n");
				break;
			}
			case 3:
			{
				printf("\nИнформация в заданном двоичном файле:\n");
				ReadFileIn("in.bin");
				break;
			}
		case 4:
			{
				CreateFileOut("in.bin", "out.bin");
				printf("\nВыходной результирующий двоичный файл успешно сформирован.\n");
				break;
			}
		case 5:
			{
				printf("\nИнформация обо всех мониторах, имеющих наибольшую диагональ:\n");
				ReadFileOut("out.bin");
				break;
			}
		}
	}
	while(select != 6);
	
	return 0;
}