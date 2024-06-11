#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>

typedef struct node {
	struct node* left;
	unsigned carid;
	char cgrade;
	struct node* right;

}CARTYPE;

int make_bst(CARTYPE* troot, unsigned id, char grade);
void nonpasscar(CARTYPE* troot);

void main(int argc, char* argv[]) {
	CARTYPE* tree = NULL;
	CARTYPE* ptr;
	unsigned id;
	char grade;
	FILE* input;

	if ((input = fopen(argv[1], "r")) == NULL) {
		printf("Invalid Open input file...\n");
		exit(1);
	}

	while (fscanf(input, "%u %c", &id, &grade)!= EOF)
	{
		if (!tree) {
			tree = (CARTYPE*)malloc(sizeof(CARTYPE));
			tree->carid = id;
			tree->left = tree->right = NULL;
		}
		else {
			make_bst(tree, id, grade);
		}
	}

	printf("\n 검사등급이 A가 아닌 번호 출력\n");
	nonpasscar(tree);

	return 0;

}
int make_bst(CARTYPE* root, unsigned id, char grade) {
	CARTYPE* tptr = root, * before = NULL;
	int first = 0;
	if (root == NULL) first = 1;
	while (tptr) {
		if (id < tptr->carid) {
			before = tptr;
			tptr = tptr->left;
		}
		else if (id > tptr->carid) {
			before = tptr;
			tptr = tptr->right;
		}
		else
			return 0;
	}
	tptr= (CARTYPE*)malloc(sizeof(CARTYPE));
	tptr->carid = id;
	tptr->cgrade = grade;
	tptr->left = tptr->right = NULL;
	if (first == 0) {
		if (id < before->carid) {
			before->left = tptr;
		}
		else before->right = tptr;
	}
	return 1;
}

void nonpasscar(CARTYPE* root) {
	if (root) {
		nonpasscar(root->left);
		if ((root->cgrade) != 'A') {
			printf("%u\n", root->carid);
		}
		nonpasscar(root->right);
	}
}
