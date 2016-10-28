#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 Input: submit 2016 fall ents 689a$ 
 Output: submit 2016falen89
*/

//helper method to check if the character is already present in the buffer
int help(char a[], char b){
    int i=0;
    do{
        if(a[i]==b)
            return 1;
        i++;
    }while (a[i]!='\0');
    return 0;
}

int main(){
    char c,temp[200];
    int i=0,j;
    //input char by char from input and check for duplicates until '$'
    //Note : Char is read charcter by charcter and stored in buffer, for each character processing id done & stored and printed , when processing id one for the entire buffer
    do{
        c = getchar();
        if (c!='$'){
            j=help(temp,c);
            if(j==0)
                putchar(c);
            temp[i] =c;
            i++;
        }
    }while(c!='$');
    return 0;
}
