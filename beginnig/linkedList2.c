
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 20;
    temp->link = NULL;

    head->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 230;
    temp->link = NULL;

    head->link->link = temp;

    printf("first data : %d\nsecond data : %d\nthird data : %d", head->data, head->link->data, head->link->link->data);
    printf("\n");
    printf("Or,\n");
    printf("first data : %d\nsecond data : %d\nthird data : %d", head->data, head->link->data, temp->data);

    return 0;
}


/*

    head -> link = 1st node er link k point krche = 2nd node k point krche
    head -> link -> link = 2nd node er link k point krche = 3rd node k point krce
    head -> link -> link -> link = 3rd node link k point krche = Null k point krche(4th node thakle setak point krche.)

*/