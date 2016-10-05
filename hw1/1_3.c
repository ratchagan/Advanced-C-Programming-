#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char numbers[1000];
    int size,i;
    //char *numbers;
    printf("Input: ");
    scanf("%s",&numbers);
    size = strlen(numbers);
    printf("Output: ");
    for (i=0; i=size;i++)
    {
        switch(numbers[i]) {
            case '1': printf("one "); break;
            case '2': printf("two "); break;

            case '3': printf("three "); break;
            case '4': printf("four "); break;
            case '5': printf("five "); break;
            case '6': printf("six "); break;
            case '7': printf("seven "); break;
            case '8': printf("eight "); break;
            case '9': printf("nine "); break;
            default: printf("zero");
        }
    }
    return 0;
}
