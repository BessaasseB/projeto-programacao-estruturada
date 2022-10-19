#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main(void)
{
    
    setlocale(LC_ALL, "Portuguese");

    int size;

    do
    {
        printf("Quantos usuários serão inseridos?: ");
        scanf("%d", &size);

    } while (size < 1 || size > 1000);
    
        

    int id[size];
    char nome[size], email[size], sexo[size], endereco[size];
    double altura;
    bool vacina;


    return 0;
}
