#include <stdio.h>
#include <conio.h>

void create();
void insert();
void search();
void deletion();
void display();

int i, e, n, pos;
static int b[50];

int main()
{
    int ch;
    char g = 'y';
    create();
    
    do
    {
        printf("\n List Operations");
        printf("\n 1.Insert \n 2.Deletion \n 3.Search \n 4.Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
       
        switch(ch)
        {
             case 1:
                insert();
                break;
            
            case 2:
                deletion();
                break;
               
            case 3:
                search();
                break;
            
            case 4:
                printf("\nExiting");
                exit(0);
            
            default:
                printf("\n Enter the correct choice:");
        }
       
        printf("\n Do you want to continue(y/n) : ");
        fflush(stdin);
        scanf("\n %c",&g);
    
    } while(g=='y' || g=='Y');
    
    getch();
    return 0;
}

void create()
{
    printf("\n Enter the number of elements:");
    scanf("%d",&n);
    printf("\n Enter list elements: ");
    
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
}

void deletion()
{
    
    printf("\n Enter the position you want to delete: ");
    scanf("%d", &pos);
    
    if(pos >= n)
        printf("\n Invalid location");
    
    else
    {
        for(i=pos+1; i<n; i++)
        b[i-1] = b[i];
        n--;
        printf("\n List elements after deletion");
        display();
    }

}

void search()
{
   
    int flag = 0;
    printf("\n Enter the element to be searched: ");
    scanf("%d", &e);
    
    for(i=0; i<n; i++)
    {
        if(b[i] == e)
        {
            flag = 1;
            printf("\n Element is in the %d position", i);
            break;
        }
    }
    
    if(flag == 0)
        printf("\n Value %d is not in the list", e);

}

void insert()
{
    
    printf("\n Enter the position you need to insert: ");
    scanf("%d", &pos);
    
    if(pos >= n)
        printf("\n Invalid location");
    
    else
    {
        ++n;
        for(i=n; i>pos; i--)
        b[i] = b[i-1];
        printf("\n Enter the element to insert: ");
        scanf("%d", &e);
        b[pos] = e;
    }
    
    printf("\n List after insertion:");
    display();
}

void display()
{
    
    for(i=0; i<n; i++)
    printf("\n %d", b[i]);

}