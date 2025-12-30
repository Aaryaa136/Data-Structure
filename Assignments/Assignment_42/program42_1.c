#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    SearchFirstOcc
//Description:      Return index of first occurence of the element
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

int SearchFirstOcc(PNODE first,int no)
{
    int iIndex = 0;

    iIndex =1;

    while(first != NULL)
    {
        if(first -> data == no)
        {
            return iIndex;
        }
        first = first -> next;
        iIndex++;
    }

    printf("Node not found");
    return -1;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,70);
    InsertFirst(&head,30);
    InsertFirst(&head,50);
    InsertFirst(&head,40);
    InsertFirst(&head,30);
    InsertFirst(&head,20);
    InsertFirst(&head,10);

    iRet = SearchFirstOcc(head,30);
    printf("First occurered index of a node is:%d",iRet);

    return 0;
}