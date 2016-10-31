/* report the 4th element from the last in a singly linked list. For
 example, return 43 for the linked list whose data values are:
 30->9->43->20->18->28.
 Gang Qu
 */

#include <stdio.h>
#include <stdlib.h>

#define NEW(x) (x*)malloc(sizeof(x))

typedef int DATA;

typedef struct node
{ void * data;
    struct node * next;
} NODE;

typedef struct
{ long num;
    NODE * head;
    NODE * tail;
}ROOT;

NODE * make_node (void *data)
{ NODE * temp;
    temp = NEW(NODE);
    if (temp != NULL)
    { temp->data = data;
        temp->next = NULL;
    }
    return temp;
}

ROOT * make_root (void)
{ ROOT * temp;
    temp = NEW(ROOT);
    if (temp != NULL)
    { temp->num = 0;
        temp->head = NULL;
        temp->tail = NULL;
    }
    return temp;
}

void display_list(ROOT *r)
{ NODE * temp;
    
    if (r != NULL)
    { temp = r->head;
        do
        { printf("%3d ", *(DATA *)(temp->data));
            temp = temp->next;
        } while (temp != NULL);
    }
    printf("\n");
}

int insert_at_tail(ROOT *r, DATA *d)
{ NODE * temp;
    temp = make_node(d);
    
    if (temp == NULL) return -1;  // fail, cannot create new NODE
    
    if (r == NULL)
    { r = make_root();
        if (r == NULL) return -1;   // fail, cannot create ROOT
    }
    
    (r->num)++;
    
    if (r->num == 1)              // if previously the list is empty
        r->head = r->tail = temp;
    
    else
    { r->tail->next = temp;
        r->tail = temp;
    }
    
    return 0;
}

// To find from the head 
//NODE* four_last(ROOT *r){
//    NODE * temp;
//    int i = 1;
//    if(r!=NULL){
//        
//        temp = r->head;
//        //temp = r->tail;
//        while(i<4){
//            if(temp!=NULL){
//                temp= temp->next;
//                i++;}
//            else
//                return NULL;
//        }
//    }
//    return temp;
//}

NODE* four_last(ROOT *r){
    NODE *temp;
    int i =0;
    if(r!=NULL){
        temp = r->head;
        //Setting a counter to find if 4 elements exists in the linked list
        while(temp!=NULL ){
            i++;
            temp= temp->next;}
        //if 4 elements exists in the LL, then find the total elements in the list,
        //to find the position of the fourth element from the tail
    if(i>=4){
        temp = r->head;
        if(i==4){
            // if there are only 4 elements, return the 1st element
            return temp;
        }else{
            i=i-4;
            while(i!=0){
                //set the temp to the 4th element position
                temp = temp ->next;
                i--;
            }
            return temp;
        }
    }
    else{
        return NULL;
    }}
    return temp;
}


int main(void)
{ ROOT *root;   // a pointer to ROOT type
    DATA *data;   // a pointer points to type DATA (int)
    DATA d;
    int i;
    NODE *temp;
    
    root = make_root(); // see what happend when this line is deleted.
    
    for (i=0; i<6; i++)
    { data = NEW(DATA);
        d = 19 - 2*i;
        *data = d;
        
        // test the four_last() function
        temp = four_last(root);
        if (temp == NULL)
            printf("  Fourth from last node does not exist!\n");
        else
            printf("  Fourth from last node is %d\n", *(DATA *)(temp->data));
        
        insert_at_tail(root, data);
        printf("inserting %3d at the tail: ", d);
        display_list(root);
        
    }
    
    return 0;
}

