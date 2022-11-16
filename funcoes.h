#include <stdio.h>
#include <string.h>

int checkEmail(char email[]){

    int i;

    for(i = 0; i < 30; i++){
        if(email[i] == 64){
            return 1;
        }
    }
}

int checkSexo(char sexo[]){

    int i;
    char mascL[10] = {'m', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'},
            mascU[10] = {'M', 'a', 's', 'c', 'u', 'l', 'i', 'n', 'o', '\0'},
            femL[9] = {'f', 'e', 'm', 'i', 'n', 'i', 'n', 'o', '\0'},
            femU[9] = {'F', 'e', 'm', 'i', 'n', 'i', 'n', 'o', '\0'},
            ndL[13] = {'n', 'a', 'o', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 'r', '\0'},
            ndU[13] = {'N', 'a', 'o', ' ', 'd', 'e', 'c', 'l', 'a', 'r', 'a', 'r', '\0'};

    
    if(strncmp(sexo, mascL, 9) == 0 || 
    strncmp(sexo, mascU, 9) == 0 || 
    strncmp(sexo, femL, 8) == 0 || 
    strncmp(sexo, femL, 8) == 0 || 
    strncmp(sexo, ndL, 12) == 0 || 
    strncmp(sexo, ndU, 12) == 0){
        return 0;
    }

    else{
        return 1;
    }
}

int checkAltura(int h){

    if(h < 1 || h > 2){
        return 1;
    }
    else{
        return 0;
    }

}