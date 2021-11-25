#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sched.h>

int main(){
    struct sched_param param;
    int prio, max, min;

    int sched_policy = sched_getscheduler(0);
    if (sched_policy == -1) {
	printf("Error en politica");
	return -1;
    }
    max = sched_get_priority_max(sched_policy);
    min = sched_get_priority_min(sched_policy);
    int e = sched_getparam(0,&param);
    if (e != 0) {
	printf("Error en getparam");
	return -1;
    }
    prio = param.sched_priority;
    printf("Politica: ");
    switch(sched_policy){
	case SCHED_OTHER:
	    printf("SCHED_OTHER\n"); break;
	case SCHED_FIFO:
	    printf("SCHED_FIFO\n"); break;
	case SCHED_RR:
	    printf("SCHED_RR\n"); break;
	default:
	    printf("Error\n");
	    return -1;
	}
    printf("Prioridad del proceso actual: %d\n",prio);
    printf("Valor maximo de prioridad: %d\n",max);
    printf("Valor minimo de prioridad: %d\n",min);
    return 0;
}


