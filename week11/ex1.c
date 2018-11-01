#include <windows.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>

const char file[] = "ex1.txt";

int main() {
	DWORD sizeLow = 64;
	DWORD sizeHigh = 0;
	HANDLE f_handle = CreateFileA(file, GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE map_handle = CreateFileMappingA(f_handle, NULL,PAGE_READWRITE, sizeHigh, sizeLow, NULL);
	char* map = (char*) MapViewOfFile(map_handle, FILE_MAP_ALL_ACCESS, 0, 0, sizeLow);
	char string_to_write[64] = "What a nice day \0\n";
	CopyMemory(map, string_to_write, sizeLow);
	FlushViewOfFile(map, sizeLow);
	CloseHandle(map_handle);
	CloseHandle(f_handle);
	return 0;	
}