#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink, * rlink;
}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink = newnode;
	newnode->rlink->llink = newnode;
}

void print_dlist(DListNode* head) {
	DListNode* p;
	for (p = head->rlink; p != head;p=p->rlink ) {
		printf("%2d", p->data);
	}
	printf("(head)");
	printf("\n");
}

element ddelete(DListNode* head, DListNode* removed) {
	element r;
	if (removed == head) return;
	r = removed->data;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;

	return r;
}

element ddelete_first(DListNode* head) {
	element r;
	r = head->rlink->data;

	head->llink->rlink = head->rlink;
	head->rlink->llink = head->llink;

	return r;
}
element ddelete_last(DListNode* head) {
	element r;
	r = head->rlink->data;

	head->llink->rlink = head->rlink;
	head->rlink->llink = head->llink;

	return r;
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	int choice = 0;
	int n1, n2;
	element r;
	while (1) {
		printf("\n메뉴\n");
		printf("1. 리스트 처음에 추가\n");
		printf("2. 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5. 리스트 프린트\n");
		printf("6. 프로그램 종료\n");
		printf("선택 : ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			printf("리스트 처음에 추가할 숫자를 입력하시오 : ");
			scanf_s("%d", &n1);
			dinsert(head, n1);
			break;
		case 2:
			printf("리스트 마지막에 추가할 숫자를 입력하시오 : ");
			scanf_s("%d", &n2);
			dinsert(head->llink, n2);
			break;
		case 3:
			printf("리스트 처음 노드를 삭제합니다.");
			r = ddelete_first(head->rlink);
			break;
		case 4:
			printf("리스트 마지막 노드를 삭제합니다.");
			r = ddelete_last(head->llink);
			break;
		case 5:
			printf("리스트를 출력합니다.");
			print_dlist(head);
			break;
		case 6:
			printf("프로그램을 종료합니다.");
			exit(0);
		default:
			printf("잘못된 선택입니다.\n");
			break;
		}
	}

	/*dinsert(head, 10);
	dinsert(head, 20);
	dinsert(head->rlink->rlink, 5);
	dinsert(head->llink, 2);
	print_dlist(head);

	element deleted;
	deleted = ddelete(head, head->rlink);
	printf(" Deleted = %d\n", deleted);
	deleted = ddelete(head, head->llink);
	printf(" Deleted = %d\n", deleted);

	print_dlist(head);*/
}