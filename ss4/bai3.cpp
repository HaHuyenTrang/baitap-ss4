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


// Them Node vao cuoi danh sach 
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

// xoa phan tu dau tien 
void deleteFirstNode(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
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
int main(){
Node* head = NULL;
    int n, value;

    // Nhap so phan tu 
    printf("Nhap so phan tu (0 <= n <= 1000): ");
    scanf("%d", &n);

    // Nhap cac phan tu 
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu  %d: ", i + 1);
        scanf("%d", &value);
        appendNode(&head, value);
    }

    // Xoa phan tu 
    deleteFirstNode(&head);

	// in ra
	printf("Danh sach ne \n");
	printList(head);
	return 0;
}
