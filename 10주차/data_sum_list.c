#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct list_node *list_pointer;
struct list_node {
	int data;
	list_pointer link;
};

void print_list(list_pointer ptr);
list_pointer make_node();
int nodesum(list_pointer ptr);
int nodenumber(list_pointer ptr);

void main() {
	list_pointer ptr;
	ptr = make_node();
	print_list(ptr);
	printf("list안의 data 합 : %d \n", nodesum(ptr));
	printf("list안의 node 수 : %d \n", nodenumber(ptr));
}

list_pointer make_node() {
	list_pointer first, second, third;
	first = (list_pointer)malloc(sizeof(struct list_node));
	second = (list_pointer)malloc(sizeof(struct list_node));
	third = (list_pointer)malloc(sizeof(struct list_node));

	third->link = NULL;
	second->link = third;
	first->link = second;

	first->data = 100;
	second->data = 200;
	third->data = 300;
	
	return first;
}

void print_list(list_pointer ptr) {
	printf("리스트 안의 정보 : ");

	for (; ptr; ptr = ptr->link) {
		printf("%4d", ptr->data);
	}
	printf("\n");
}

int nodenumber(list_pointer ptr) {
	int count = 0;
	for (; ptr; ptr = ptr->link) {
		count++;
	}
	return count;
}
