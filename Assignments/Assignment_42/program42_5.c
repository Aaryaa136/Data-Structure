#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    Maximum
//Description:      Returns maximum node from ll
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

int Minimum(PNODE first)
{
    int iMin = 0;

    if(first == NULL)
    {
        printf("Linked list is empty\n");
        return -1;   
    }

    iMin = first-> data;

    while(first != NULL)
    {
        if(iMin > first -> data)
        {
            iMin = first->data;
        }
        first = first -> next;
    }

    return iMin;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,640);
    InsertFirst(&head,240);
    InsertFirst(&head,20);
    InsertFirst(&head,230);
    InsertFirst(&head,110);

    iRet =Minimum(head);
    printf("Minimum node is:%d",iRet);

    return 0;
}