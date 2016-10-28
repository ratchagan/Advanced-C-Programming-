   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   
   void substring(char *string);
   
   int main(){
       int i=0;
   char c,temp[200];
       char *string;
   do{
   c= getchar();
       if(c!='\n'){
           temp[i]=c;
           i++;
       }}while(c!='\n');
   substring(temp);
   return 0;
   }
   
   void substring(char *string){
   int i,j=0,n;
   n = strlen(string);
   int found, ans = -1;
   
   for(i =0;i<n/2;i++){
       found = 1;
       for(j=0;j<=i;j++){
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
