#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
#include<string.h>
#include<unistd.h>
sem_t mutex_luggage_weight;
sem_t mutex_luggage_check;
sem_t mutex_pass;
struct persondetails
{
    char* name;
};
void* airport(void* arg)
{
    struct persondetails obj=*(struct persondetails*)arg;
    sem_wait(&mutex_luggage_weight);
    printf("%s has started the Weiging process\n",obj.name);
    sleep(4);
    printf("%s has ended the Weiging process\n",obj.name);
    sem_post(&mutex_luggage_weight);
    sem_wait(&mutex_luggage_check);
    printf("%s has started the Luggage Check process\n",obj.name);
    sleep(7);
    printf("%s has Ended the Luggage chcek process\n",obj.name);
    sem_post(&mutex_luggage_check);
    sem_wait(&mutex_pass);
    printf("%s has started the Boarding Pass process\n",obj.name);
    sleep(3);
    printf("%s has ended the Boarding pass process\n",obj.name);
    sem_post(&mutex_pass);
}
int main()
{
    pthread_t t[10];
    sem_init(&mutex_luggage_weight,0,1);
    sem_init(&mutex_luggage_check,0,1);
    sem_init(&mutex_pass,0,1);
    struct persondetails* obj=malloc(sizeof(struct persondetails));
    obj->name="Ali Ashber\0";
    pthread_create(&t[0],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 2\0";
    pthread_create(&t[1],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 3\0";
    pthread_create(&t[2],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 4\0";
    pthread_create(&t[3],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 5\0";
    pthread_create(&t[4],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 6\0";
    pthread_create(&t[5],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 7\0";
    pthread_create(&t[6],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 8\0";
    pthread_create(&t[7],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 9\0";
    pthread_create(&t[8],NULL,airport,(void*)obj);
    sleep(1);
    obj->name="Person 10\0";
    pthread_create(&t[9],NULL,airport,(void*)obj);
    sleep(1);
    pthread_join(t[0],NULL);
    pthread_join(t[1],NULL);
    pthread_join(t[2],NULL);
    pthread_join(t[3],NULL);
    pthread_join(t[4],NULL);
    pthread_join(t[5],NULL);
    pthread_join(t[6],NULL);
    pthread_join(t[7],NULL);
    pthread_join(t[8],NULL);
    pthread_join(t[9],NULL);
}