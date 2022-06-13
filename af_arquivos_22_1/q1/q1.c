// Leia o README antes de iniciar este exercício!


// inclua as bibliotecas necessárias
// #include ...
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

typedef struct {
    sem_t *s1, *s2, *s3, *s4;
} t_arg;

void *thread1(void *_arg) {
    t_arg *arg = _arg;

    printf("A\n"); 
    sem_wait(arg->s4);    
    printf("C\n");
    sem_post(arg->s1);

    return NULL;
}

void *thread2(void *_arg) {
    t_arg *arg = _arg;

    sem_wait(arg->s1); 
    printf("D\n");
    sem_post(arg->s2);

    return NULL;
}

void *thread3(void *_arg) {
    t_arg *arg = _arg;

    sem_wait(arg->s2);
    printf("E\n");

    printf("F\n");
    sem_post(arg->s3);

    return NULL;
}

void *thread4(void *_arg) {
    t_arg *arg = _arg;

    printf("B\n");
    sem_post(arg->s4);
    sem_wait(arg->s3); 
    printf("G\n");

    return NULL;
}

int main(int argc, char *argv[]) {

    // Crie TODAS as threads em um laço. Voce deve utilizar semaforos para sincronizacao.
    pthread_t *tids = malloc(sizeof(pthread_t) * 4);

    t_arg *arg = malloc(sizeof(t_arg));
    
    sem_t *s1 = malloc(sizeof(sem_t));
    sem_t *s2 = malloc(sizeof(sem_t));
    sem_t *s3 = malloc(sizeof(sem_t));
    sem_t *s4 = malloc(sizeof(sem_t));

    sem_init(s1, 0, 0);
    sem_init(s2, 0, 0);
    sem_init(s3, 0, 0);
    sem_init(s4, 0, 0);

    arg->s1 = s1;
    arg->s2 = s2;
    arg->s3 = s3;
    arg->s4 = s4;

    pthread_create(&tids[0], NULL, thread1, arg);

    pthread_create(&tids[1], NULL, thread2, arg);

    pthread_create(&tids[0], NULL, thread3, arg);

    pthread_create(&tids[1], NULL, thread4, arg);

    // Espere por TODAS as threads
    for (int i = 0; i < 4; i++) {
        pthread_join(tids[i], NULL);
    }

    sem_destroy(s1);
    sem_destroy(s2);
    sem_destroy(s3);
    sem_destroy(s4);

    free(tids);
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(arg);
    
    
    return 0;
}