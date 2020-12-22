

// **********************************************************************
#include <stdio.h>
#include <ctype.h>
#define MAXLEN 20

void display(char source[], FILE *file);

int main(void){

    FILE *fp = fopen("IN.dat", "r");

    // проверка на существование исходного файла
    if(fp == NULL){
        fclose(fp);
        printf("Sorry, file don`t find\n");
        return 2;
    } else{
        fclose(fp);
        display("IN.dat", fp);
    }
        fp = fopen("IN.dat", "r");
        char c = 'a';
        int temp = 0;
        int count = 0;
        int arr[MAXLEN];
        int i = 0;

        do
        {
            c = getc(fp);

            // проверка на корректность введенных в исходный файл данных
            if(!(isdigit(c)) && (c != ' ') && (c != EOF)){
                fp = fopen("IN.dat", "w"); 
                fprintf(fp, "Sorry, file is incorrect\n");
                fclose(fp);
                display("IN.dat", fp);
                return 2;
            }

            // проверка является ли с числовым данным
            if(isdigit(c)){
                // преобразуем в целочисленный тип данных
                temp = temp * 10 + (c - 48);
            } else{
                
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


        fclose(fp);



    fp = fopen("IN.dat", "w");

    if (arr[0] < 0){
        fprintf(fp, "%d ", 0);
    } else {
        for (int i = 0; i < count; i++)
        {
            fprintf(fp ,"%d ", arr[i]);
        }
        
    }

    
    fclose(fp);
    display("IN.dat", fp);

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