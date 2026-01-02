#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    CountPrime
//Description:      Count prime numbers
//Output:           Boolean
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

int CountPrime(PNODE first)
{
    int iCount = 0;

    while(first != NULL)   
    {
        int temp = first->data;

        while(temp != 0)   
        {
            int digit = temp % 10;

            if(digit == 2 || digit == 3 || digit == 5 || digit == 7)
            {
                iCount++;
            }

            temp = temp / 10;
        }

        first = first->next; 
    }

    return iCount;
}


int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head,45);
    InsertFirst(&head,89);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,21);
    InsertFirst(&head,17);

    Display(head);

    CountPrime(head);
    printf("Number of prime nodes:%d",iRet);
    
    return 0;
}