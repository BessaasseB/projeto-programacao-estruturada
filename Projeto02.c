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


int main(void)
{

    srand(time(NULL));

    int size, i, j, newSize = 0, excludeIndex;
    char menuOpt, emailSearch[30];
    int emailCheck = 0, sexoCheck, alturaCheck;
    double alturaBkup[1000];
    bool vacinaBkup[1000];
    char nomeBkup[1000][30], emailBkup[1000][30], sexoBkup[1000][15], enderecoBkup[1000][50];
    int  idBkup[1000], userOpt;
    struct cadastro cadastro[1000];

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
/*
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

            printf("Qual usuario deseja editar?:\n");
            for(i=0; i<(size+newSize); i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, id[i], nome[i]);
            }
            scanf("%d", &pos);
            fflush(stdin);

            for(i=pos-1; i<size-1; i++){

                id[i] = id[i+1];
                strcpy(nome[i], nome[i+1]);
                strcpy(email[i], email[i+1]);
                strcpy(sexo[i], sexo[i+1]);
                strcpy(endereco[i], endereco[i+1]);
                altura[i] = altura[i+1];
                vacina[i] = vacina[i+1];
                
            }

            size--;

            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;


        case 'b':

            printf("Informe o email que deseja buscar: ");
            fgets(emailSearch, 30, stdin);

            for(i=0; i<(size+newSize); i++){
                if(strncmp(emailSearch, email[i], 30) == 0){
                    break;
                }
            }

            printf("---USUARIOS CADASTRADOS---\n");
            printf("\n-----USUARIO %d-----\n", id[i]);
            printf("\nNome: %s", nome[i]);
            printf("Email: %s", email[i]);
            printf("Sexo: %s", sexo[i]);
            printf("Endereco: %s", endereco[i]);
            printf("Altura: %.2lf M\n", altura[i]);
            if(vacina[i] == true){
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
                printf("\n-----USUARIO %d-----\n", id[i]);
                printf("\nNome: %s", nome[i]);
                printf("Email: %s", email[i]);
                printf("Sexo: %s", sexo[i]);
                printf("Endereco: %s", endereco[i]);
                printf("Altura: %.2lf M\n", altura[i]);
                if(vacina[i] == true){
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

                strcpy(idBkup, id);
                strcpy(nomeBkup, nome);
                strcpy(emailBkup, email);
                strcpy(sexoBkup, sexo);
                strcpy(enderecoBkup, endereco);
                strcpy(alturaBkup, altura);
                strcpy(vacinaBkup, vacina);
            }

            printf("\n!!!BACKUP CONCLUIDO COM SUCESSO!!!\n");
            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;

        case 'e':

            printf("De qual usario deseja restaurar os dados?:\n");
            for(i=0; i<(size+newSize); i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, id[i], nome[i]);
            }
            scanf("%d", &userOpt);
            fflush(stdin);

            strcpy(nome[userOpt], nomeBkup[userOpt]);
            strcpy(email[userOpt], emailBkup[userOpt]);
            strcpy(sexo[userOpt], sexoBkup[userOpt]);
            strcpy(endereco[userOpt], enderecoBkup[userOpt]);
            altura[userOpt] = alturaBkup[userOpt];
            vacina[userOpt] = vacinaBkup[userOpt];

            printf("\n!!!RESTAURACAO CONCLUIDO COM SUCESSO!!!\n");
            printf("\nPressione ENTER para continuar!\n");
            getch();

            break;

        case 'f':
            emailCheck = 0;
            
            printf("Qual usuario deseja editar?:\n");
            for(i=0; i<(size+newSize); i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, id[i], nome[i]);
            }
            scanf("%d", &userOpt);
            fflush(stdin);

            printf("Informe o nome do usuario ID-%d: ", id[userOpt]);
            fgets(nome[userOpt], 30, stdin);
            fflush(stdin);


            while(emailCheck == 0){

                printf("Informe o email do usuario: ");
                fgets(email[userOpt], 30, stdin);
                fflush(stdin);

                for(j=0;email[userOpt][j] != '\0';j++){

                    if(email[userOpt][j] == 64){
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
                    fgets(sexo[userOpt], 15, stdin);
                    fflush(stdin);

                    if(strncmp(sexo[userOpt], mascL, 1) == 0){
                        sexoCheck = strncmp(sexo[userOpt], mascL, 9);
                    }
                    if(strncmp(sexo[userOpt], mascU, 1) == 0){
                        sexoCheck = strncmp(sexo[userOpt], mascU, 9);
                    }
                    if(strncmp(sexo[userOpt], femL, 1) == 0){
                        sexoCheck = strncmp(sexo[userOpt], femL, 8);
                    }
                    if(strncmp(sexo[userOpt], femU, 1) == 0){
                        sexoCheck = strncmp(sexo[userOpt], femU, 8);
                    }
                    if(strncmp(sexo[userOpt], ndL, 1) == 0){
                        sexoCheck = strncmp(sexo[userOpt], ndL, 12);
                    }
                    if(strncmp(sexo[userOpt], ndU, 1) == 0){
                        sexoCheck = strncmp(sexo[userOpt], ndU, 12);
                    }


                    if(sexoCheck != 0){
                        printf("!!Sexo invalido, tente novamente!!\n");
                    }


                }while(sexoCheck != 0);

                printf("Informe o endereco do usuario: ");
                fgets(endereco[userOpt], 30, stdin);
                fflush(stdin);

                do{
                    printf("Informe a altura do usuario: ");
                    scanf("%lf", &altura[userOpt]);
                    fflush(stdin);

                    if(altura[userOpt] < 1 || altura[userOpt] > 2){

                        printf("!!Altura informada invalida, informe valores entre 1m e 2m!!\n");
                    }

                }while(altura[userOpt] < 1 || altura[userOpt] > 2);

                printf("O usuario esta vacinado?: ");
                scanf("%c", &vax[userOpt]);

                switch(vax[userOpt]){
                    case 's':
                        vacina[userOpt] = true;
                        break;

                    case 'n':
                        vacina[userOpt] = false;
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
                id[i] = rand() % 999+1;
                printf("Informe o nome do usuario ID-%d: ", id[i]);
                fgets(nome[i], 30, stdin);
                fflush(stdin);


                while(emailCheck == 0){

                        printf("Informe o email do usuario: ");
                        fgets(email[i], 30, stdin);
                        fflush(stdin);

                        for(j=0;email[i][j] != '\0';j++){

                            if(email[i][j] == 64){
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
                            fflush(stdin);

                            if(strncmp(sexo[i], mascL, 1) == 0){
                                sexoCheck = strncmp(sexo[i], mascL, 9);
                            }
                            if(strncmp(sexo[i], mascU, 1) == 0){
                                sexoCheck = strncmp(sexo[i], mascU, 9);
                            }
                            if(strncmp(sexo[i], femL, 1) == 0){
                                sexoCheck = strncmp(sexo[i], femL, 8);
                            }
                            if(strncmp(sexo[i], femU, 1) == 0){
                                sexoCheck = strncmp(sexo[i], femU, 8);
                            }
                            if(strncmp(sexo[i], ndL, 1) == 0){
                                sexoCheck = strncmp(sexo[i], ndL, 12);
                            }
                            if(strncmp(sexo[i], ndU, 1) == 0){
                                sexoCheck = strncmp(sexo[i], ndU, 12);
                            }


                            if(sexoCheck != 0){
                                printf("!!Sexo invalido, tente novamente!!\n");
                            }


                        }while(sexoCheck != 0);

                        printf("Informe o endereco do usuario: ");
                        fgets(endereco[i], 30, stdin);
                        fflush(stdin);

                        do{
                            printf("Informe a altura do usuario: ");
                            scanf("%lf", &altura[i]);
                            fflush(stdin);

                            if(altura[i] < 1 || altura[i] > 2){

                                printf("!!Altura informada invalida, informe valores entre 1m e 2m!!\n");
                            }

                        }while(altura[i] < 1 || altura[i] > 2);

                        printf("O usuario esta vacinado?: ");
                        scanf("%c", &vax[i]);

                        switch(vax[i]){
                            case 's':
                                vacina[i] = true;
                                break;

                            case 'n':
                                vacina[i] = false;
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
*/
    return 0;
}
