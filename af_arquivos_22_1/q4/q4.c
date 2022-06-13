#include "macros_correcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int *extrai_primeiro_int(char *msg) {
    // Preencha aqui!
    char *lista[10];
    lista[0] = "0";
    lista[1] = "1";
    lista[2] = "2";
    lista[3] = "3";
    lista[4] = "4";
    lista[5] = "5";
    lista[6] = "6";
    lista[7] = "7";
    lista[8] = "8";
    lista[9] = "9";
    char *string[100];
    int indice = 0;
    int condicao = 1;
    int pegou_numero = 0;
    for (int i = 0; i < sizeof(msg); i++){
        for (int j = 0; j < 10; j++) {
            if (strcmp(msg[i], lista[j]) == 0 && condicao == 1){
                string[indice] = msg[i];
                indice++;
                pegou_numero == 1;
            }

            if (pegou_numero == 1 && strcmp(msg[i], " ") == 0) {
                condicao = 0;
            }
        }
    }
    int valor = atoi(string);
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
