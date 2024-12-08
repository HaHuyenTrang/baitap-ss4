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


// Thêm Node vao cuoi ds 
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

// tim kiem phan tu  
int searchList(Node* head, int target) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == target) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
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
  	int n, value, target;

    // Nhap phan tu 
    printf("Nhap so phan tu  (0 <= n <= 1000): ");
    scanf("%d", &n);


    // Nhap cac phan tu 
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu  %d: ", i + 1);
        scanf("%d", &value);
        appendNode(&head, value);
    }

	// in ra
	printf("Danh sach ne \n");
	printList(head);
	
	
//	phan tu can tim 
    printf("\n nhap phan tu can tim: ");
    scanf("%d", &target);

    // tim kiem 
    int result = searchList(head, target);

    
    if (result != -1) {
        printf("Phan tu  %d o vi  tri (index): %d\n", target, result);
    } else {
        printf("Phan tu %d khong co trong danh sach.\n", target);
    }
	return 0;
}
