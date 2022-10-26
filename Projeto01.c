/*Utilizando os conceitos de vetor, implemente um algoritmo que:

inclua até 1000 usuários;
edite um usuário;
exclua um usuário;
busque um usuário pelo email;
imprima todos os usuários cadastrados;
faça backup dos usuários cadastrados;
faça restauração dos dados;
Dados do usuário:

Id (int) => preenchido automaticamente por números randômicos
Nome completo (string)
Email (string) => validação do campo: verificar se o caractere "@" aparece
Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Não declarar
Endereço (string)
Altura (double) => validação do campo: aceitar valores entre 1 e 2 m.
Vacina (tomou a vacina? boolean)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void)
{
    
    srand(time(NULL));

    int size, i, j=0, check = 0;

    do
    {
        printf("Quantos usuarios serao inseridos?: ");
        scanf("%d", &size);

    } while (size < 1 || size > 1000);
    
        

    int id[size][1];
    char nome[size][30], email[size][30], sexo[size][15], endereco[size][50], vax;
    double altura[size][1];
    bool vacina[size][5];

    fflush(stdin);

    for(i=0; i<size; i++){

        id[i][i] = rand() % 999+1; 

        printf("Informe o nome do usuario ID-%d: ", id[i][i]);
        fgets(nome[i], 30, stdin);
   
        printf("Informe o email do usuario: ");
        fgets(email[i], 30, stdin);
 

        printf("Informe o sexo do usuario: ");
        fgets(sexo[i], 30, stdin);

        printf("Informe o endereco do usuario: ");
        fgets(endereco[i], 30, stdin);

        printf("Informe a altura do usuario: ");
        scanf("%f", &altura);

        fflush(stdin);

        printf("O usuario esta vacinado?: ");
        scanf("%c", &vax);

        fflush(stdin);
        
        printf("\n");
    }

    printf("\n");

    for(i=0; i<size; i++){
        printf("%s", nome[i]); 
        printf("%s", email[i]);
        printf("%s", sexo[i]);
        printf("%s", endereco[i]);  

        printf("\n");
    }

    
    return 0;
}
