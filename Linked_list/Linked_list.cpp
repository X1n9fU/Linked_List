#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count=0;
int* c=&count;

typedef struct {
	char name[100];
}element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head; 
	head = p; 
	return head;
}

void print_list(ListNode* head) {
	if (strcmp(head->data.name, "head->") != 0) 
		printf("head->");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL\n");
}

ListNode* search(ListNode* head, element x) {
	ListNode* p = head;
	while (p != NULL) {
		if (strcmp(p->data.name, x.name) == 0)
			return p;
		count++;
		p = p->link;
	}
	return NULL;
}

ListNode* findNode(ListNode* head) {
	ListNode* p = head;
	int c = 1;
	while (c != count) {
		if (count == 0)
			break;
		p = p->link;
		c++;
	}
	return p;
}

ListNode* delete_(ListNode* head, ListNode* pre) {
	if (count==0) {
		ListNode* removed = head;
		head = removed->link;
		free(removed);
		return head;
		
	}
	else {
		ListNode* removed;
		removed = pre->link;
		pre->link = removed->link;
		free(removed);
		return head;
	}
}

void split_list(ListNode* head, ListNode* pre) {
	ListNode* p = pre;
	pre = pre->link;
	p->link = NULL;
	printf("list1: ");
	print_list(head);
	printf("list2: ");
	print_list(pre);
}

int main(void) {
	ListNode* head= NULL;
	element data;
	strcpy(data.name, "PEACH");
	head= insert_first(head, data);
	strcpy(data.name, "MELON");
	head= insert_first(head, data);
	strcpy(data.name, "MANGO");
	head= insert_first(head, data);
	strcpy(data.name, "LEMON");
	head = insert_first(head, data);
	strcpy(data.name, "BANANA");
	head = insert_first(head, data);
	strcpy(data.name, "KIWI");
	head = insert_first(head, data);
	strcpy(data.name, "APPLE");
	head = insert_first(head, data);
	print_list(head);

	element fruit;
	printf("���� �ܾ�:");
	scanf("%s", fruit.name);
	if (fruit.name == "head")
		exit(1);	
	search(head, fruit);//�ܾ� ã��, �� �ܾ��� �� ������ ��� �����ϴ��� COUNT ����
	ListNode* pre = findNode(head);//COUNT �� ��ŭ PRE��带 �����δ�.
	head= delete_(head, pre);//pre��尡 ����Ű�� ���� ��带 ���ָ� ã�Ҵ� �ܾ �������.
	split_list(head, pre);//����� �ܾ �������� �� �� ������ ��� 
	return 0;
}