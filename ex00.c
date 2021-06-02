#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "../ex00/ft_strdup.c"

char *ft_strdup(char *src);

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
	char *str;

	printf("\nQuote: Would it save you a lot of time if I just gave up and went mad now?\n\n");
	
	char *string1 = "Pa2mDTow2O0rcWF9QFipJAb7kpkFdNjmvdfKQ6uL";
	str = ft_strdup(string1);
	printf("string = %s\t| ret %s\n", string1, str);
	free(str);
	char *string2 = "ffJykmhacQ2rn3Nm1";
	str = ft_strdup(string2);
	printf("string = %s\t\t\t\t| ret %s\n", string2, str);
	free(str);
	char *string3 = "sXlEDtdEkD";
	str = ft_strdup(string3);
	printf("string = %s\t\t\t\t\t| ret %s\n", string3, str);
	free(str);
	char *string4 = "usFWKEz3sNyIi49fz6G";
	str = ft_strdup(string4);
	printf("string = %s\t\t\t\t| ret %s\n", string4, str);
	free(str);
	char *string5 = "5PmuKqUFZXAPHI6A3mZ3Rj";
	str = ft_strdup(string5);
	printf("string = %s\t\t\t\t| ret %s\n", string5, str);
	free(str);
	char *string6 = "FplJKDPP6KZCGhlaMdjr6j4YTd6iNh";
	str = ft_strdup(string6);
	printf("string = %s\t\t\t| ret %s\n", string6, str);
	free(str);
	char *string7 = "mbewt2H8xImgsxzQULr3a3cG0sYTeBsGaZsZqYJ9ps";
	str = ft_strdup(string7);
	printf("string = %s\t| ret %s\n", string7, str);
	free(str);

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