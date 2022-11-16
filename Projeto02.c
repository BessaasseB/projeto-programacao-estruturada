#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "funcoes.h"

typedef struct endereco{

    char rua[20], cidade[20], estado[20], cep[8];

}endereco;

struct cadastro{

    int id;
    char nome[30], email[30], sexo[15], vax;
    double altura;
    bool vacina;
    endereco endereco;

};
struct cadastroBackup{

    int id;
    char nome[30], email[30], sexo[15], vax;
    double altura;
    bool vacina;
    endereco endereco;

};


int main(void)
{

    srand(time(NULL));

    int size, i, j, newSize = 0, excludeIndex;
    char menuOpt, emailSearch[30];
    int emailCheck, sexoCheck, alturaCheck;
    int userOpt;
    struct cadastro cadastro[1000];
    struct cadastroBackup cadastroBackup[1000];

        do{
            printf("Quantos usuarios serao inseridos?: ");
            scanf("%d", &size);

        } while (size < 1 || size > 1000);

        fflush(stdin);

        for(i=0; i<size; i++){

            emailCheck = 0;
            sexoCheck = 0;
            alturaCheck = 0;

            cadastro[i].id = rand() % 999+1;
            printf("Informe o nome do usuario ID-%d: ", cadastro[i].id);
            fgets(cadastro[i].nome, 30, stdin);
            fflush(stdin);

        while(emailCheck == 0){

                printf("Informe o email do usuario: ");
                fgets(cadastro[i].email, 30, stdin);
                fflush(stdin);

                emailCheck = checkEmail(cadastro[i].email);
                

                if(emailCheck == 0){
                        printf("!!O email informado e invalido!!\n");
                }
        };

                do{
                    printf("Informe o sexo do usuario: ");
                    fgets(cadastro[i].sexo, 15, stdin);
                    fflush(stdin);

                    sexoCheck = checkSexo(cadastro[i].sexo);

                    if(sexoCheck != 0){
                        printf("!!Sexo invalido, tente novamente!!\n");
                    }

                }while(sexoCheck != 0);


                printf("Informe o CEP do usuario: ");
                fgets(cadastro[i].endereco.cep, 8, stdin);
                fflush(stdin);
                printf("Informe o estado do usuario: ");
                fgets(cadastro[i].endereco.estado, 20, stdin);
                fflush(stdin);
                printf("Informe a cidade do usuario: ");
                fgets(cadastro[i].endereco.cidade, 20, stdin);
                fflush(stdin);
                printf("Informe a rua do usuario: ");
                fgets(cadastro[i].endereco.rua, 20, stdin);
                fflush(stdin);
                

                do{
                    printf("Informe a altura do usuario: ");
                    scanf("%lf", &cadastro[i].altura);
                    fflush(stdin);
                    
                    alturaCheck = checkAltura(cadastro[i].altura);

                    if(alturaCheck != 0){

                        printf("!!Altura informada invalida, informe valores entre 1m e 2m!!\n");
                    }

                }while(alturaCheck != 0);

                printf("O usuario esta vacinado?: ");
                scanf("%c", &cadastro[i].vax);

                switch(cadastro[i].vax){
                    case 's':
                        cadastro[i].vacina = true;
                        break;

                    case 'n':
                        cadastro[i].vacina = false;
                        break;
                }


                fflush(stdin);


                printf("\n");
            }

    int pos;

    do{

        system("cls");

        printf("-----CADASTRO CONCLUIDO-----\n");
        printf("-------MENU DE OPCOES-------\n");
        printf("[A] EXCLUIR UM USUARIO\n");
        printf("[B] BUSCAR UM USUARIO POR EMAIL\n");
        printf("[C] IMPRIMIR TODOS OS USUARIOS CADASTRADOS\n");
        printf("[D] BACKUP DOS USUARIOS CADASTRADOS\n");
        printf("[E] RESTAURACAO DOS DADOS\n");
        printf("[F] EDITAR UM USUARIO\n");
        printf("[G] ADICIONAR UM USUARIO\n");
        printf("[H] ENCERRAR PROGRAMA\n");
        scanf("%c", &menuOpt);
        fflush(stdin);

        switch(menuOpt){

        case 'a':

            printf("Qual usuario deseja deletar?:\n");
            for(i=0; i<(size+newSize); i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, cadastro[i].id, cadastro[i].nome);
            }
            scanf("%d", &pos);
            fflush(stdin);

            for(i=pos-1; i<size-1; i++){

                cadastro[i].id = cadastro[i+1].id;
                strcpy(cadastro[i].nome, cadastro[i+1].nome);
                strcpy(cadastro[i].email, cadastro[i+1].email);
                strcpy(cadastro[i].sexo, cadastro[i+1].sexo);
                strcpy(cadastro[i].endereco.cep, cadastro[i+1].endereco.cep);
                strcpy(cadastro[i].endereco.estado, cadastro[i+1].endereco.estado);
                strcpy(cadastro[i].endereco.cidade, cadastro[i+1].endereco.cidade);
                strcpy(cadastro[i].endereco.rua, cadastro[i+1].endereco.rua);
                cadastro[i].altura = cadastro[i+1].altura;
                cadastro[i].vacina = cadastro[i+1].vacina;
                
            }

            size--;

            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;


        case 'b':

            printf("Informe o email que deseja buscar: ");
            fgets(emailSearch, 30, stdin);

            for(i=0; i<(size+newSize); i++){
                if(strncmp(emailSearch, cadastro[i].email, 30) == 0){
                    break;
                }
            }

            printf("---USUARIOS CADASTRADOS---\n");
            printf("\n-----USUARIO %d-----\n", cadastro[i].id);
            printf("\nNome: %s", cadastro[i].nome);
            printf("Email: %s", cadastro[i].email);
            printf("Sexo: %s", cadastro[i].sexo);
            printf("Endereco: %s %s %s %s", cadastro[i].endereco.cep,
                                            cadastro[i].endereco.estado,
                                            cadastro[i].endereco.cidade,
                                            cadastro[i].endereco.rua);
            printf("Altura: %.2lf M\n", cadastro[i].altura);
            if(cadastro[i].vacina == true){
                printf("O usuario esta vacinado!\n");
            }
            else{
                printf("!!!O USUARIO NAO ESTA VACINADO!!!\n");
            }

            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;

        case 'c':

            for(i=0; i<(size + newSize); i++){

                printf("---USUARIOS CADASTRADOS---\n");
                printf("\n-----USUARIO %d-----\n", cadastro[i].id);
                printf("\nNome: %s", cadastro[i].nome);
                printf("Email: %s", cadastro[i].email);
                printf("Sexo: %s", cadastro[i].sexo);
                printf("Endereco: %s %s %s %s", cadastro[i].endereco.cep,
                                            cadastro[i].endereco.estado,
                                            cadastro[i].endereco.cidade,
                                            cadastro[i].endereco.rua);
                printf("Altura: %.2lf M\n", cadastro[i].altura);
                if(cadastro[i].vacina == true){
                    printf("O usuario esta vacinado!\n");
                }
                else{
                    printf("!!!O USUARIO NAO ESTA VACINADO!!!\n");
                }

            }
                printf("\nPressione ENTER para continuar!\n");
                getch();

            break;

        case 'd':

            for(i=0; i<(size+newSize); i++){

                cadastroBackup[i].id = cadastro[i].id;
                strcpy(cadastroBackup[i].nome, cadastro[i].nome);
                strcpy(cadastroBackup[i].email, cadastro[i].email);
                strcpy(cadastroBackup[i].sexo, cadastro[i].sexo);
                strcpy(cadastroBackup[i].endereco.cep, cadastro[i].endereco.cep);
                strcpy(cadastroBackup[i].endereco.estado, cadastro[i].endereco.estado);
                strcpy(cadastroBackup[i].endereco.cidade, cadastro[i].endereco.cidade);
                strcpy(cadastroBackup[i].endereco.rua, cadastro[i].endereco.rua);
                cadastroBackup[i].altura = cadastro[i].altura;
                cadastroBackup[i].vacina = cadastro[i].vacina;
            }

            printf("\n!!!BACKUP CONCLUIDO COM SUCESSO!!!\n");
            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;

        case 'e':

            printf("De qual usario deseja restaurar os dados?:\n");
            for(i=0; i<(size+newSize); i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, cadastro[i].id, cadastro[i].nome);
            }
            scanf("%d", &userOpt);
            fflush(stdin);

            cadastro[i].id = cadastroBackup[i].id;
            strcpy(cadastro[userOpt].nome, cadastroBackup[userOpt].nome);
            strcpy(cadastro[userOpt].email, cadastroBackup[userOpt].email);
            strcpy(cadastro[userOpt].sexo, cadastroBackup[userOpt].sexo);
            strcpy(cadastro[userOpt].endereco.cep, cadastroBackup[userOpt].endereco.cep);
            strcpy(cadastro[userOpt].endereco.estado, cadastroBackup[userOpt].endereco.estado);
            strcpy(cadastro[userOpt].endereco.cidade, cadastroBackup[userOpt].endereco.cidade);
            strcpy(cadastro[userOpt].endereco.rua, cadastroBackup[userOpt].endereco.rua);
            cadastro[userOpt].altura = cadastroBackup[userOpt].altura;
            cadastro[userOpt].vacina = cadastroBackup[userOpt].vacina;

            printf("\n!!!RESTAURACAO CONCLUIDO COM SUCESSO!!!\n");
            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;

        case 'f':
            emailCheck = 0;
            
            printf("Qual usuario deseja editar?:\n");
            for(i=0; i<(size+newSize); i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, cadastro[i].id, cadastro[i].nome);
            }
            scanf("%d", &userOpt);
            fflush(stdin);

            printf("Informe o nome do usuario ID-%d: ", cadastro[userOpt].id);
            fgets(cadastro[userOpt].nome, 30, stdin);
            fflush(stdin);


            while(emailCheck == 0){

                printf("Informe o email do usuario: ");
                fgets(cadastro[userOpt].email, 30, stdin);
                fflush(stdin);

                emailCheck = checkEmail(cadastro[userOpt].email);

                if(emailCheck == 0){
                        printf("!!O email informado e invalido!!\n");
                }
            };

                do{
                    printf("Informe o sexo do usuario: ");
                    fgets(cadastro[userOpt].sexo, 15, stdin);
                    fflush(stdin);

                    sexoCheck = checkSexo(cadastro[userOpt].sexo);

                    if(sexoCheck != 0){
                        printf("!!Sexo invalido, tente novamente!!\n");
                    }


                }while(sexoCheck != 0);

                printf("Informe o CEP do usuario: ");
                fgets(cadastro[userOpt].endereco.cep, 8, stdin);
                fflush(stdin);
                printf("Informe o estado do usuario: ");
                fgets(cadastro[userOpt].endereco.estado, 20, stdin);
                fflush(stdin);
                printf("Informe a cidade do usuario: ");
                fgets(cadastro[userOpt].endereco.cidade, 20, stdin);
                fflush(stdin);
                printf("Informe a rua do usuario: ");
                fgets(cadastro[userOpt].endereco.rua, 20, stdin);
                fflush(stdin);

                do{
                    printf("Informe a altura do usuario: ");
                    scanf("%lf", &cadastro[userOpt].altura);
                    fflush(stdin);

                    alturaCheck = checkAltura(cadastro[userOpt].altura);

                    if(alturaCheck != 0){

                        printf("!!Altura informada invalida, informe valores entre 1m e 2m!!\n");
                    }

                }while(alturaCheck != 0);

                printf("O usuario esta vacinado?: ");
                scanf("%c", &cadastro[userOpt].vax);

                switch(cadastro[userOpt].vax){
                    case 's':
                        cadastro[userOpt].vacina = true;
                        break;

                    case 'n':
                        cadastro[userOpt].vacina = false;
                        break;
                }

            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;


        case 'g':

            printf("Quantos usuarios novos deseja inserir?: ");
            scanf("%d", &newSize);
            fflush(stdin);

            for (i=size; i<(size+newSize); i++){
                emailCheck = 0;
                cadastro[i].id = rand() % 999+1;
                printf("Informe o nome do usuario ID-%d: ", cadastro[i].id);
                fgets(cadastro[i].nome, 30, stdin);
                fflush(stdin);


                while(emailCheck == 0){

                        printf("Informe o email do usuario: ");
                        fgets(cadastro[i].email, 30, stdin);
                        fflush(stdin);

                        emailCheck = checkEmail(cadastro[i].email);

                        if(emailCheck == 0){
                                printf("!!O email informado e invalido!!\n");
                        }
                };

                        do{
                            printf("Informe o sexo do usuario: ");
                            fgets(cadastro[i].sexo, 15, stdin);
                            fflush(stdin);

                            sexoCheck = checkSexo(cadastro[i].sexo);


                            if(sexoCheck != 0){
                                printf("!!Sexo invalido, tente novamente!!\n");
                            }


                        }while(sexoCheck != 0);

                        printf("Informe o CEP do usuario: ");
                        fgets(cadastro[userOpt].endereco.cep, 8, stdin);
                        fflush(stdin);
                        printf("Informe o estado do usuario: ");
                        fgets(cadastro[userOpt].endereco.estado, 20, stdin);
                        fflush(stdin);
                        printf("Informe a cidade do usuario: ");
                        fgets(cadastro[userOpt].endereco.cidade, 20, stdin);
                        fflush(stdin);
                        printf("Informe a rua do usuario: ");
                        fgets(cadastro[userOpt].endereco.rua, 20, stdin);
                        fflush(stdin);

                        do{
                            printf("Informe a altura do usuario: ");
                            scanf("%lf", &cadastro[i].altura);
                            fflush(stdin);
                            
                            alturaCheck = checkAltura(cadastro[i].altura);

                            if(alturaCheck != 0){

                                printf("!!Altura informada invalida, informe valores entre 1m e 2m!!\n");
                            }

                        }while(alturaCheck != 0);

                        printf("O usuario esta vacinado?: ");
                        scanf("%c", &cadastro[i].vax);

                        switch(cadastro[i].vax){
                            case 's':
                                cadastro[i].vacina = true;
                                break;

                            case 'n':
                                cadastro[i].vacina = false;
                                break;
                        }

                        fflush(stdin);

                        printf("\n");
                    }

            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;


        case 'h':
            printf("\n!!!PROGRAMA ENCERRADO!!!\n");
            break;
        }

    }while(menuOpt != 'h');

    return 0;
}
