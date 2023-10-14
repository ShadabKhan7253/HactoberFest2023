#include <Stdio.h>
#include <conio.h>
#include <stdlib.h>
#define NULL 0

struct Stack
{
    int data;
    struct Stack *next;
};

struct Stack *top=NULL;

void push()
{
    struct Stack *pnode;

    pnode=(struct Stack*)malloc(sizeof(struct Stack));
    if (pnode==NULL)
        printf("\nMemory Overflow, cannot insert node!");
    else
    {
        // I have the space and i can push the "Elements"
        printf("\nEnter the element to be pushed: ");
        scanf("%d", &pnode->data);
        pnode->next=top;
        top=pnode;

        printf("\nNode Inserted!");
    }
}

void pop()
{
    struct Stack *current;
    if (top==NULL)
        printf("\nStack Underflow, cannot pop!");
        
    else
    {
        current=top;
        top=top->next;
        printf("\nDeleted Data %d ",current->data);
        free(current);
    }
}

void stackTop()
{
    if (top==NULL)
        printf("\nStack is Empty, so no top element!");
    else
        printf("Top most element is %d ",top->data);
}

void show()
{
    struct Stack *current;
    if (top==NULL)
        printf("\nNothing to show, as stack is empty");
    else
    {
        current=top;
        printf("\nStack element from top: ");
        
        while(current!=NULL)
        {
            printf("%d ",current->data);
            current=current->next;
        }

    }
}

void main()
{
    int ch, element;

    while (1)
    {
        printf("\n-----------------Menu---------------");
        printf("\n1. Push \n2. Pop \n3. StackTop \n4. Show \n5. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            stackTop();
            break;
        case 4:
            show();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice");
        } // End of Switch
    }     // End of While
} // End of Main
