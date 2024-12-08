#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;// phan du lieu cua node
	struct Node* next;// con tro, tro den nut tiep theo
}Node;

// Tao 1 Node  
Node* createNode(int value){
	// cap phat bo nho 
	Node* newNode = (Node*)malloc(sizeof(Node));
	// gan data cho node
	newNode->data = value;
	// gan phan link
	newNode->next = NULL;
	return newNode;
};


//them 1 phan tu vao dau head
void insertHead(Node** head, int value){
	// tao 1 node moi 
	Node* newNode = createNode(value);
	// tro node moi den head
	newNode->next = *head;
	// cap nhat head tro den node moi
	*head = newNode;
};

// duyet danh sach 
void printList(Node* head){
	Node* temp  = head;
	while (temp != NULL){
		printf("%d--->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
int main(){
	Node* head = NULL;
	// them 1 phan tu vao dau danh sach
	printf("Moi ban nhap vao phan tu dau : ");
	int value;
	scanf("%d", &value);
	insertHead(&head,value);
	// in ra
	printf("Danh sach ne \n");
	printList(head);
	return 0;
}
