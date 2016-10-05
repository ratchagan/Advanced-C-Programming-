#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void reverseWord(char *word, int size){
int i;
for( i = size - 1; i >= 0; i-- ){
printf("%c", word[i]);
}
}
bool check(char c){
bool cond1 = (c >= '0' && c <= '9');
bool cond2 = (c >= 'a' && c <= 'z');
bool cond3 = (c >= 'A' && c <= 'Z');
return !(cond1 || cond2 || cond3);
}

int main( int argc, char *argv[] ) {
        int src,des, i = 0;
        char ch, word[20];
        src = open( argv[1], O_RDONLY );
        des = open( argv[2], O_CREAT|O_RDWR, 0640 );
        dup2(src, STDIN_FILENO);
        dup2(des, STDOUT_FILENO);
        while( scanf( "%c", &ch ) != EOF ){
        if( check(ch) ){
                reverseWord( word, i );
                printf( "%c", ch );
                i = 0;
        }
        else if( i == 20 ){
                reverseWord( word, i );
                i = 0;
        }
        else{
                word[i++] = ch;
        }
        }
        close(src);
        close(des);
