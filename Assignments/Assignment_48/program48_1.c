#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    ReplaceEven
//Description:      Replace even numbers with 0
//Author:           Aaryaa Patil
//Date:             2/1/26
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
    PNODE temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        printf("| %d | ->",temp -> data);
        temp = temp -> next;
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

void ReplaceEven(PNODE first)
{
    int iSize = 0 , iCnt = 0;
    iSize = Count(first);

    for(iCnt = 1 ; iCnt <= iSize ; iCnt++)
    {
        if(first -> data % 2 == 0)
        {
            first -> data = 0;
        }
        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,48);
    InsertFirst(&head,99);
    InsertFirst(&head,74);
    InsertFirst(&head,23);
    InsertFirst(&head,15);
    InsertFirst(&head,100);
    InsertFirst(&head,26);

    Display(head);

    printf("Replaced nodes:\n");
    ReplaceEven(head);
    Display(head);
    return 0;
}