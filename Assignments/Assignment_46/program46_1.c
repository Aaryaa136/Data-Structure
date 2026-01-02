#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayGreater
//Description:      Display elements greater then X
//Input:            Integer
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

void DisplayGreater(PNODE first , int x)
{
    int iSize = 0;
    iSize = Count(first);
    
    int iCnt = 0;

    for(iCnt = 1 ; iCnt <= iSize ; iCnt++)
    {
        if(first -> data > x)
        {
            printf("%d\t",first->data);
        }
        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    int iValue = 0;

    InsertFirst(&head,45);
    InsertFirst(&head,89);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,78);
    InsertFirst(&head,17);

    Display(head);

    printf("Enter number:");
    scanf("%d",&iValue);

    printf("Numbers greater then %d:\n",iValue);

    DisplayGreater(head,iValue);

    return 0;
}