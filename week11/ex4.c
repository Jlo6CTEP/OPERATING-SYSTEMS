#include <windows.h> 
#include <stdlib.h> 
#include <string.h>
#include <stdio.h>

const char file_source[] = "ex4.txt";
const char file_dest[] = "ex4.memcpy.txt";

int main() {
	HANDLE f_source_handle = CreateFileA(file_source,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	DWORD sizeLow = GetFileSize(f_source_handle, NULL);
	DWORD sizeHigh = 0;
		
	
	HANDLE map_source_handle = CreateFileMappingA(f_source_handle, NULL,PAGE_READWRITE, sizeHigh, sizeLow, NULL);
	char* map_source = (char*) MapViewOfFile(map_source_handle, FILE_MAP_READ, 0, 0, sizeLow);

	HANDLE f_dest_handle = CreateFileA(file_dest, GENERIC_READ|GENERIC_WRITE,0,NULL,CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);
	HANDLE map_dest_handle = CreateFileMappingA(f_dest_handle, NULL, PAGE_READWRITE, sizeHigh, sizeLow, NULL);
	char* map_dest = (char*) MapViewOfFile(map_dest_handle, FILE_MAP_WRITE, 0, 0, sizeLow);

	CopyMemory(map_dest, map_source, sizeLow);
	FlushViewOfFile(map_dest, sizeLow);
	
	CloseHandle(map_dest_handle);
	CloseHandle(map_source_handle);
		
	CloseHandle(f_source_handle);
	CloseHandle(f_dest_handle);
	return 0;	
}