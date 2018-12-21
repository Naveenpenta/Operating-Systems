#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t mutex; //variables of semaphore type
sem_t db;
int readercount=0;
pthread_t reader1,reader2,writer1,writer2;
void *reader(void *p)
{
	sem_wait(&mutex);
	printf("Mutex acquired by readee");
	
	printf("\n");
	readercount++;
	printf("current count of reraders is %d",readercount);
	if(readercount==1)//the first reader should stop  
		sem_wait(&db);
	printf("mutex completin");	
	sem_post(&mutex);
	int value;
	sem_getvalue(&mutex,&value);
	printf(" got the value %d",value);
	//printf("mutex completin");
	printf("\n");
	
	printf("going to read");
	printf("\n");
	sem_wait(&mutex);
	readercount--;
	if(readercount==0)
			sem_post(&db);
			
	sem_post(&mutex);
	printf("reading complete");
	printf("\n");
}
void *writer(void *p)
{
	printf("writer %s  is waiting",p);
	printf("\n");
	sem_wait(&db);
	printf("writer %s is writting",p);
	printf("\n");
	sem_post(&db);
}

//void *reader(void *);
//void *writer(void *);
 
main()
{
	//sem_init(sem_t xx,to be forked or not ,intial value); 
	sem_init(&mutex,0,1);
	sem_init(&db,0,1);
	int i=0;
	int n;
	
		while(i<15)
		{
		
		
				pthread_create(&reader1,NULL,reader,"1");	
	
				pthread_create(&reader2,NULL,reader,"2");
		
		
				pthread_create(&writer1,NULL,writer,"1");
		
			pthread_create(&writer2,NULL,writer,"2");
			i+=1;
		}
	
		
		

			
}

