#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    IncrementAll
//Description:      Increase each element by 1
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

void IncrementAll(PNODE first)
{
    while(first != NULL)
    {
        first -> data = first -> data + 1;
        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,45);
    InsertFirst(&head,89);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,78);
    InsertFirst(&head,17);

    Display(head);

    IncrementAll(head);

    printf("Updated LL:\n");
    Display(head);

    return 0;
}