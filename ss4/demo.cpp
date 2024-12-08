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
//	them phan tu vao cuoi danh sach
void insertEnd(Node** head, int value){
	// tao 1 node moi 
	Node* newNode = createNode(value);
	if(*head==NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

//	them 1 phan tu vao vi tri bat ki
vod insertElement(Node** head, int value, int position){
	// tao 1 node moi 
	Node* newNode = createNode(value);
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node* temp = *head;
	for(int i =0; i < position-1 && temp != NULL; i++ ){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	
}


// duyet danh sach 
void printList(Node* head){
	Node* temp  = head;
	while (temp != NULL){
		printf("%d--->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main (){
	Node* head = NULL;
	// them 1 phan tu vao dau danh sach
	printf("Moi ban nhap vao phan tu dau : ");
	int value;
	scanf("%d", &value);
	insertHead(&head,value);
	// in ra
	printf("Danh sach ne \n");
	printList(head);
	
	do{
		printf("==================MENU=================\n");
		printf("1. them 1 phan tu vao dau. \n");
		printf("2. xem danh sach. \n");
		printf("3.  them 1 phan tu vao cuoi. \n");
		printf("4.  them 1 phan tu vao vi tri ngau nhien. \n");
		printf("5. thoat. \n");
		printf("chon: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1:
//				them 1 phan tu vao dau danh sach
				printf("moi ban nhap vao pha tu dau: ");
				scanf("%d",&value);
				insertHead(&head,value);
				break;
			case 2:
//				in
				printf("danh sach: \n");
				printList(head);
				break;
			case 3:
//				them 1 phan tu vao cuoi danh sach
				printf("moi ban nhap vao phan tu cuoi: ");
				scanf("%d", &value);
				insertEnd(&head,value);
				break;
			case 4:
//				them 1 phan tu vao vi tri can them
				printf("moi ban nhap vao vi tri can them: ");
				int position;
				scanf("%d", &position);
				printf("moi ban nhap vao phan tu muon them : ");
				scanf("%d", &value);
				insertElement(&head,value,position);
				break;
			case 5:
				exit(0);
			default:
				printf("vui long chon lai: ");
		}
	}while(1==1);
	return 0;
}
