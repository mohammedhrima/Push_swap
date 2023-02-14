#include <stdio.h>
#include <signal.h>

void handle_signal(int sig)
{
	printf("signal is %d\n", sig);
}

int main(void)
{
	signal(SIGINT, handle_signal);
	while(1);
}