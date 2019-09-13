#include<stdio.h>
#include<stdlib.h>

struct NODE{

    int data;
    struct NODE *link;

};
typedef struct NODE node;

node* create_node(int element){
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=element;
    ptr->link=NULL;
    return ptr;
}

node* add_node_to_list(node *ptr,node **headptr,node *start){
    if(start==NULL){
        *headptr=ptr;
        start=ptr;
    }else{
        start->link=ptr;
        start=ptr;
    }
    ptr->link=*headptr;
    return start;
}
void display(node *head){
    node *iptr=head;
    printf("\n");
    if(head){
        do{
            printf("%d->",iptr->data);
            iptr=iptr->link;
        }while(iptr!=head);
        printf("NULL");
   }
}

void main(){
    int element;char check='y';
    node **headptr,*head,*ptr,*start=NULL;
    headptr=&head;
    while(check=='y'||check=='Y'){
        printf("\nENTER THE DATA:");
        scanf("%d",&element);
        ptr=create_node(element);
        start=add_node_to_list(ptr,headptr,start);
        printf("Y/N");
        check=getch();
    }
    display(head);

}
