#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char **argv){
    if (argc != 5){
        printf("Son necesarios 4 argumentos. Se espera algo de la forma \"ejecutable comando1 argumento1 comando2 argumento2\".\n");
        return -1;
    }
    int tuberia[2];
    pipe(tuberia);
    int pid = fork();
    if(pid == -1){
        printf("Error en el pid.\n");
        return -1;
    }
    else if(pid ==0){//hijo
        close(tuberia[1]);
        dup2(tuberia[0], 0);
        close(tuberia[0]);
        execlp(argv[3], argv[3], argv[4], (char*)NULL);
    }
    else {//padre
        close(tuberia[0]);  
        dup2(tuberia[1], 1);
        close(tuberia[1]);
        execlp(argv[1], argv[1], argv[2], (char*)NULL);
    }
    return -2;
}
