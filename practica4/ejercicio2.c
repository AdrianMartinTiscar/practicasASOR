#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

const int TAM = 256;

int main(int argc, char **argv){
   
    int p_h[2], h_p[2];
    pipe(p_h);
    pipe(h_p);
    int pid = fork();
    if(pid == -1){
        printf("Error en el pid.\n");
        return -1;
    }
    else if(pid ==0){//hijo
	char mensajeP[TAM +1];
	char resp = 'l';
        close(p_h[1]); 
        close(h_p[0]);
        for(int i=0;i<10;i++){
	    ssize_t bytes = read(p_h[0], mensajeP, TAM);
	    mensajeP[bytes]='\0';
	    if(i==0) printf("Reciviendo mensajes del padre...\n");
	    printf("Mensaje del padre: %s",mensajeP);
	    sleep(1);
	    if(i == 9) resp = 'q';
            write(h_p[1], &resp, 1);
	}
	close(p_h[0]);
        close(h_p[1]);       
    }
    else {//padre
	char mensajeH[TAM +1];
        close(p_h[0]); 
        close(h_p[1]);
	char resp = 'l';
        while(resp == 'l'){
	    ssize_t bytes = read(0, mensajeH, TAM);
	    write(p_h[1], mensajeH, bytes);
	    read(h_p[0], &resp, sizeof(char));
	}
	close(p_h[1]);
        close(h_p[0]); 
    }
    return 0;
}
