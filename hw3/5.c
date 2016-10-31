/* rearrange a linked list around value x such that all the elements with
 data value less than x will be in front, followed by x, then values
 larger than x. For example, when x=18, 30->9->43->20->18->28 may
 become 9->18->30->43->20->28, or 9->18->43->20->28->30. Assume that
 there is no duplicate data values in the linked list and you can only
 use known linked list operations (delete and insert only).
 (Optional: try to minimize the number of linked list operations).
 
 Gang Qu
 PLEASE READ THE FUNCTION rearrange() CAREFULLY AND ONLY MAKE CHANGES IN THAT
 FUNCTION. YOU SHOULD BE ABLE TO GET THE PROBLEM SOLVED WITHOUT MAKING CHANGES
 TO ANYWHERE ELSE IN THIS CODE.
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
    
    if (&r != NULL)
    { temp = r->head;
        do
        { printf("%3d ", *(DATA *)(temp->data));
            temp = temp->next;
        } while (temp != NULL);
    }
    printf("\n");
}

int insert_at_head(ROOT *r, DATA *d)
{ NODE * temp;
    temp = make_node(d);
    
    if (temp == NULL) return -1;  // fail, cannot create new NODE
    
    if (r == NULL)
    { r = make_root();
        if (r == NULL) return -1;   // fail, cannot create ROOT
    }
    
    (r->num)++;
    temp->next = r->head;
    r->head = temp;
    
    if (r->num == 1)              // if previously the list is empty
        r->tail = temp;
    
    return 0;
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

void delete_node (ROOT *r, DATA d)
{ NODE * temp;
    if (r == NULL)   return;      // non-existing list
    if (r->head == NULL) return;  // empty list
    
    temp = r->head;               // delete at head, special case
    if (*(DATA *)(temp->data) == d)
    { r->head = temp->next;
        (r->num)--;
    }
    
    else
    { while(temp->next != NULL && *(DATA *)(temp->next->data) != d)
        temp = temp->next;
        
        if (temp->next == NULL )    // reach the tail of the list
        { if (*(DATA *)(temp->data) == d)
        { r->tail = temp;
            (r->num)--;
        }
        else
            return;
        }
        else
        { temp->next = temp->next->next;
            (r->num)--;
        }
    }
}

int rearrange (ROOT *r, DATA d)
{ int cnt = 0;                  // count the number of linked list operations
    // you can define new linked list, new node, or new function.
    // But you can only use the three linked list operations as
    // defined above: delete_node, insert_at_head, insert_at_tail
    // to modify any linked list. Whenever you call any of these
    // functions, remember to update cnt.
    NODE *this,*start,*end;
    
    if (r == NULL) return 0;      // non-existing list
    if (r->head == NULL) return 0;// empty list
    
    this = r->head;
    while (this != NULL && *(DATA *)(this->data) != d)
       this = this->next;
    
    if (this == NULL || (this->next == NULL && *(DATA *)(this->data) != d))
        // d not in the list
    { printf("%d not in the list.\n", d);
        return 0;
    }

    
    start = r->head;
    end = r->tail;
    DATA key;
    do{
    if(*(DATA *)(start->data) < *(DATA *)(this ->data)){
        key =*(DATA *)(start->data);
        delete_node(r, key);
        insert_at_head(r, start->data);
        start = start->next;
        cnt +=2;
    }
    else if(*(DATA *)(start->data) > *(DATA *)(this->data)){
        key =(*(DATA *)(start->data));
        delete_node(r, key);
        insert_at_tail(r, start->data);
        start = start->next;
        cnt +=2;
    }
    else if(*(DATA *)(start->data) == *(DATA *)(this->data) ){
        start = start->next;
    }
    }while((*(DATA *)(start->data) != *(DATA *)end->data));
    
    
    //last node
    if((*(DATA *)(start->data)) == (*(DATA *)end->data)){
        if(*(DATA *)(start->data) < *(DATA *)(this ->data)){
            key =*(DATA *)(start->data);
            delete_node(r, key);
            insert_at_head(r, start->data);
            start = start->next;
            cnt +=2;
        }
        else if(*(DATA *)(start->data) > *(DATA *)(this->data)){
            key =(*(DATA *)(start->data));
            delete_node(r, key);
            insert_at_tail(r, start->data);
            start = start->next;
            cnt +=2;
        }
    }
    
    
    
//condition checked until last pointer moves till last data
    

    
    printf("Rearrange around %d ...\n", d);
    
    
    return cnt;
}


int main(int argc, char *argv[])
{ ROOT *root;   // a pointer to ROOT type
    DATA *data;   // a pointer points to type DATA (int)
    DATA d;
    FILE *input;
    int x;
    
    if (argc != 2)
    { printf("Usage: a.out input\n");
        exit(0);
    }
    
    input = fopen(argv[1], "r");
    if (input == NULL)
    { printf("Input file cannot open!\n");
        exit(0);
    }
    
    root = make_root();
    
    while (fscanf(input, "%d", &d) != EOF)
    { data = NEW(DATA);
        *data = d;
        insert_at_head(root, data);
    }
    
    printf("Select the value of x from the list: \n");
    display_list(root);
    scanf("%d", &x);
    
    d = rearrange (root, x);
    display_list(root);
    printf("%d list operatins used.\n", d);
    
    return 0;
}
