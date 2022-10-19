#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    
    int size;

    do
    {
        printf("Quantos usuários serão inseridos?: ");
        scanf("%d", &size);

    } while (size < 1 || size > 1000);
    
        

    int id[size];
    char nome[30], email[30], sexo[15], endereco[50];
    double altura;
    bool vacina;

    

    return 0;
}
