#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    FirstOcc
//Description:      Return position of first occurenec
//Input:            Integer
//Output:           Integer
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

int FirstOccur(PNODE first , int no)
{
    int iCnt = 0 , iIndex = 0;
    int iSize = 0;

    iSize = Count(first);

    for(iCnt = 1 ; iCnt <= iSize ; iCnt++)
    {
        if(first->data == no)
        {
            iIndex = iCnt;
            break;
        }
        first = first -> next;
    }

    return iIndex;
}

int main()
{
    PNODE head = NULL;
    int iValue = 0;
    int iRet = 0; 
  
    InsertFirst(&head,34);
    InsertFirst(&head,58);
    InsertFirst(&head,11);
    InsertFirst(&head,60);
    InsertFirst(&head,11);
    InsertFirst(&head,180);
    InsertFirst(&head,99);

    Display(head);

    printf("Enter number:");
    scanf("%d",&iValue);

    iRet = FirstOccur(head,iValue);

    printf("First occurenec of %d is:%d",iValue,iRet);

    return 0;
}