#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    ReplaceNegative
//Description:      Replace negative values with zero
//Author:           Aaryaa Patil
//Date:             31/12/25
//
//////////////////////////////////////////////////////////

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn -> next = *first;
        *first = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ", first -> data);
        first = first -> next;
    }
    printf("NULL\n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }

    return iCount;
}

void ReplaceNegative(PNODE first)
{
    while(first != NULL)
    {
        if(first -> data < 0)
        {
            first -> data = 0;
        }
        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,45);
    InsertFirst(&head,-89);
    InsertFirst(&head,6);
    InsertFirst(&head,-56);
    InsertFirst(&head,78);
    InsertFirst(&head,17);

    Display(head);

    ReplaceNegative(head);

    printf("Replaced ll:\n");
    Display(head);

    return 0;
}