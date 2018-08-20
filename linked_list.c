#include <stdio.h>
#include <stdlib.h>

// Create a structure for Linked List
struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL; // starting point for the list 

//Insert an element into list
void insert(int data,int pos){
    //Node creation
    struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node));//or Node* temp1 = new Node();
    temp1 -> data = data;
    if(pos == 1){
       temp1 -> next = head; 
       head = temp1;
       return;
    }
    struct Node* temp2 = head;
    for(int i=0;i<pos-2;i++)
        temp2 = temp2 -> next;
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;
}

//Delete an element from the list
void Delete(int pos){
    struct Node* temp1 = head;
    if(pos == 1){
        head = temp1 -> next;
        free(temp1);
        return;
    }
    for (int i=0 ; i<pos-2 ; i++)
        temp1 = temp1 -> next;
    struct Node* temp2 = temp1 -> next;
    temp1 -> next = temp2 -> next;
    free(temp2);
}

//Reverse the list
void reverse(){
    struct Node *current, *prev, *next;
    prev = NULL;
    current = head;
    while(current != NULL){
        next = current -> next;
        current -> next = prev;
        prev = current ;
        current = next;
    }
    head = prev;
}

//Print the list
void print(void){
    struct Node* temp = head;
    printf("Elements in list : ");
    while(temp != NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
}

int main(void) {
    int choice,data,pos;
    char ch;
    print();
    do{
    printf("\n");
    printf("Select operation to perform : \n");
    printf("1. Insertion. \n");
    printf("2. Deletion. \n");
    printf("3. Reverse List \n");
    printf("4. Print List. \n");
    printf("5. Exit. \n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
	    case 1 :
	        printf("position of the element : ");
	        scanf("%d",&pos);//position for the element
	        printf("Data to be inserted at %d position : ",pos);
	        scanf("%d",&data);//data to be inserted in the node
	        insert(data,pos);
	        print();
	        break;
	    case 2 :
	        printf("Position of the element to be deleted : ");
	        scanf("%d",&pos);//position of the element to be deleted
	        Delete(pos);
	        print();
	        break;
	    case 3 :
	        reverse();
	        print();
	        break;
	    case 4 :
	        print();
	        break;
	    default:
	        exit(0);
	}
	printf("\nPerform other operations (Y/N) : ");
	getchar();
	ch = getchar();
    }while(ch == 'y');
return 0;
}
