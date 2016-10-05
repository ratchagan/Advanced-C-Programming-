#include <stdio.h>
#include <stdlib.h>

void main()
{
    int ar[20],i,count=0,n=0,j;
    char c;
    printf("Enter the two arrays separated by enter key");
    while(c!='\n'){
        scanf("%d%c",&ar[i++],&c);
    }
    //input the 2nd array
    do{
        scanf("%d%c",&ar[i++],&c);
    }while(c!='\n');
    // count the number of array elements
    for(i=0;i<20;i++){
        if(ar[i]!='\0' && ar[i]<1000)
            count++;
    }
    n=count;//eleiminating the additional spaces
    int a;//temp
    for ( i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (ar[i] > ar[j])
            {
                a = ar[i];
                ar[i] = ar[j];
                ar[j] = a;
            }
        }
    }
    for (i = 0; i < n; ++i)
    {
        printf("%d ", ar[i]);
    }
    
}
