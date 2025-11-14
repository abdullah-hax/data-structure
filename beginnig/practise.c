#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *createList(struct node *head){
    int value;
    struct node *temp = NULL, *tail = NULL;

    while(scanf("%d", &value) && value != -1){
        temp = malloc(sizeof(struct node));

        if(temp == NULL){
            printf("faild");
            exit(1);
        }

        temp->data = value;
        temp->link = NULL;

        if(head == NULL){
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


int main(){
    struct node *head = NULL;
    head = createList(head);
    printList(head);
    
}