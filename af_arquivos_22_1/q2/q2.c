// Leia o PDF ou MD antes de iniciar este exercício!

// inclua libs aqui!
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){

    // SUA RESPOSTA AQUI
    int status;
    pid_t filho;
    int passou_filho = 0;
    int loop = 1;
    int verify;

    while (loop) {
        filho = fork();

        if (filho == 0) {
            printf("%s\n",argv[1]);
            char *args[] = {argv[1], NULL};
            verify = execvp("verify", args);
            printf("Acabei filho\n");
            passou_filho = 1;
            loop = 0;
        } else {
            sleep(2);
            if (passou_filho){
                printf("VERIFY RETORNOU %d\n", verify);
            } else {
                printf("PANE NO SISTEMA VERIFY...\n");
            }
        }
    }
    

    return 0;
}