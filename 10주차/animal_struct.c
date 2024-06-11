#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct fnode* fpointer;
struct fnode {
	char animal[10];
	int item;
	fpointer next;
};

void main() {
	fpointer head = NULL, ptr, another, before=NULL;
	int k, how_many = 0;

	head = (fpointer)malloc(sizeof(struct fnode));
	strcpy(head->animal, "dog");
	head->item = 10;
	head->next = NULL;

	for (k = 0; k < 4; k++) {
		another = (fpointer)malloc(sizeof(struct fnode));
		printf("동물과 해당 동물의 수를 입력하세요 :");
		scanf("%s %d", (another->animal), &(another->item));
		ptr = head;
		while (ptr != NULL) {
			before = ptr;
			ptr = ptr->next;
		}
		before->next = another;
		another->next = NULL;
	}
	printf("-------------------------------\n");
	ptr = head;
	while (ptr != NULL) {
		printf("%s: %d\n", ptr->animal, ptr->item);
		how_many += ptr->item;
		ptr = ptr->next;
	}
	printf("전체 마릿수 : %d\n", how_many);
}