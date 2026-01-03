#include<stdio.h>
#include<stdlib.h>

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
    PNODE temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        printf("| %d | -> ",temp->data);
        temp = temp -> next;
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

void DisplayAlternate(PNODE first)
{
    int iPos = 0;
    iPos = 1;

    while(first != NULL)
    {
        if(iPos % 2 != 0)
        {
            printf("%d\n",first->data);
        }

        iPos++;
        first = first -> next;
    }
}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,21);
    InsertFirst(&head,45);
    InsertFirst(&head,9);
    InsertFirst(&head,84);
    InsertFirst(&head,63);
    InsertFirst(&head,16);

    Display(head);

    printf("Altenate nodes:\n");
    DisplayAlternate(head);
    
    return 0;
}