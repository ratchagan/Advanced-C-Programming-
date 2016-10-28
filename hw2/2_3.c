/*
 int foo(int A[], int n) { int res = 0, i = n-1;
 for (; i>=0; i--)
 res += A[i];
 return res; }
 */
// with recursion
int foo(int A[],int n){
    if(n>0)
        return A[n-1] +foo(A,n-1);
    else
        return 0;
}
