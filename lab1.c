//Author Peter Adamson

#include <pthread.h>
#include <stdio.h>

//function declarations
void decrement(int *i);
void increment(int *i);
void *loopAndAdd();

//gloabl variable declaration
pthread_t thread;

int main()
{
	//variable initializations
	int i = 5;
	pid_t pid = pid;

	//fork the processes	
	pid = fork(); //returns process ID of child process to the parent and 0 to the child

	if(pid == -1)	//process creation failed
	{
		printf("child process failed to create\n");
	}
	else if(pid == 0) //this is the child process
	{
		//increment i
		increment(&i);
		printf("the child value of i is: %d\n",i);

		//thread creation
		pthread_t mythread;
		pthread_create(&thread, NULL, &loopAndAdd, NULL);
		
		//get thread id of newly created thread
		pthread_t threadid = pthread_self();
		printf("thread id in child process thread: %u\n",threadid);

		//wait for termination
		pthread_join(thread, NULL);
	}
	else		//this is the parent process
	{
		//decrement i
		decrement(&i);
		printf("the parent value of i is: %d\n",i);
	}
}

//decreases i by 1
void decrement(int *i)
{
	*i = *i - 1;
	pid_t pid = getpid();
	printf("This decrement is executed by the parent with pid %d\n",pid);
}

//increases i by 1
void increment(int *i)
{
	*i = *i + 1;
	pid_t pid = getpid();
	printf("This incremement is executed by the child with pid %d\n",pid);
}

//increases local variable add
void *loopAndAdd()
{
	int threadid = pthread_self();
	printf("New thread in child process thread: %u\n",threadid);
	int j;
	int add = 0;
	for(j = 0; j < 15; j++)
	{
		add = add + j;
	}
}
