#include <stdio.h>

void newFile(FILE *file, char source[]);

int main(void){
    FILE *file1,
        *file2;
    newFile(file1, "IN.txt");
    newFile(file2, "IN.dat");
    return 0;

}

void newFile(FILE *file, char source[]){
    file = fopen(source, "w");
    fclose(file);
    int n;
    file = fopen(source, "a");
    
    do
    {
        printf("Enter count of values for \"%s\": ", source);
        scanf("%d", &n);
    } while (n <= 1);

    puts("Thanks");

    printf("Enter values for \"%s\":\n", source);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        fprintf(file, "%d ", temp);
    }

    fclose(file);

}