/*Utilizando os conceitos de vetor, implemente um algoritmo que:

inclua até 1000 usuários; CHECK;
edite um usuário; CHECK;
exclua um usuário;
busque um usuário pelo email; CHECK
imprima todos os usuários cadastrados; CHECK;
faça backup dos usuários cadastrados; CHECK;
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

    int size, i, j, check = 0, newSize;
    char menuOpt, emailSearch[30];
    int emailCheck = 0, sexoCheck;
    char mascL[10] = {'m', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'},
            mascU[10] = {'M', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'},
            femL[9] = {'f', 'e', 'm', 'i', 'n', 'i', 'n', 'o', '\0'},
            femU[9] = {'F', 'e', 'm', 'i', 'n', 'i', 'n', 'o', '\0'},
            ndL[13] = {'n', 'a', 'o', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 'r', '\0'},
            ndU[13] = {'N', 'a', 'o', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 'r', '\0'};
    double altura[size], alturaBkup[size];
    bool vacina[size], vacinaBkup[size];



        do{
            printf("Quantos usuarios serao inseridos?: ");
            scanf("%d", &size);

        } while (size < 1 || size > 1000);

        fflush(stdin);

        char nome[size][30], nomeBkup[size][30], email[size][30], emailBkup[size][30], sexo[size][15], sexoBkup[size][15], endereco[size][50], enderecoBkup[size][50], vax[size];
        int id[size], idBkup[size], userOpt;

        for(i=0; i<size; i++){

            emailCheck = 0;
            sexoCheck = 0;

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

                    printf("%d", sexoCheck);

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
        printf("[G] ENCERRAR PROGRAMA\n");
        scanf("%c", &menuOpt);
        fflush(stdin);

        switch(menuOpt){

        case 'a':

            printf("Qual usuario deseja excluir?:\n");
            for(i=0; i<size; i++){
                printf("\nNumero: %d -- ID: %d -- Nome: %s",i, id[i], nome[i]);
            }
            scanf("%d", &userOpt);
            fflush(stdin);

            break;

        case 'b':

            printf("Informe o email que deseja buscar: ");
            fgets(emailSearch, 30, stdin);

            for(i=0; i<size; i++){
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

            for(i=0; i<size; i++){

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

            for(i=0; i<size; i++){

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
            for(i=0; i<size; i++){
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
            for(i=0; i<size; i++){
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

                    printf("%d", sexoCheck);

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
            printf("\n!!!PROGRAMA ENCERRADO!!!\n");
            break;
        }

    }while(menuOpt != 'g');


    return 0;
}
