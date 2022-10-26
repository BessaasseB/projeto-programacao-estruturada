/*Utilizando os conceitos de vetor, implemente um algoritmo que:

inclua até 1000 usuários;
edite um usuário;
exclua um usuário;
busque um usuário pelo email;
imprima todos os usuários cadastrados;
faça backup dos usuários cadastrados;
faça restauração dos dados;
Dados do usuário:

Id (int) => preenchido automaticamente por números randômicos CHECK
Nome completo (string) CHECK
Email (string) => validação do campo: verificar se o caractere "@" aparece CHECK
Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Não declarar
Endereço (string) CHECK
Altura (double) => validação do campo: aceitar valores entre 1 e 2 m. CHECK
Vacina (tomou a vacina? boolean)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void)
{

    srand(time(NULL));

    int size, i, j, check = 0;

    do
    {
        printf("Quantos usuarios serao inseridos?: ");
        scanf("%d", &size);

    } while (size < 1 || size > 1000);



    int id[size], emailCheck = 0, sexoCheck = 0;
    char nome[size][30], email[size][30], sexo[size][15], endereco[size][50], vax[size];
    double altura[size];
    bool vacina[size];

    fflush(stdin);

    for(i=0; i<size; i++){

        id[i] = rand() % 999+1;

        printf("Informe o nome do usuario ID-%d: ", id[i]);
        fgets(nome[i], 30, stdin);

        printf("Informe o email do usuario: ");
        fgets(email[i], 30, stdin);

        do{

            printf("Informe o email do usuario: ");
            fgets(email[i], 30, stdin);

            for(j=0;email[i][j] != '\0';j++){

                if(email[i][j] == '@'){
                    emailCheck = 1;
                    break;
                }

            }
            if(emailCheck == 0){
                    printf("!!O email informado e invalido!!\n");
            }

        }while(emailCheck == 0);

        printf("Informe o sexo do usuario: ");
        scanf("%[^\n]", sexo[i]);

        printf("Informe o endereco do usuario: ");
        fgets(endereco[i], 30, stdin);

        do{
            printf("Informe a altura do usuario: ");
            scanf("%lf", &altura[i]);

            if(altura[i] < 1 || altura[i] > 2){

                printf("!!Altura informada invalida, informe valores entre 1m e 2m!!\n");
            }

        }while(altura[i] < 1 || altura[i] > 2);


        fflush(stdin);

        printf("O usuario esta vacinado?: ");
        scanf("%c", &vax[i]);

        fflush(stdin);

        printf("\n");
    }

    printf("\n");

    for(i=0; i<size; i++){

        printf("-----USUARIO %d-----\n", id[i]);
        printf("\nNome: %s", nome[i]);
        printf("Email: %s", email[i]);
        printf("Sexo: %s", sexo[i]);
        printf("Endereco: %s", endereco[i]);
        printf("Altura: %.2lf\n", altura[i]);
        printf("Esta vacinado?: %c", vax[i]);

        printf("\n");
    }


    return 0;
}
