#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <locale.h>

int main(){
   setlocale(LC_ALL, "es_ES");
   char s[200];
   time_t tim = time(NULL);
   struct tm* ltime = localtime(&tim);
   strftime(s, 200, "%A, %d de %B de %Y, %H:%M", ltime);
   printf(s);
   return 0;
}
