#include<stdio.h> 
#include<unistd.h>
#include<wait.h>
#include<signal.h>
void signal_handler(int num){
	 printf("Received Signal from %d\n",num);
	
}
 int main()
 {
 	signal(SIGINT, signal_handler); 
	sleep(100);
	return 0;
 	
 }

