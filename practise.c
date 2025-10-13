#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *delFirst(struct node *head, int pos){
    if(head == NULL){
        printf("empty");
        return NULL;
    }

    struct node *current = head;

    if(head->next == NULL){
        free(head);
        return NULL;
    }

    // case 1 : delete at pos 1
    if(pos == 1){
        head = head->next;
        if(head->next != NULL){   // case 1a : only 1 node
            head->prev = NULL;
        }

        free(current);
        return head;
    }

    // case 2 : delete at onother pos
    while(pos > 1){
        current = current->next;
        pos--;
    }

    current->prev->next = current->next;
    if(current->next != NULL){     // case 2a : last pos
        current->next->prev = current->prev;
    }

    free(current);
   
    return head;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 1;
    head->next = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 2;
    temp->next = NULL;

    head->next = temp;
    temp->prev = head;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 3;
    temp->next = NULL;

    head->next->next = temp;
    temp->prev = head->next;

    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = 4;
    temp->next = NULL;

    head->next->next->next = temp;
    temp->prev = head->next->next;

    printList(head);
    printf("\nAfter deleting : ");

    head = delFirst(head, 1);

    printList(head);

}