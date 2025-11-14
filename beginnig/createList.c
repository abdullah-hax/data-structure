#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node* createList(struct node *head){
    struct node *tail = NULL, *temp = NULL;
    int value;

    printf("Enter numbers (press -1 to stop): ");

    while(scanf("%d", &value) && value != -1){
        temp = malloc(sizeof(struct node));
        if(temp == NULL){
            printf("Memory Allocation faild.");
            exit(1);
        }
        temp->data = value;
        temp->link = NULL;

        if(head == NULL){ // head NULL mane head kaok point krche na ortat kno node ekno create hoi nai
            head = temp;
            tail = temp;
        } else {
            tail->link = temp;
            tail = temp;
        }
    }

    return head;

}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    head = createList(head);
    printList(head);

  
    return 0;
}
