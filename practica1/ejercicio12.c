#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char**args){
    time_t times;
    if ((times = time(NULL)) == -1){
   	 fprintf(stderr, "%s", strerror(errno));
   	 return -1;
    }
    printf("Hora en segundos desde el Epoch: %ld\n", times);
    return 0;
}

