#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <strings.h>

#define MAX_M 1024
#define MAX_BUFF 1024
#define n 17

void produz(char *str){

    fgets(str, MAX_M, stdin);
}

int conta_espaco(char *str, int m)
{
    int i, conta=0;

    for(i=0; i< m; i++){
        if(str[i]==' ')
            conta++;
    }
    return conta;
}

int formata(char *str, int m){
    char aux_str[MAX_M];
    int i, j = 0, aux = 0, a = 0;
    int respaco, ainserir, restoain;

    if(m <= n){
        return ;
    }
    else if(m > n){
        for(i = n; str[i] != ' '; i--);
        respaco = conta_espaco(str, i);
        ainserir = n - i;
        if(respaco > 0){
            if(ainserir%respaco == 0){
                ainserir = ainserir/respaco;
            }
            else if(ainserir%respaco != 0){
                restoain = ainserir%respaco;
                ainserir = ainserir/respaco;
            }

            while(aux < i ){
                aux_str[j] = str[aux];
                j++;
                aux++;
                if(str[aux] == ' '){
                    for(a = 0; a < ainserir;  a++){
                        aux_str[j] = ' ';
                        j++;
                    }
                    if(restoain > 0){
                        aux_str[j] = ' ';
                        restoain--;
                        j++;
                    }
                }
            }
            aux_str[j] = '\n';
            j++;
            aux_str[j] = '\0';
        }
    }
    return i;
}

void main(){
    char *str;
    str = (char *)calloc(MAX_M, sizeof(char));
    char buffer[MAX_BUFF];
    int m, espacos, mn, aux, a;

    produz(str);
    m = strlen(str) - 1;
    espacos = conta_espaco(str, m);

    mn =((m%n)==0) ? m/n : (m/n)+1 ;

     do{
        a = 0;
        printf("%s\n%d\nespaços = %d\n", str, m, espacos);
        aux = formata(str, m);
        aux++;
        while(a < aux){
            str++;
            a++;
        }
    }while(strlen(str) > n);
    printf("%s\n%d\nespaços = %d\n", str, m, espacos);
}
