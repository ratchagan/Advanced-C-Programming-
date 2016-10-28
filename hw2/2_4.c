//For any given array with length n, the function finds the largest number in the array

int foo(int A[], int n){
    int large =-1;
    
    if (n == 1 )
        return *A;
    else{
        for (int i =0; i <n;i++){
            if (A[i]>A[i+1]&& A[i]>large)
                large = A[i];
            if(A[n-1]> large)
                large = A[n-1];
        }
        return large;
    }
}
