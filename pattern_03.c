#include <stdio.h>
int main()
{
    int i=0;
    int number;
    printf("enter the number of rows: ");
    scanf("%d",&number);
    for (int row=0;row<number;row++)
    {
        printf("%d ",i+1);
        for (int col=0;col<=row;col++)
        {
            printf("%c ",65+i);
            
        }
        printf("\n");
        i++;
    }
}