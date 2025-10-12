/* 

    delFirst er khetrre must head k return krte hoi
    but delLast e retrun na krleo problem hoina .

    why ? cinta kore deko.

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data ;
    struct node *link;
};


struct node * delLast(struct node *head){
    if(head == NULL){
        printf("empty");
        return head;
    }

    // Case 1 : Only 1 node    // ptr->link->link thakar karone 1 node er case 'must' consider krte hbe.
    if(head->link == NULL){
        free(head);   // free() use krle head jei node k point krse se free hoi but head = NULL hoina. 
        return head;
    }

    // Case 2 : More than 1 node
    struct node *temp = head;
    while(temp->link->link != NULL){   // 1 node er khettre temp->link er link nai , tai compiler eta check krte gie segmantion fault dibe.
        temp = temp->link;
    }

    free(temp->link);

    temp->link = NULL;

    return head;
}

void printList(struct node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->link;
    }
}


int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *temp = malloc(sizeof(struct node));
    temp->data = 2;
    temp->link = NULL;

    head->link = temp;

    temp = malloc(sizeof(struct node));
    temp->data = 3;
    temp->link = NULL;

    head->link->link = temp;
    
    temp = malloc(sizeof(struct node));
    temp->data = 4;
    temp->link = NULL;

    head->link->link->link = temp;

    printList(head);
    printf("\nAfter deleting : ");

    head = delLast(head);

    printList(head);

}

