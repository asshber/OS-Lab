
#include <stdio.h> //needs for perror 
#include <signal.h> //signal.h 
#include<wait.h>
#include<unistd.h>


  void handler(int signum){
   if(signum == SIGINT)
   { 
   printf("CONTROL SIGNAL IS PRESSED!");  
	} 
    } 
int main(){
 struct sigaction sa; //creating sa, which will be called in sigaction function with the control signal variable 
 sa.sa_handler = handler; //this is declaring which handler is used if control signal is passed to sa;
  while(1){ 

printf("/"); 
for(int i=0;i<=100000;i++){
}
  if(sigaction(SIGINT, &sa, NULL) == -1)
   perror("S1GACTION"); 
}
   return 0;
}
