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


// Them node vao cuoi ds 
void appendNode(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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





// Xóa Node vi tri ng dung chon 
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }

    Node* temp = *head;

    // xoa node dau
    if (position == 0) {
        *head = temp->next;  // doi head thanh Node ke tiep
        free(temp);         
        return;
    }

    // Tim node trc vi tri can xoa
    Node* prev = NULL;
    for (int i = 0; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    // vi tri ngoai ds
    if (temp == NULL) {
        printf("Vvi tri ngoai ds.\n");
        return;
    }

    // Bo qua node vi tri chi dinh
    prev->next = temp->next;
    free(temp);  
}
int main(){
	Node* head = NULL;
	int n, value, position;

//    nhap so phan tu
    printf("Nhap so phan tu: ");
    scanf("%d", &n);


    // Nhap phan tu
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        appendNode(&head, value);
    }


	// in ra
	printf("Danh sach ne \n");
	printList(head);
	
	// vi tri can xoa
    printf("\n vi tri can xoa : ");
    scanf("%d", &position);

    // Xoa node o vi tri chi dinh
    deleteAtPosition(&head, position);


    printf("\nDanh sau khi xoa vi tri %d:\n", position);
    printList(head);
	return 0;
}
