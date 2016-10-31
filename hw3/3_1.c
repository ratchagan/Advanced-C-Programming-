#include <stdio.h>
#include <stdlib.h>

#define Trial 100
#define Range 99

void bubble_sort(int a[], int n, int *copy, int *comparison )
{ int current, next, temp;
    
    for (current = 0; current < n; current++)
        for (next = current + 1; next < n; next ++)
        { (*comparison)++;
            if (a[current] > a[next])
            { temp = a[current];
                a[current] = a[next];
                a[next] = temp;
                *copy += 3;
            }
        }
    
}


//Implementation of insertion_sort
void insertion_sort(int a[], int n, int *copy,int *comparison){
    int j,i,key;
    //j starts from the 2nd element
    for(j = 1; j < n; j++){
        key = a[j];
        //insert key into sorted sequence A[1..j-1]
        i = j -1;
        (*comparison)++;
        while(i >-1 && a[i]>key){
            a[i+1] = a[i];
            i=i-1;
            *copy +=1;
        }a[i+1]=key;
        *copy+=1;
    }
}

void counting_sort(int a[],int b[], int n, int *copy,int *comparison){
    
    int c[Range+1],i,j;
    
    for(i=0;i<=Range;i++)
        c[i]=0;
    for(j=1;j<=n;j++)
        c[a[j]]= c[a[j]]+1;
    for(i=1;i<=Range;i++)
        c[i]=c[i]+c[i-1];
    for(j=n;j>=1;j--){
        b[c[a[j]]]=a[j];
        c[a[j]]=c[a[j]]-1;
        *copy+=1;
    }
    
}



void q_sort(int *first, int *last, int *copy, int *comparison)
{ int *left = first;
    int *right = last;
    int pivot, tmp;
    
    pivot = *(left + (right - left) / 2 );
    
    while (left <= right)
    { (*comparison)++;
        while (*left < pivot)
        { left++; (*comparison)++;}
        (*comparison)++;
        while (*right > pivot)
        {  right--; (*comparison)++;}
        if (left <= right)
        { tmp = *left;
            *left = *right;
            *right = tmp;
            *copy +=3;
            left++;
            right--;
        }
    }
    
    if (first < right)
        q_sort (first, right, copy, comparison);
    if (left < last)
        q_sort (left, last, copy, comparison);
}






void show(int a[], int n)
{ int i;
    for (i=0; i<n; i++)
        printf("%3d: %d\n", i, a[i]);
}

//void show_b(int b[], int n)
//{ int i;
//    for (i=1; i<n+1; i++)
//        printf("%3d: %d\n", i, b[i]);
//}

int main(int argc, char *argv[])
{ int *a, seed;
    int *b;// pointer to the random array
    int size, min = 0, max = 99;  // default range of random values
    int copy = 0, comparison = 0; // number of copies and comparisons for sorting
    float Tcopy = 0, Tcomp = 0;
    int i;
    
    if (argc != 2 && argc != 4)
    { printf("Usage: \nGenerate k random numbers between 0 and 99:\t a.out k\nGenerate k random numbers between a and b:\t a.out k a b\n");
        exit(0);
    }
    
    size = atoi (argv[1]);
    if (size <= 0)
    { printf("Cannot generate %d random numbers.\n", size);
        exit(0);
    }
    
    if (argc == 4)
    { min = atoi (argv[2]);
        max = atoi (argv[3]);
        if (min >= max)
        { printf("invalid range [%d, %d]\n", min, max);
            exit(0);
        }
    }
    
    a = (int *) malloc (size*sizeof(int));
    b = (int *) malloc (size*sizeof(int));
    if (a == NULL)
    { printf("Not enough memory for %d random numbers.\n", size);
        exit(0);
    }
    
    for (seed = 1; seed <=Trial; seed++)
    { srand(seed);
        //a[0]=0;
        b[0]=0;
        for (i=0; i<size; i++)
            a[i] = rand()%(max-min+1) + min;
        printf("Original array:\n");
        show(a,size);
        
        //bubble_sort(a,size, &copy, &comparison);
        insertion_sort(a,size, &copy, &comparison);
        //counting_sort(a,b,size, &copy, &comparison);
        printf("Sorted array:\n");
        show(a,size);
        
        Tcopy += copy;
        Tcomp += comparison;
        
        printf("Seed = %d, copy data %d times, compare data %d times.\n", seed, copy, comparison);
        copy = 0;
        comparison = 0;
    }
    printf("Average: copy %.2f times, compare %.2f times.\n", Tcopy/Trial, Tcomp/Trial);
    
    return 0;
}
