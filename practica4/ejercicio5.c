#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

const int TAM = 256;

int main(int argc, char **argv){
    
    int pd = open("tuberia",O_RDONLY|O_NONBLOCK,0222);
    if(pd == -1){
	pd = mkfifo("tuberia",0666);
    }
    int pd2 = open("tuberia2",O_RDONLY|O_NONBLOCK,0222);
    if(pd2 == -1){
	pd2 = mkfifo("tuberia2",0666);
    }
    char buffer[TAM];
    fd_set set;
    int nfds;
    if(pd2 > pd) nfds = pd2+1;
    else nfds = pd+1;
    while(1){
        FD_ZERO(&set);
    	FD_SET(pd, &set);
    	FD_SET(pd2, &set);
	int numfd = select(nfds, &set, NULL, NULL, NULL);
	if(numfd == -1){
	    printf("Error en el select.\n");
	    close(pd);
    	    close(pd2);
	    return -1;
	}
	if(FD_ISSET(pd, &set)){
	    int leido = read(pd, buffer, TAM);
	    if(leido == 0){
		close(pd);
		int pd = open("tuberia",O_RDONLY|O_NONBLOCK,0222);
    		if(pd == -1){
		    pd = mkfifo("tuberia",0666);
   		}
		if (pd+1 > nfds) nfds = pd+1;
	    }
	    else{
	        write(1, "tuberia: ", strlen("tuberia: "));
   	 	write(1, buffer, leido);
	    }
	}
	if(FD_ISSET(pd2, &set)){
	    int leido = read(pd2, buffer, TAM);
	    if(leido == 0){
		close(pd2);
		int pd2 = open("tuberia2",O_RDONLY|O_NONBLOCK,0222);
    		if(pd2 == -1){
		    pd2 = mkfifo("tuberia2",0666);
   		}
		if (pd2+1 > nfds) nfds = pd2+1;
	    }
	    else{
	        write(1, "tuberia2: ", strlen("tuberia2: "));
   	 	write(1, buffer, leido);
	    }
	}
	
    }  
    close(pd);
    close(pd2);
    return 0;
}
