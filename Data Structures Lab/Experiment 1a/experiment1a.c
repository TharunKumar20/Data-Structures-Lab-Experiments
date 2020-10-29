#include<stdio.h>
#include<conio.h>

#define max 5
static int stack[max];
int top = -1;

void push(int x)
{
   stack[++top] = x;
}

int pop()
{
    return (stack[top--]);
}

void view()
{
    int i;
    if (top < 0)
            printf("\n Stack Empty \n");    
    else
    {
        printf("\n Top-->");
        for(i=top; i>=0; i--)
        {
            printf("%4d", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch, val;
    do
    {
    printf("\n STACK OPERATION \n");
    printf("\n1.PUSH ");
    printf("\n2.POP ");
    printf("\n3.VIEW ");
    printf("\n4.QUIT \n");
    printf("Enter Choice : ");
    scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                if(top < max-1)
                {
                    printf("\nEnter Stack element : ");
                    scanf("%d", &val);
                    push(val);
                }
                else
                    printf("\n Stack Overflow \n");
                
                break;   
                
            }

            case 2:
            {    
                if(top < 0)
                    printf("\n Stack Underflow \n");
                else
                {
                    val = pop();
                    printf("\n Popped element is %d\n", val);
                }
            break;
            }

            case 3:
            {
                view();
                break;
            }

            case 4:  
            {
                printf("Exiting");
                exit(0);
            }
            
            default:
            {
                printf("\n Invalid Choice \n");
            }
        } 
    }while(ch != 4);
    getch();
    return 0;
}