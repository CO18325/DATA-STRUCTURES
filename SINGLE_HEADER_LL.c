#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *link;
};

typedef struct NODE node;

node* create_node(int element){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->link=NULL;
    ptr->data=element;
    return ptr;
}

node* add_node_to_list(node **headptr,node *start,node *ptr){
    (*headptr)->data++;
    start->link=ptr;
    ptr->link=NULL;
    start=ptr;
    return start;
}
void display(node *head){
    node *ptr=head;
    printf("\n");
    while(ptr){
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    printf("NULL");
}

void main(){
    int element;
    char check='y';
    node *ptr,*head,*start;
    node **headptr=&head;
    ptr=create_node(0);
    head=ptr;
    start=ptr;
    while(check=='y'||check=='Y'){
        printf("\nENTER THE DATA: ");
        scanf("%d",&element);
        ptr=create_node(element);
        start=add_node_to_list(headptr,start,ptr);
        printf("Y/N");
        check=getch();
    }
    display(head);
}
