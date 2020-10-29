#include <stdio.h>
#include <conio.h>

#define max 5
static int queue[max];
int front = -1;
int rear = -1;

void insert(int x)
{
    queue[++rear] = x;
    
    if (front == -1)
        front = 0;
}
    
int Remove()
{
    int val;
    val = queue[front];
    
    if (front==rear && rear==max-1)
        front = rear = -1;
    
    else
        front ++;
    
    return (val);
}

void view()
{
    int i;
    
    if (front == -1)
        printf("\n Queue Empty \n");
    
    else
    {
        printf("\n Front-->");
        
        for(i=front; i<=rear; i++)
            printf("%4d", queue[i]);
        
        printf(" <--Rear\n");
    }
}

int main()
{
    int ch= 0,val;

   
    while(ch != 4)
    {
        printf("\n QUEUE OPERATION \n");
        printf("\n1.INSERT ");
        printf("\n2.DELETE ");
        printf("\n3.VIEW ");
        printf("\n4.QUIT\n");
        printf("Enter Choice : ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            {
                if(rear < max-1)
                {
                    printf("\n Enter element to be inserted : ");
                    scanf("%d", &val);
                    insert(val);
                }
                else
                    printf("\n Queue Full \n");
                
                break;
            }
            
            case 2:
            {
                if(front == -1)
                    printf("\n Queue Empty \n");
                else
                {
                    val = Remove();
                    printf("\n Element deleted : %d \n", val);
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
                exit(0);
            }
                
            default:
                printf("\n Invalid Choice \n");
        }
    }
    getch();
    return 0;
}