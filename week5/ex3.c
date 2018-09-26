#include <windows.h>
#include <stdio.h>

#define BUFFER_SIZE 256

int buffer = 0;
int consumer_sleep = 0;
int producer_sleep = 0;

DWORD WINAPI consumer(void* data) {
	while (1) {
		while(!consumer_sleep) {
			if (buffer == 0) {
				consumer_sleep = 1;
				break;
			}
			buffer--;

			if(buffer == BUFFER_SIZE - 1) {
				producer_sleep = 0;
			}
			Sleep(10);
		}
		Sleep(10);
	}
}


DWORD WINAPI producer(void* data) {
	while (1) {
		while(!producer_sleep) {
			if (buffer == BUFFER_SIZE) {
				producer_sleep = 1;
				break;
			}
			buffer++;
			if (buffer == 1) {
				consumer_sleep = 0;
			}
			Sleep(10);
		}
		Sleep(10);
	}
}

int main() {
	HANDLE thread_consumer = CreateThread(NULL, 0, consumer,(void*) NULL, 0, NULL);
	HANDLE thread_producer = CreateThread(NULL, 0, producer,(void*) NULL, 0, NULL);

	while (!(producer_sleep && consumer_sleep)) {
		printf("Current number of elements %d\n",buffer);
		Sleep(30000);
	}

	printf("Houston we have a problem \n%s");
	
	return 0;
}