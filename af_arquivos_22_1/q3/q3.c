// Leia o PDF ou MD antes de iniciar este exercício!
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Crie AQUI os handlers necessários
int status = 0;
void sigint_handler(int num) {
    status += 1;
    printf("08:15:03 ./q3 finished with signal sigint\n");
}

void sigterm_handler(int num) {
    status += 1;
    printf("08:15:03 ./q3 finished with signal sigterm\n");
}

int main(int argc, char *argv[]) {

    // Exiba o PID deste processo
    printf("PID deste processo: %d\n", getpid());

    FILE arquivo = open(*argv[1], "WR");

    if (arquivo) {
        write(arquivo, "08:15:03 ./q3 finished with signal sigint\n");
    } else {
        write("logfile.log", "08:15:03 ./q3 finished with signal sigint\n");
    }

    // Registre AQUI seu handler para os sinais!
    struct sigaction s;
    s.sa_handler = sigint_handler; 
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;
    sigaddset(&s.sa_mask, SIGTERM);

    sigaction(SIGINT, &s, NULL);

    struct sigaction s1;
    s1.sa_handler = sigterm_handler;
    sigemptyset(&s1.sa_mask);
    s1.sa_flags = 0;
    sigaddset(&s1.sa_mask, SIGINT);

    sigaction(SIGTERM, &s1, NULL);

    while(1); // roda infinitamente

    return 0;
}