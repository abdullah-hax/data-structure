/* 

    Edge case :
            => Only 1 node exist
            => 1st position
            => last position
            => invalid input from user

*/




#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* del_first(struct node *head){
    if(head == NULL){
        printf("List is already empty");
        return NULL;
    }

    // singly delFirst e 1 node er kno impact nai.
    struct node *temp = NULL;
    temp = head;
    head = head -> link;

    free(temp);   // free() use krle temp jei node k point krse se free hoi but temp = NULL hoina. 

    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }

    return head;

}

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 2;
    temp->link = NULL;

    head->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 3;
    temp->link = NULL;
    head->link->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 4;
    temp->link = NULL;
    head->link->link->link = temp;


    head = del_first(head);
    return 0;
}



/* 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* del_first(struct node *head){
    if(head == NULL){
        printf("List is already empty");
        return head;
    }

    // singly delFirst e 1 node er kno impact nai.
    struct node *temp = NULL;
    temp = head;
    head = head -> link;

    free(temp);   // free() use krle temp jei node k point krse se free hoi but temp = NULL hoina. 

    return head;
}

void printList(struct node *head){
     while(head != NULL){
        printf("%d ", head->data);
        head = head->link;
    }
}

int main() {
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 2;
    temp->link = NULL;

    head->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 3;
    temp->link = NULL;
    head->link->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 4;
    temp->link = NULL;
    head->link->link->link = temp;

    printList(head);
    printf("\nAfter deleting : ");

    head = del_first(head);

    printList(head);

    return 0;
}

*/