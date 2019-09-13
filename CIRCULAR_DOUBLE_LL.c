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
node* add_node_to_list(node **headptr,node *start,node *ptr){
    if(start==NULL){
        *headptr=ptr;
    }else{
        start->next=ptr;
        ptr->prev=start;
    }
    start=ptr;
    (*headptr)->prev=ptr;
    ptr->next=*headptr;

    return start;
}
void f_display(node *head){
    if(head){
        node *ptr=head;
        printf("\nFORWARD DISPLAY: \n");
        do{
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
        printf("NULL");
    }
}
void r_display(node *head){
    if(head){
        node *ptr=head;
        printf("\nREVERSE DISPLAY: \n");
        do{
            ptr=ptr->prev;
            printf("%d->",ptr->data);
        }while(ptr!=head);
        printf("NULL");
    }
}
node* deletion(node *head,int element){
    if(head){
        node *ptr=head;
        node *previous,*next;
        previous=NULL;
        int flag=0;
        do{
            if(ptr->data==element){
                if(previous==NULL){
                    head->next=ptr->next;
                    ptr->next->prev=head;
                }else{
                    previous->next=ptr->next;
                    ptr->next->prev=previous;
                }
                free(ptr);
                flag=1;
                break;
            }
            previous=ptr;
            ptr=ptr->next;
        }while(ptr!=head);
        if(flag!=1){
            printf("ELEMENT NOT FOUND");
        }
    }
    return head;
}
void main(){
    int element;
    char check='y';
    node *head,*start,*ptr;
    node **headptr=&head;
    start=NULL;
    while(check=='y'||check=='Y'){
            printf("\nENTER DATA: ");
            scanf("%d",&element);
            ptr=create_node(element);
            start=add_node_to_list(headptr,start,ptr);
            printf("Y/N");
            check=getch();
    }
    f_display(head);
    r_display(head);
    printf("\n ENTER THE ELEMENT TO BE DELETED: ");
    scanf("%d",&element);
    head=deletion(head,element);
    f_display(head);
}
