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
Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Não declarar CHECK
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



    int id[size], emailCheck = 0, sexoCheck;
    char nome[size][30], email[size][30], sexo[size][15], endereco[size][50], vax[size];
	char mascL[10] = {'m', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'},
		 mascU[10] = {'M', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'},
		 femL[9] = {'f', 'e', 'm', 'i', 'n', 'i', 'n', 'o', '\0'},
		 femU[9] = {'F', 'e', 'm', 'i', 'n', 'i', 'n', 'o', '\0'},
		 ndL[13] = {'n', 'a', 'o', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 'r', '\0'},
		 ndU[13] = {'N', 'a', 'o', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 'r', '\0'};
    double altura[size];
    bool vacina[size];


    fflush(stdin);

    for(i=0; i<size; i++){

        id[i] = rand() % 999+1;
        printf("Informe o nome do usuario ID-%d: ", id[i]);
        fgets(nome[i], 30, stdin);

        while(emailCheck == 0){

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

        };

		do{
			printf("Informe o sexo do usuario: ");
	        fgets(sexo[i], 15, stdin);
	        
	        if(strncmp(sexo[i], mascL, 1) == 0){
	        	sexoCheck = strcmp(mascL, sexo[i]);
			}
			else if(strncmp(sexo[i], mascU, 1) == 0){
	        	sexoCheck = strcmp(mascL, sexo[i]);
			}
			else if(strncmp(sexo[i], femL, 1) == 0){
	        	sexoCheck = strcmp(femL, sexo[i]);
			}
			else if(strncmp(sexo[i], femU, 1) == 0){
	        	sexoCheck = strcmp(femU, sexo[i]);
			}
			else if(strncmp(sexo[i], ndL, 1) == 0){
	        	sexoCheck = strcmp(ndL, sexo[i]);
			}
			else if(strncmp(sexo[i], ndU, 1) == 0){
	        	sexoCheck = strcmp(ndU, sexo[i]);
			}
	        
	        
		}while(sexoCheck != -1);
	        


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
