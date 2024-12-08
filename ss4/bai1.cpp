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


// Hàm tao danh sach lien ket 
Node* createLinkedList(int n) {
    if (n <= 0) return NULL; 

    Node* head = NULL;       //con tro dau 
    Node* tail = NULL;       //con tro cuoi  

    for (int i = 0; i < n; i++) {
        int value;
        printf("nhap gia tri cho phan tu  %d: ", i + 1);
        scanf("%d", &value);

        Node* newNode = createNode(value); //tao node moi  
        if (head == NULL) {
            
            head = newNode;
        } else {
            // Gan Node moi vao cuoi danh sach
            tail->next = newNode;
        }
        tail = newNode; // Di chuyen con tro tail den Node moi
    }

    return head; 
}

// duyet danh sach lien ket 
void printLinkedList(Node* head) {
    Node* current = head; 
    printf("Danh sach lien ket: ");
    while (current != NULL) {
        printf("%d -> ", current->data); // In gia tri Node hien tai
        current = current->next;        // Di chuyen 
    }
    printf("NULL\n");
}

// Ham giai phong bo nho 
void freeLinkedList(Node* head) {
    Node* current = head; 
    while (current != NULL) {
        Node* temp = current; // Luu node hien tai 
        current = current->next; 
        free(temp); 
    }
}

int main(){
	int n;
    printf("nhap so luong phan tu: ");
    scanf("%d", &n);

    Node* head = createLinkedList(n); // tao danh sach lien ket
    printLinkedList(head);            // In danh sach
    freeLinkedList(head);             // Giai phóng bo nho 

    return 0;
} 
