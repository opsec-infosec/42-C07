#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex01/ft_range.c"

int *ft_range(int min, int max);

int func_done = 0;
int timer_done = 0;

void *timer(void *var)
{
	var = 0x00;
	sleep(5);
	timer_done = 1;
	return (0);
}

void *execute(void *var)
{
	var = 0x00;
	int	*intarray;
	int i = 0;
	int min = 21;
	int max = 42;

	printf("\nmin = %d | max = %d\n", min, max);
	intarray = ft_range(min,max);
	while (i < (max - min))
		printf("%d",intarray[i++]);
	printf("\n\n");
	min = 25;
	max = 20;
	intarray = ft_range(min, max);
	printf("min = %d | max =%d\n",min,max);
	if (intarray == NULL)
		printf("Min > Max -- NULL Returned\n");
	else
		printf("Min > Max -- NO NULL RETURNED\n");
	func_done = 1;
	return (0);
}
int main(void)
{
	pthread_t threadId;
	pthread_t timerId;
	int	threadId_Sig;
	
	threadId_Sig = pthread_create(&threadId, NULL, execute,  NULL);
	pthread_create(&timerId, NULL, timer, NULL);

	while (1) {
		if (timer_done) {
			pthread_cancel(threadId);
			printf("*** TIMEOUT ***\n");
			return (1);
		}
		if (func_done)
		{
			pthread_cancel(timerId);
			return (0);
		}
	}
	return (0);
}