#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    DisplayPrime
//Description:      Display prime numbers
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

void PrimeDigits(PNODE first)
{
    while(first != NULL)   
    {
        int temp = first->data;

        while(temp != 0)   
        {
            int digit = temp % 10;

            if(digit == 2 || digit == 3 || digit == 5 || digit == 7)
            {
                printf("%d ", digit);
            }

            temp = temp / 10;
        }

        printf("\n");
        first = first->next; 
    }
}


int main()
{
    PNODE head = NULL;

    InsertFirst(&head,45);
    InsertFirst(&head,89);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,21);
    InsertFirst(&head,17);

    Display(head);

    printf("Prime nodes are:\n");

    DisplayPrime(head);

    return 0;
}