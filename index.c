#include <stdio.h> // библиотека для вывода на экран
#include <string.h>
#include <ctype.h>


#define MAXLEN 20


void display(char source[], FILE *file);


int main(){
    // переменная , хранящая ссылку на файл
    FILE *fp;
    FILE *fp2;

    fp=fopen("IN.txt", "r"); 
    fp2 = fopen("OUT.txt", "w");
        
        // проверка на существование исходного файла
        if(fp == NULL){
            printf( "Sorry, file don`t find\n");
            return 1;
        }

        display("IN.txt", fp);

        // создаем переменную для хранения числа , полученного из файла
        int temp = 0;
        // временная переменная для получения символа из файла
        char c;
        // переменная для хранения количества нечетных чисел
        int oddCount = 0;

        // прогоняем цикл , обрабатывая посимвольно ввод  
        do{
            // получаем во временную переменную символ
            c = fgetc(fp);

            // проверка на корректность введеных в исходный файл данных
            if(!(isdigit(c)) && (c != ' ') && (c != EOF)){
                fprintf(fp2, "Sorry, file is incorrect\n");
                return 2;

            }
            // проверка является ли с числовым данным
            if(isdigit(c)){
                // преобразуем в целочисленный тип данных
                temp = temp * 10 + (c - 48);
            } else{
                // проверка на нечетность
                if(temp % 2 != 0){
                    oddCount++;
                }
                // обнуляем переменную
                temp = 0;
            }
        } while(c != EOF);
        
        // выводим количество нечетных чисел в второй файл
        fprintf(fp2, " %d", oddCount);

        display("OUT.txt", fp2);
        
    fclose(fp);//закрываем исходный файл
    fclose(fp2);//закрываем файл для записи



    fp = fopen("IN.dat", "r");

    // проверка на существование исходного файла
        if(fp == NULL){
            printf( "Sorry, file don`t find\n");
            return 1;
        }

        display("IN.dat", fp);
        c = 'a';
        temp = 0;
        int count = 0;
        int arr[MAXLEN];
        int i = 0;

        do
        {
            c = getc(fp);

            // проверка на корректность введенных в исходный файл данных
            if(!(isdigit(c)) && (c != ' ') && (c != EOF)){
                fp2 = fopen("IN.dat", "w"); 
                fprintf(fp2, "Sorry, file is incorrect\n");
                return 2;
            }

            // проверка является ли с числовым данным
            if(isdigit(c)){
                // преобразуем в целочисленный тип данных
                temp = temp * 10 + (c - 48);
            } else{
                // проверка на нечетность
                arr[i] = temp;
                // обнуляем переменную
                temp = 0;
                i++;
                count++;
            }

        } while (c != EOF);
        
        for (int i = 1; i < count; i++)
        {
            arr[0] -= arr[i];
        }
        
        display("IN.dat", fp);

    fclose(fp);


    fp = fopen("IN.dat", "w");

    if (arr[0] < 0){
        fprintf(fp, "%d ", 0);
    } else fprintf(fp, "%d ", arr[0]);

    for (int i = 1; i < count; i++)
    {
        fprintf(fp, "%d ", arr[i]);
    }
    
    fclose(fp);
    return 0;
}

void display(char source[], FILE *file){
    printf("display \"%s\"\n", source);
    char c;
    
    do
    {
        c = getc(file);
        if (c != EOF) putchar(c);
    } while (c != EOF);
    
    printf("\n\"%s\" is over\n", source);
    
}