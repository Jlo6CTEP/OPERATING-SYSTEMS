#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

const char file[] = "race.txt";

int main() {
	HANDLE hFile = CreateFile(file, GENERIC_READ|FILE_APPEND_DATA, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	// to obtain asynchronous mode add FILE_SHARE_READ | FILE_SHARE_WRITE instead of 0 in previous line
	int i = 0;
	while(i <= 60) {
		unsigned long int size = GetFileSize(hFile,NULL);
		char input[size];
		long unsigned int real_size;
				
		ReadFile(hFile,input,size,&real_size,NULL);
		char last[2]; 
		last[0] = input[size-1];
		last[1] = '\0';
		int symbol;
		if (size == 0) 
			symbol = 0;
		else
			symbol = (atoi(last)  + 1) % 10;
		char output[2];
		sprintf(output, "%d", symbol);
		output[1] = '\0';
		WriteFile(hFile,(void*)output,1,&real_size,NULL);   
		i++;
	}
	CloseHandle(hFile);
	return 0;	
}