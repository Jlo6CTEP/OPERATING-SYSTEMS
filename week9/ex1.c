#include <stdio.h>
#include <malloc.h>

typedef struct {
	int id;
	int time;
} page;

int find_oldest(page *frame, int size);
int is_inframe(page *frame, int size, int id);


int main(int args, char** kwargs) {
	FILE *f = fopen("input.txt","r");
	int in;

	int size = atoi(kwargs[1]);

	page *frame = (page*)malloc(size*sizeof(page));

	
	for (int i = 0; i < size; i++) {
		frame[0].id = 0;
		frame[0].time = 0;
	}
	
	printf("id, time:  %d\n ", 1);
		
		for (int i = 0; i < size; i++) {
			printf(" %d", frame[i].id);
		}

		
		printf("\n time: \n ");
				
		
		for (int i = 0; i < size; i++) {
			printf(" %d", frame[i].time);
		}

		printf("\n");
		

	int time = 1;

	int mis_count = 0;
	int hit_count = 0;
	
	while (fscanf(f, "%d", &in) != EOF) {
		int oldest = find_oldest(frame, size);
		if (is_inframe(frame,size,in)) {
			hit_count++;
		} else {
			mis_count++;
		}

		
		frame[oldest].id = in;
		frame[oldest].time = time;
		time++;
	}

	free(frame);

	float mis_hit = mis_count/hit_count;

	printf("mis/hit ratio %f",mis_hit);
	
	return 0;
} 

int find_oldest(page *frame, int size) {
	int oldest = frame[0].time;
	for (int i = 0; i < size; i++) {
		if (frame[i].time <= frame[oldest].time)
			oldest = i;
	}
	return oldest;
}

int is_inframe(page *frame, int size, int id) {
	int contains = 0;
	for (int i = 0; i < size; i++) {
		if (frame[0].id == id) {
			contains = 1;
		}
	}
	return contains;
}
