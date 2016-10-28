//the function converts decimal number into a binary number
void foo(int n){
    int remainder ;
    long binary = 0,i=1;
    if(n!=0){
    while (n!=0){
        remainder = n%2;
        n=n/2;
        binary = binary + (remainder*i);
        i=i*10;
    }printf("%d",binary);}
}