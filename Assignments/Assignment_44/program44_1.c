#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//////////////////////////////////////////////////////////
//
//Function Name:    Search
//Description:      Search whether element present in LL
//Input:            Integer
//Output:           Boolean
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

bool Search(PNODE first , int no)
{
    int iCnt = 0;
    int iSize = 0;

    iSize = Count(first);

    for(iCnt = 1 ; iCnt <= iSize ; iCnt++)
    {
        if(first->data == no)
        {
            return true;
        }
        first = first -> next;
    }

    return false;
}

int main()
{
    PNODE head = NULL;
    int iValue = 0;
    bool bRet = false;

    InsertFirst(&head,34);
    InsertFirst(&head,11);
    InsertFirst(&head,7);
    InsertFirst(&head,60);
    InsertFirst(&head,40);

    Display(head);

    printf("Enter element to be searched:");
    scanf("%d",&iValue);

    bRet = Search(head,iValue);

    if(bRet == true)
    {
        printf("Node found");
    }
    else
    {
        printf("Node is not present in LL");
    }
    
    return 0;
}