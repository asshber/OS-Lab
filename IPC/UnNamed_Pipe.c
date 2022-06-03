#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
#include<wait.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
int fd[2]; 
// fd[0] - read 
// fd[1] - write 
if (pipe(fd) == -1)
{ 
printf("An error ocurred with opening the pipe\n");
return 1; 
}
int id = fork();
if (id == 0) 
{ 
close(fd[0]);
int x;
printf("Input a number: ");
scanf("%d", &x);
if(write(fd[1], &x, sizeof(int))==-1){
	printf("Error Occured While Writing");
	return 2;
}
close(fd[1]); 
} 
else {
	
	close(fd[1]);
	int y;
if(read(fd[0],&y,sizeof(int))==-1){
	
	printf("Error Occured While reading");
	return 2;
}	
	close(fd[0]);
	printf("GOT FROM CHILD PROCESS %d \n",y);
}
return 0; 
}
