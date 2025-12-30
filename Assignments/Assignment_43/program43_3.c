#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    AdditionEven
//Description:      Add even elements of node
//Input:            Integer
//Output:           Integer
//Author:           Aaryaa Patil
//Date:             22/12/25
//
//////////////////////////////////////////////////////////

struct node 
{
    int data;
    struct node* next;
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

    if((*first) == NULL)
    {
        (*first) = newn;
    }
    else
    {
        newn -> next = (*first);
        (*first) = newn;
    }
}

int AdditionEven(PNODE first)
{
    int iSum = 0;

    while(first != NULL)
    {
        if(first -> data % 2 == 0)
        {
            iSum = iSum + first->data;
        }
        first = first -> next;
    }

    return iSum;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,41);
    InsertFirst(&head,32);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    iRet = AdditionEven(head);
    printf("Addition of even nodes is:%d",iRet);

    return 0;
}