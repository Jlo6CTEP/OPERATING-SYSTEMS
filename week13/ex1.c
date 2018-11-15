#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main() {
	char file[20] = "input.txt";
	HANDLE f_handle = CreateFileA(file, GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	int count = 8;
	long unsigned int read;
	char *input;
	input = (char*)malloc(8);
	int i = 0;
	while (ReadFile(f_handle, &input[i], 1, &read, NULL) && (!read==0)) {
		if (i+1 == count) {
			count *= 2;
			input = (char * )realloc(input, count);
		}
		i++;
	}
	input[i] = '\0';
	printf("%s", input);

	char fuck_the_c[2];
	fuck_the_c[1] = '\0';

	int avail_size = 4;
	int *available;
	available = (int*)malloc(avail_size*sizeof(int));

	
	int counter = 0;
	i = 0;
	for (i = 0; input[i] != '\n'; i++) {
		if (input[i] != ' ') {
			fuck_the_c[0] = input[i];
			available[counter] = atoi(fuck_the_c);		
			counter++;
			if (counter == avail_size) {
				available = (int*) realloc(available, avail_size*sizeof(int)*2);
				avail_size *= 2;
			}
		}
	}

	i+=3;
		
	int *existing = (int*)malloc((counter-1)*sizeof(int));
	
	counter = 0;
	for (i = i; input[i] != '\n'; i++) {
		if(input[i] != ' '){
			fuck_the_c[0] = input[i];
			existing[counter] = atoi(fuck_the_c);		
			counter++;
		}
	}
	
	i += 3;

	int init_size = 8;


	int ** mat = malloc( init_size * sizeof(int) );
	   for ( int k = 0; k < init_size; k++ ) {
	      mat[k] = malloc( (counter-1) * sizeof(int) );
	   }
	
	int f = counter;
	counter = 0;
	int counter2 = 0;
	int check = 1;
	for (int k = 0; input[i] != '\r' ; k++) {
		for (i = i; input[i] != '\r'; i++) {
			if(input[i] != ' '){
				printf("%c\n", input[i]);
				fuck_the_c[0] = input[i];
				mat[k][counter] = atoi(fuck_the_c);
				counter++;
			}
			if (counter == init_size) {
				init_size *= 2;
				mat = realloc(mat, init_size*sizeof(int));
				for ( int z = 0; z < init_size; z++ ) {
					mat[z] = realloc( mat[z], f * sizeof(int) );
				}
			}
		}
		i+=2;
		counter2 = counter;
		counter = 0;
		printf("%d",i);
	}

	i+=3;

	int ** e = malloc( init_size * sizeof(int) );
	for ( int k = 0; k < init_size; k++ ) {
	   e[k] = malloc( (counter-1) * sizeof(int) );
	}
	

	for (int k = 0; input[i] != '\r' ; k++) {
		for (i = i; input[i] != '\r'; i++) {
			if(input[i] != ' '){
				printf("%c\n", input[i]);
				fuck_the_c[0] = input[i];
				e[k][counter] = atoi(fuck_the_c);
				counter++;
			}
		}		
		i+=2;
		counter = 0;
	}
	
	for (int k =0; k < f+1; k++)
	for (int i =0; i < counter2; i++)
		printf("%d",e[k][i]);
	
		
	free(input);
	return 0;
}