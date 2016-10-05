#include <stdio.h>


void print_digits(int num)
{
        if (num >10)
        {
                print_digits(num/10);
                printf(" ");
        }
        printf("%d", num%10);
}

int main()
{
        int input,result=0;

        printf("Input: ");
        scanf("%d",&input);

        printf("Output: " );
        while(input>0)
        {
                result = result *10;
        result = result + input%10;
        input = input/10;
        }
        print_digits(result);
        return 0;

        
}
