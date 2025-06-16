#include <stdio.h>
int main()
{
    int number;
    printf("ENTER ROWS: ");
    scanf("%d",&number);

    int i=number-1;
    int n=1;
    for (int row=0;row<number;row++)
    {
    
        for (int col=0;col<=number-row-1;col++)
        {
            printf("%c ",65+i);
            i--;
        }
        printf("\n");
        i=number-1-n;
        n++;
    }
}