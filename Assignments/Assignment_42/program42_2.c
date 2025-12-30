#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    SearchLastOcc
//Description:      Return index of last occurence of the element
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

int SearchLastOcc(PNODE first,int no)
{
    int iCnt = 0 , iIndex = -1;

    iCnt =1;

    while(first != NULL)
    {
        if(first -> data == no)
        {
            iIndex = iCnt;
        }
        first = first -> next;
        iCnt++;
    }

    if(iIndex == -1)
    {
        printf("Node not found");
        return -1;
    }

    return iIndex;
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

    iRet = SearchLastOcc(head,30);
    printf("Last occurered index:%d",iRet);

    return 0;
}