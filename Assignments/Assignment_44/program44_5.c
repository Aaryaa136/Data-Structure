#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayEven
//Description:      Display even elements from list
//Input:            Integer
//Author:           Aaryaa Patil
//Date:             30/12/25
//
//////////////////////////////////////////////////////////

struct  node
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
        newn -> next = (*first);
        *first = newn;
    }
}

void InsertLast(PPNODE first , int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = (*first);

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }   

        temp -> next = newn;
    }
}

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | ->",first -> data);
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

void DisplayEven(PNODE first)
{
    int iCnt = 0 , iCount = 0;
    int iSize = 0;

    iSize = Count(first);

    for(iCnt = 1 ; iCnt <= iSize ; iCnt++)
    {
        if(first->data % 2 == 0)
        {
           printf("%d\t",first->data);
        }
        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;
  
    InsertFirst(&head,34);
    InsertFirst(&head,58);
    InsertFirst(&head,7);
    InsertFirst(&head,60);
    InsertFirst(&head,11);
    InsertFirst(&head,180);
    InsertFirst(&head,99);

    Display(head);

    printf("Even nodes:\n");
    DisplayEven(head);

    return 0;
}