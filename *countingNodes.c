#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void nodeCount(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty");
        return; // immediately stop hoye jabe. return 0 dile complile time error hbe, karon 0 hlo int
    }

    struct node *ptr = NULL;
    ptr = head;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }

    printf("\n\nnumber of nodes : %d", count);
}

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

    nodeCount(head);

    return 0;
}

/*

    ptr -> link = 1st node er link k point krche
    ptr -> link -> link = 2nd node er link k point krche
    ptr -> link -> link -> link = 3rd node link k point krche

    ptr -> data = 1st node er data k point krche
    ptr -> link -> data = 2nd node er data k point krche
    ptr -> link -> link -> data = 3rd node er data k point krche

*/

/*

    difference :
        ptr != NULL;      =>  point -> check -> execute, check kore NULL pele execute krbena.
        ptr->link != NULL  => point -> porerta check -> execute, check kore NULL pele execute krbena.

        mone rakar jnno sonkepe eta bola jai :
            ptr != NULl         => 3rd node cross kore 4th node(NULL) e cole jai , tai 3ta execute kore
            ptr -> link != NULL => 3rd prjnto ashe , tai 2 ta execute kore


*/