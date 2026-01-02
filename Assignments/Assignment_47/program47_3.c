#include<stdio.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////
//
//Function Name:    SumDigits
//Description:      Sum of digits of each node
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

void SumDigits(PNODE first)
{
    int iSum = 0 , iCount = 0;
    int temp = 0;

    while(first != NULL)
    {
        temp = first -> data;
        iSum = 0;

        if(temp < 0)
        {
            temp = -temp;
        }

        if(temp == 0)
        {
            iSum = 0;
        }
        else
        {
            while(temp != 0)
            {
                iSum = iSum + (temp % 10);   //add last digit
                temp = temp / 10;            //remove last digit
            }
        }

        printf("Sum digits of %d is :%d\n",first->data,iSum);

        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,45);
    InsertFirst(&head,891);
    InsertFirst(&head,6);
    InsertFirst(&head,56);
    InsertFirst(&head,7809);
    InsertFirst(&head,17);

    Display(head);

    printf("Digits of each node is:\n");

    SumDigits(head);

    return 0;
}