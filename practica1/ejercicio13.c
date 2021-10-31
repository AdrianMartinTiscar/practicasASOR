#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char**args){
    int veces = 1000000;
    struct timeval inicio;    
    int ini = gettimeofday(&inicio, NULL);
    ini = inicio.tv_usec;
    for(int i = 0;i < veces; i++);
    struct timeval fin;
    int f = gettimeofday(&fin, NULL);
    f= fin.tv_usec;
    printf("Tiempo que tarda un bucle en incrementar una variable %d veces: %ldms\n",veces, f-ini);
    return 0;
}

