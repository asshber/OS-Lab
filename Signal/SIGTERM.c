#include<stdio.h>
#include<signal.h>


void sign_handler(int sig)
{
	printf("Caught signal by %d\n", sig);
}

int main()
{
	int i=0;
	signal(SIGTERM, sign_handler);
	while (1){
		printf("i = %d",i);
		i++;
	}
	return 0;
}

