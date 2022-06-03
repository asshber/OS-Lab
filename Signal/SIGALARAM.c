#include<stdio.h> 
#include<unistd.h>
#include<wait.h>
#include<signal.h>
#include<errno.h> 

void wakeup() { 
printf("Hello\n");
printf(" \n"); 
}

int main() {
signal(SIGALRM,wakeup);
while(1){
	alarm(5);
	pause();
	printf("Watting For Alarm\n"); 
	
}

return 0; 
	
}


