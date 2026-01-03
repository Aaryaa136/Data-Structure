#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayOddPosition
//Description:      Display elements at odd positions
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

void DisplayOddPosition(PNODE first)
{
    int iPos = 1;

    while(first != NULL)
    {
        if(iPos % 2 != 0)
        {
            printf("%d\n",first -> data);
        }

        first = first -> next;
        iPos++;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,4);
    InsertFirst(&head,9);
    InsertFirst(&head,13);
    InsertFirst(&head,2);
    InsertFirst(&head,15);
    InsertFirst(&head,100);
    InsertFirst(&head,6);

    Display(head);

    printf("Odd positions nodes:\n");
    DisplayOddPosition(head);
   
    return 0;
}