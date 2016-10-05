#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
void main()
{
        int a,b,c;
        int low,high,mid;
        printf("\n Input:");
        scanf("%d %d %d",&a,&b,&c);
        low = min(min(a,b),c);
        high = max(max(a,b),c);
        mid = a+b+c-low-high;
        printf("%d %d %d",high,mid,low);
}
