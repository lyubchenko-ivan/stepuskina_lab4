#include <stdio.h> // библиотека для вывода на экран
#include <string.h>
#include <ctype.h>


#define MAXLEN 20


void display(char source[], FILE *file);


int main(){
    // переменная , хранящая ссылку на файл
    FILE *fp;
    // FILE *fp2;

    fp=fopen("IN.txt", "r+"); 
    // fp2 = fopen("OUT.txt", "w");
        
        // проверка на существование исходного файла
        if (fp == NULL){
            printf("Sorry, we don`t find yours file :-(\n");
            return 1;
        }else{
            fclose(fp);
            display("IN.txt", fp);
        }

        fp = fopen("IN.txt", "a+");

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
                fclose(fp);
                fp = fopen("IN.txt", "w");
                fprintf(fp, "Sorry, file is incorrect\n");
                fclose(fp);
                display("IN.txt", fp);
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
        fprintf(fp, " %d", oddCount);
        fclose(fp);

        display("IN.txt", fp);
        
    return 0;
}

void display(char source[], FILE *file){
    file = fopen(source, "r");
    printf("display \"%s\"\n", source);
    char c;
    
    while((c = fgetc(file)) != EOF){
        putchar(c);
    }
    
    printf("\n\"%s\" is over\n", source);
    fclose(file);
}