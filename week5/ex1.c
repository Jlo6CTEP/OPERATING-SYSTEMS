#include <windows.h>
#include <stdio.h>

DWORD WINAPI ThreadFunc(void* data) {
	printf("Hello from thread with number %d\n", GetCurrentThreadId());
	Sleep(50);
	return 0;
}
int main() {
	long unsigned int id;
	HANDLE thread[10];
	for (int i = 0; i < 10; i++) {
		thread[i] = CreateThread(NULL, 0, ThreadFunc,(void*) NULL, 0, &id);
		printf("Thread created with id: %d and number %d\n",id,i);
		WaitForSingleObject(thread[i], INFINITE); //Comment/uncomment this to obtain synchronous/asynchronous mode
	}
	Sleep(1000);
	return 0;
}