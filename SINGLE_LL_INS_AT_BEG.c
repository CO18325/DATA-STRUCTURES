//INSERTION AT THE BEGINING
#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *blink;
};
typedef struct NODE node;

node* create_node(int element){

    node *ptr;
    ptr = (node*)malloc(sizeof(node));
    ptr->data=element;
    ptr->blink=NULL;
    return ptr;
}

node* add_node_to_list(node *ptr,node *start){

    if(start==NULL){
        start=ptr;
    }else{
        ptr->blink=start;
        start=ptr;
    }
    return start;
}

void display(node *head){

    node *ptr=head;
    while(ptr){
        printf("%d->",ptr->data);
        ptr=ptr->blink;
    }
    printf("NULL");
}

void main(){

        node *ptr,*start=NULL,*head;
        int element;
        char check='y';
        while(check=='Y'||check=='y'){
            printf("ENTER THE DATA: ");
            scanf("%d",&element);
            ptr=create_node(element);
            start=add_node_to_list(ptr,start);
            printf("Y/N\n");
            check=getch();
        }
        head=ptr;
        display(head);
}
