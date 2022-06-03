#include<stdio.h>
#include<signal.h>
#include<unistd.h>
//signal handling function that will except ctrl-\ and ctrl-c
void sig_handler(int signo)
{
    //looks for ctrl-c which has a value of 2
    if (signo == SIGINT)
        printf("\nreceived SIGINT\n");
    //looks for ctrl-\ which has a value of 9
    else if (signo == SIGQUIT)
        printf("\nreceived SIGQUIT\n");
    else if (signo == SIGTSTP)
        printf("\nreceived SIGSTP\n");
    else if (signo == SIGKILL)
        printf("\nreceived SIGKILL\n");
    else if (signo==SIGALRM)
        printf("Alarm recieved\n");
    else if(signo==SIGTERM)
        printf("Caught signal by %d\n", signo);

}

int main(void)
{
//     //these if statement catch errors
//     signal(SIGINT, sig_handler);
//     signal(SIGQUIT, sig_handler);
//     signal(SIGTSTP, sig_handler);
//     signal(SIGKILL, sig_handler); 
//     //Runs the program infinitely so we can continue to input signals
//     while(1)
//         sleep(1);
//     return 0;
    signal(SIGALRM,sig_handler);
    signal(SIGTERM,sig_handler);
    int i=0;
    while (1){
        printf("%d\n",getpid());
        sleep(100);
	}
	return 0;
}
