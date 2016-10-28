#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct Date {
    int month;
    int day;
};

struct NODE{
    struct Date *date;
    struct NODE *next;
    struct NODE *prev;
    
};

struct NODE* head;

struct schedule {
    struct NODE *first;
    struct NODE *last;
};

struct Date *insertDate(int M, int D){
    struct Date* d= (struct Date *)malloc(sizeof(struct Date));
    d->month=M;
    d->day=D;
    return d;
}

struct NODE *createNode(struct Date* d){
    struct NODE* n =(struct NODE *)malloc(sizeof(struct NODE));
    n->date=d;
    n->next=NULL;
    n->prev= NULL;
    return n;
}

struct schedule *createSchedule(struct NODE* n){
    struct schedule* s = (struct schedule *)malloc(sizeof(struct schedule));
    s->first=n;
    s->last=NULL;
    return s;
}


void insertSortedDate(struct schedule** head, struct schedule* new_schedule){
    
    struct schedule* current;
    
    if(*head == NULL || (*head)->first->date->month >= new_schedule->first->date->month ){
        new_schedule->first->next = *head;
        *head = new_schedule;
    }
    else{
        current = *head;
        while(current->first->next !=NULL &&
              current->first->next->date->month < new_schedule->first->date->month)
        {
            current = current->first->next;
        }
        new_schedule->first->next = current->first->next;
        current->first->next =new_schedule;
    }
    
}

void search(struct schedule** head, int m, int d ){
    struct schedule* current;
    current = *head;
    while(current !=NULL){
        if(current->first->date->day==d && current->first->date->month==m){
            printf(" Date is in the list");
            break;}
        else{
            current = current->first->next;
            
        }
    }
    printf("Date is not present in the list");
}


void print(struct schedule *head){
    struct schedule *temp = head;
    while(temp!=NULL){
        printf("%d",temp->first->date->month);
        temp =temp->first->next;
    }
}


int main( int argc, char *argv[]){
    
    int m,d,src;
    //FILE * fp;
    //fp = fopen("input.txt","r");

    struct schedule* head = NULL;
    struct Date *new_date;
    struct NODE *new_node;
    struct schedule *new_schedule;
    
    /*Reads the dates from the file in the format M D separated by space  */
    while( fscanf( fp,"%d %d", &m, &d ) !=EOF){
        new_date = insertDate(m,d);
        new_node = createNode(new_date);
        new_schedule = createSchedule(new_node);
        /*Dates are read and sorted, then inserted inside the linked list */
        insertSortedDate(&head,new_schedule);
    
   }
    fclose(fp);
    printf("Enter the day and month of the date to be searched:");
    scanf("%d %d",&m,&d);
    if((m<=12 && m >=1)&& (d>=1 && d<=31))
        search(&head,m,d);
    else
        printf("Enter a valid date");
    
}






