#include<stdio.h>
#include<stdlib.h>


//////////////////////////////////////////////////////////
//
//Function Name:    DisplayPrime
//Description:      Check each node is it prime number or not
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

void DisplayPrime(PNODE first)
{
    int isPrime = 0;
    int iCnt = 0, iNum = 0;

    while(first != NULL)
    {
        iNum = first->data;
        isPrime = 1;  

        if(iNum <= 1)
        {
            isPrime = 0;  
        }
        else
        {
            for(iCnt = 2; iCnt <= iNum / 2; iCnt++)
            {
                if(iNum % iCnt == 0)
                {
                    isPrime = 0;  
                    break;        
                }
            }
        }

        if(isPrime)
        {
            printf("%d is a prime number\n", iNum);
        }

        first = first->next;  
    }
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,89);
    InsertFirst(&head,22);
    InsertFirst(&head,41);
    InsertFirst(&head,17);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    DisplayPrime(head);

    return 0;
}