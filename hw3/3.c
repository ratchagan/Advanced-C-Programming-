#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substring(char *string,int *comparison);
void substring_method1(char *string, int *comparison);

int main(){
    
    int i=0,comparison=0;
     float Tcomp = 0;
    char c,temp[200];
    char *string;
    do{
        c= getchar();
        if(c!='\n'){
            temp[i]=c;
            i++;
        }}while(c!='\n');
    //substring_method1(temp,&comparison);
    substring(temp,&comparison);
    printf("compare data %d times.\n", comparison);
    comparison =0;
    return 0;
}

void substring_method1(char *string,int *comparison){
    int n,k,i,j,found,m,count;
    n = strlen(string);
    //break the string into 2 halfs
    k = n /2;
    i=0,j=k,found=-1;
    
    while(i<k && j<n){
        (*comparison)++;
        //check the 1st element with middle ellement in the string
        if(string[i]==string[j]){
            //if they are equal, the comparison should go until the last character in the string
            while(j<n){
                (*comparison)++;
                //after the characters match, check for the entire A-A pattern to be equal
                if(string[i]==string[j])
                    {count = j;
                        i++;
                        j++;
                    }
                //if there does not exits an A B A pattern, assign an counter dound =-1
                else{
                    found=-1;
                    break;
                }
            found =1;}
        }
        else{
            j++;
        }
        }
    // print the A-B pattern
    if(found==1){
        for(m=0;m<=n-i-1;m++)
            putchar(string[m]);
    }
}

//output:
//Tony’s sister helps Tony
//Tony’s sister helps compare data 14 times.


//function using window method to find ABA pattern
//this method will take less comparisons then the previous method
void substring(char *string, int *comparison){
    int i,j=0,n;
    n = strlen(string);
    int found, ans = -1;
    
    for(i =0;i<n/2;i++){
        found = 1;
        for(j=0;j<=i;j++){
            (*comparison)++;
            if(string[i-j]!=string[n-1-j])
            {
                found = 0;
                break;
            }
        }
        if(found == 1){
            ans = i;
            break;
        }
    }
    if(ans != -1)
    {
        for(i=0;i<=n-j-1;i++)
            putchar(string[i]);
    }
}

//output:
//Tony’s sister helps Tony
//Tony’s sister helps compare data 7 times.

