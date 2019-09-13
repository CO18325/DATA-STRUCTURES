#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
};

typedef struct NODE node;

node* create_node(int element){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=element;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}

node* add_node_to_list(node **headptr,node *start,node *ptr,node **tailptr){
    if(start==NULL){
        *headptr=ptr;
    }else{
        start->next=ptr;
        ptr->prev=start;
    }
    *tailptr=ptr;
    start=ptr;
}
void f_display(node *head){
    node *ptr=head;
    printf("\nFORWARD DISPLAY: \n");
    while(ptr){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}
void r_display(node *tail){
    node *ptr=tail;
    printf("\nREVERSE DISPLAY: \n");
    while(ptr){
        printf("%d->",ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL");
}

node* delete_node(node *head,node **tailptr,int element){
    node *ptr=head;
    node *previous=NULL;
    int flag=0;
    while(ptr){
        if(ptr->data==element){
            flag=1;
            if(previous==NULL){
                 head->next->prev=ptr->prev;
                 head=head->next;
            }else if(ptr==(*tailptr)){
                previous->next=ptr->next;
                 *tailptr=previous;
            }else{
                previous->next=ptr->next;
                ptr->next->prev=previous;

            }
            free(ptr);
            break;
        }
        previous=ptr;
        ptr=ptr->next;
    }
    if(flag!=1){
        printf("ELEMENT NOT FOUND\n");
    }
    return head;
}

node* insert_node(node *head,node **tailptr,int positional_data,int element){
    node *ptr=head;
    node *newptr=create_node(element);
    int flag=0;
    while(ptr){
        if(ptr->data==positional_data){
            if(ptr!=(*tailptr)){
                ptr->next->prev=newptr;
            }else{
                *tailptr=newptr;
            }
            newptr->next=ptr->next;
            ptr->next=newptr;
            newptr->prev=ptr;
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==0){
        printf("ELEMENT NOT FOUND AFTER WHICH WE NEED TO INSERT \n");
    }
    return head;
}

void search_node(node *head,int element){
    node *ptr=head;
    int flag=0,count=1;
    while(ptr){
        if(ptr->data==element){
            flag=1;
            printf("ELEMENT FOUND AT %d",count);
            break;
        }
        ptr=ptr->next;
        count++;
    }
    if(flag!=1){
        printf("ELEMENT NOT FOUND");
    }
}

node* update_node(node *head,int element){
    node *ptr=head;
    int flag=0;
    while(ptr){
        if(ptr->data==element){
            flag=1;
            printf("ENTER THE UPDATED DATA: ");
            scanf("%d",&element);
            ptr->data=element;
            break;
        }
        ptr=ptr->next;
    }
    if(flag!=1){
        printf("ELEMENT NOT FOUND");
    }
    return head;
}

node* sort_list(node *head){
    int temp;
    node *iptr,*jptr;
    iptr=head;
    while(iptr){
        jptr=iptr->next;
        while(jptr){
            if(iptr->data>jptr->data){
                temp=iptr->data;
                iptr->data=jptr->data;
                jptr->data=temp;
            }
            jptr=jptr->next;
        }
        iptr=iptr->next;
    }
    return head;
}
void main(){
    int element,positional_data;
    char check='y';
    node *head,*tail,*start,*ptr;
    node **headptr=&head;
    node **tailptr=&tail;
    start=NULL;
    while(check=='y'||check=='Y'){
            printf("\nENTER DATA: ");
            scanf("%d",&element);
            ptr=create_node(element);
            start=add_node_to_list(headptr,start,ptr,tailptr);
            printf("Y/N");
            check=getch();
    }
    f_display(head);
    r_display(tail);

    printf("\nENTER THE ELEMENT TO BE DELETED: ");
    scanf("%d",&element);
    head=delete_node(head,tailptr,element);
    f_display(head);
    r_display(tail);

    printf("\nENTER THE ELEMENT YOU WANT TO INSERT: ");
    scanf("%d",&element);
    printf("ENTER THE ELEMENT AFTER WHICH YOU WANT TO ENTER:");
    scanf("%d",&positional_data);
    head=insert_node(head,tailptr,positional_data,element);
    f_display(head);
    r_display(tail);

    printf("\nENTER THE ELEMENT YOU WANT TO SEARCH: ");
    scanf("%d",&element);
    search_node(head,element);

    printf("\nENTER THE ELEMENT YOU WANT TO UPDATE: ");
    scanf("%d",&element);
    head=update_node(head,element);
    f_display(head);
    r_display(tail);

    printf("\nSORTED DOUBLE LINKED LIST: ");
    head=sort_list(head);
    f_display(head);
    r_display(tail);

}
