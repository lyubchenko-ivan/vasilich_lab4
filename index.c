#include <stdio.h>
#include <string.h>
#include <ctype.h>

// void newFile(FILE * file, char mode[], char name[]);
void display(char source[], FILE *file);


int main(void){
    FILE *file1;
    FILE *file2;

    int countLatinLet = 0;
    file1 = fopen("IN.txt", "r");
    file2 = fopen("OUT.txt", "w");
    
    if (file1 == NULL){
        fprintf(file2, "Sorry, we don`t find yours file :-(");
        fclose(file2);
        display("OUT.txt", file2);
        return 1;
    }else{
        fclose(file1);
        display("IN.txt", file1);
    }

    file1 = fopen("IN.txt", "r");
    char c;
    while (( c = fgetc(file1)) != EOF){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            countLatinLet++;
        }
    }
    
    fprintf(file2, "Answer: %d", countLatinLet);

    fclose(file1);
    fclose(file2);

    display("OUT.txt", file2);


    printf("Let`s do a second part\n");


    file1 = fopen("f", "r");
    file2 = fopen("newf", "w");
    

    if (file1 == NULL){
        fprintf(file2, "Sorry, we don`t find yours file :-(");
        fclose(file2);
        display("newf", file2);
        return 1;
    }else{
        fclose(file1);
        display("f", file1);
        file1 = fopen("f", "r");
    }
    c = ' ';
    while (( c = fgetc(file1)) != EOF){
        if(c >= 'A' && c <= 'Z'){
            fprintf(file2, "%c", tolower(c));
        } else{
            fprintf(file2, "%c", c);
        }
    }
    fclose(file1);
    fclose(file2);

    display("newf", file2);


}


void display(char source[], FILE *file){
    file = fopen(source, "r");
    printf("display \"%s\"\n", source);
    char c;
    
    do
    {
        c = getc(file);
        if (c != EOF) putchar(c);
    } while (c != EOF);
    
    printf("\n\"%s\" is over\n", source);
    fclose(file);
}