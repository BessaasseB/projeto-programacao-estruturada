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

int main(void)
{
    
    int size, i;

    do
    {
        printf("Quantos usuarios serao inseridos?: ");
        scanf("%d", &size);

    } while (size < 1 || size > 1000);
    
        

    int id[size][1];
    char nome[size][30], email[size][30], sexo[size][15], endereco[size][50];
    double altura[size][1];
    bool vacina[size][5];

    for(i=0; i<size; i++){
        printf("Teste\n");
    }

    

    return 0;
}
