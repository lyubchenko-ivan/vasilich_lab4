#include <stdio.h>
#include <locale.h>

int newFile(FILE *file, char source[]);

int main(void){
    setlocale(LC_ALL,"ru");
    FILE *file1, *file2;
    puts("Привет, эта программа запишет нам два файла для дальнейшей работы с ними.");
    puts("Твоя задача заключается лишь в том, чтобы ввести значения в терминал");
    puts("Обо все другом позаботиться наш исполнитель, пожелай ему удачи");
    newFile(file1, "IN.txt");
    newFile(file2, "f");
    return 0;

}

int newFile(FILE *file, char source[]){
    file = fopen(source, "w+");

    char c;
    printf("Начинай вводить данные для файла \"%s\":", source);
    while ((c = getchar()) != '\n'){
        fputc(c, file);
    }


    puts("Благодарочку лови");

    fclose(file);
    return 0;
}