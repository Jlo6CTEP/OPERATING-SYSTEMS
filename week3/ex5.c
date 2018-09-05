#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
	int item;
	struct node* next;
	struct node* prev;
} node;

int* print_list(node* list);
node* insert_node(node* list, int item);
node* delete_node(node* list, int del);

int main() {
	node* a;
	a = insert_node(NULL, 10);
	insert_node(a, 12);
	insert_node(a, 11);
	insert_node(a, 17);
	insert_node(a, 16);
	insert_node(a, 15);
		
	
	a = delete_node(a,10);
	a = delete_node(a,17);
	a = delete_node(a,15);
	int *print = print_list(a);
	
	for (int i =0; i < 3; i++) {
		printf("%d ", print[i]);
	}
}

int* print_list(node* list){
	int *a = (int*)realloc(NULL, 8);
	int length = 2;
	int counter = 0;
	a[0] = list->item;
	while (list->next != NULL) {
			list = (node*)list->next;
			counter ++;
			if  (counter >= length) {
				a = (int*)realloc(a,length*8);
				length*=2;
			}
			a[counter] = list->item;
	}
	return a;
}
node* insert_node(node* list, int item){
	node* a = malloc(sizeof(node));
	a->item = item;
	a->next = NULL;
	a->prev = NULL;
	if (list == NULL) {
		return a;
	} else {
		while (list->next != NULL) {
			list = (node*)list->next;
		}
		list->next = (struct node*)a;
		a->prev = (struct node*)list;
		return a;
	}	
}

node* delete_node(node* list, int del){
	node *a = list;
	
while (list->next != NULL && list->item != del) {
		list = (node*)list->next;
	}
	if (list->item != del) {
		return(a);
	}
	if (list->prev == NULL && list->next == NULL) {
		free(list);
		return (node*)NULL;
	} else if (list->prev == NULL) {
		a = (node*)list->next;
		free(list);
		return a;
	} else {
		((node*) (list->prev))->next = list->next;
		if (list->next != NULL) {
		((node*) (list->next))->prev =list->prev;
		} 
		free(list);
		return(a);	
	} 
			
}
