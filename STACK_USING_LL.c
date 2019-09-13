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

void display_stack(node **tailptr){
    node *ptr;
    ptr=(*tailptr);
    printf("\n");
    if(ptr){
        while(ptr){
            printf("%d->",ptr->data);
            ptr=ptr->link;
        }
        printf("NULL");
    }else{
        printf("UNDERFLOW\n");
    }
}
int pop(node **tailptr){
    if((*tailptr)==NULL){
        printf("\nUNDRFLOW");

        return 0;
    }
    int del_element=(*tailptr)->data;
    *tailptr=(*tailptr)->link;
    return (del_element);

}
node* push(node **tailptr,int element){
    node *ptr=create_node(element);
    ptr->link=(*tailptr);
    *tailptr=ptr;
    return ptr;
}
node* peek(node **tailptr){
    return (*tailptr);
}

int peek_at_desired_pos(node **tailptr,int top,int loc){
        node *ttail=NULL;
        node **ttailptr=&ttail;
        int ttop=-1,element,i;
        for(i=top;i>top-loc;i--){
            push(ttailptr,(*(tailptr))->data);
            ttop++;
            pop(tailptr);
        }
        //display_stack(ttailptr);
        element=(*(tailptr))->data;
        for(i=ttop;i>=0;i--){
            push(tailptr,(*(ttailptr))->data);
            pop(ttailptr);
        }
        return element;
}

void update_at_desired_pos(node **tailptr,int top,int loc){
        node *ttail=NULL;
        node **ttailptr=&ttail;
        int ttop=-1,element,i;
        for(i=top;i>top-loc;i--){
            push(ttailptr,(*(tailptr))->data);
            ttop++;
            pop(tailptr);
        }
        //display_stack(ttailptr);
        printf("\nENTER THE UPDATED VALUE: ");
        scanf("%d",&element);
        (*(tailptr))->data=element;
        for(i=ttop;i>=0;i--){
            push(tailptr,(*(ttailptr))->data);
            pop(ttailptr);
        }
}



void main(){
    node *tail=NULL;
    node **tailptr=&tail;
    int top=-1,element,loc,option;
    while(1){
      printf("\n1.PUSH \t2.POP \t3.PEEK \t4.PEEK AT DESIRED LOCATION\n5.DISPLAY  \t6.UPDATION \t7.EXIT\n");
      printf("ENTER YOUR OPTION: ");
      scanf("%d",&option);
      switch(option){
        case 1:
            printf("\nENTER THE NUMBER TO BE PUSHED INTO THE STACK: ");
            scanf("%d",&element);
            printf("\n%d HAS BEEN PUSHED INTO THE STACK",(push(tailptr,element)->data));
            top++;
            break;
        case 2:
            printf("\nELEMENT DELETED IS %d",pop(tailptr));
            display_stack(tailptr);
            break;
         case 3:
            printf("\nTHE LAST ELEMENT IN THE STACK IS: %d",(peek(tailptr))->data);
            break;
         case 4:
            printf("\nENTER THE LOC YOU WANT TO SEARCH: ");
            scanf("%d",&loc);
            loc=loc-1;
            element=peek_at_desired_pos(tailptr,top,loc);
            printf("\nTHE LAST ELEMENT IN THE STACK IS: %d",element);
            break;
         case 5:
            display_stack(tailptr);
            break;
         case 6:
            printf("\nENTER THE LOC YOU WANT TO UPDATE: ");
            scanf("%d",&loc);
            loc=loc-1;
            update_at_desired_pos(tailptr,top,loc);
            printf("\nSTACK IS UPDATED!!");
      }
   }

}
