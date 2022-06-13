#include "macros_correcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *extrai_primeiro_int(char *msg) {
    // Preencha aqui!
    int lista[10];
    lista[0] = 48;
    lista[1] = 49;
    lista[2] = 50;
    lista[3] = 51;
    lista[4] = 52;
    lista[5] = 53;
    lista[6] = 54;
    lista[7] = 55;
    lista[8] = 56;
    lista[9] = 57;
    char *string[100];
    char *string_teste[1];
    int indice = 0;
    int condicao = 1;
    int pegou_numero = 0;
    for (int i = 0; i < sizeof(long)*sizeof(msg); i++){
        printf("ascii: %d\n",msg[i]);
        string_teste[0] = msg[i];
        printf("letra:%s\n",string_teste);

        for (int j = 0; j < 10; j++) {
            if (msg[i] == lista[j] && condicao == 1){
                string[indice] = msg[i];
                indice++;
                pegou_numero == 1;
            }

            if (pegou_numero == 1) {
                if (msg[i] > 70) {
                    printf("numero2:%d",msg[i]);
                    condicao = 0;
                }
            }

        }
    }
    int valor = atoi(string);
    printf("%d\n",valor);
    return valor; // Você pode alterar o retorno, se necessário!
}


// Não edite a main, caso contrário zerará a questão
int main() {

    {
        char *msg = "comprei 10 crypto siscoin hoje";
        int correto = 10;
        int *primeiro_int_user = NULL;
        primeiro_int_user = extrai_primeiro_int(msg);

        printf("Testes: %s\n", msg);
        assertExpr(primeiro_int_user != NULL, "ERRO: Primeiro é NULL!");
        if (primeiro_int_user != NULL) {
            assertExpr(*primeiro_int_user == correto, "Primeiro Int tem valor incorreto!");
            free(primeiro_int_user);
        } else {
            assertExpr(primeiro_int_user != NULL, "ERRO: Devido a ser nulo um dos testes não pode ser executado!");
        }
    }

    {
        char *msg = "(-_-)___/ R$ 71,99";
        int correto = 71;
        int *primeiro_int_user = NULL;
        primeiro_int_user = extrai_primeiro_int(msg);

        printf("Testes: %s\n", msg);
        assertExpr(primeiro_int_user != NULL, "ERRO: Primeiro é NULL!");
        if (primeiro_int_user != NULL) {
            assertExpr(*primeiro_int_user == correto, "Primeiro Int tem valor incorreto!");
            free(primeiro_int_user);
        } else {
            assertExpr(primeiro_int_user != NULL, "ERRO: Devido a ser nulo um dos testes não pode ser executado!");
        }
    }

    {
        char *msg = "Nascido em 1987, junqueira sempre soube o que fazer da vida!";
        int correto = 1987;
        int *primeiro_int_user = NULL;
        primeiro_int_user = extrai_primeiro_int(msg);

        printf("Testes: %s\n", msg);
        assertExpr(primeiro_int_user != NULL, "ERRO: Primeiro é NULL!");
        if (primeiro_int_user != NULL) {
            assertExpr(*primeiro_int_user == correto, "Primeiro Int tem valor incorreto!");
            free(primeiro_int_user);
        } else {
            assertExpr(primeiro_int_user != NULL, "ERRO: Devido a ser nulo um dos testes não pode ser executado!");
        }
    }

    {
        char *msg = "Na verdade foi em 1983, não 1987!";
        int correto = 1983;
        int *primeiro_int_user = NULL;
        primeiro_int_user = extrai_primeiro_int(msg);

        printf("Testes: %s\n", msg);
        assertExpr(primeiro_int_user != NULL, "ERRO: Primeiro é NULL!");
        if (primeiro_int_user != NULL) {
            assertExpr(*primeiro_int_user == correto, "Primeiro Int tem valor incorreto!");
            free(primeiro_int_user);
        } else {
            assertExpr(primeiro_int_user != NULL, "ERRO: Devido a ser nulo um dos testes não pode ser executado!");
        }
    }

    {
        char *msg = "É, o final do semestre está chegando!";
        int *primeiro_int_user = extrai_primeiro_int(msg);

        printf("Testes: %s\n", msg);
        assertExpr(primeiro_int_user == NULL, "ERRO: nenhum número deveria ter sido retornado!");
    }

    printSummary;
}
