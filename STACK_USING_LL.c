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

//THIS FUNCTION IS JUST FOR REFERENCE IT DOESNOT OBEY THE RULES OF STACK
void display_stack(node **top){
    node *ptr;
    ptr=(*top);
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
int pop(node **top){
    if((*top)==NULL){
        printf("\nUNDRFLOW");

        return 0;
    }
    int del_element=(*top)->data;
    node *temp=(*top);
    *top=(*top)->link;
    free(temp);
    return (del_element);

}
void push(node **top,int element){
    node *ptr=create_node(element);
    ptr->link=(*top);
    *top=ptr;
    //return ptr;
}
int peek(node **top){
    return ((*top)->data);
}

int peek_at_desired_pos(node **top,int loc){
        node *ttail=NULL;
        node **ttop=&ttail;
        int value,element,i;
        for(i=loc;i>=1;i--){
            element=pop(top);
            push(ttop,element);
            //ttop++;
        }
        //display_stack(ttop);
        value=peek(top);
        for(i=loc;i>=1;i--){
            element=pop(ttop);
            push(top,element);
        }
        return value;
}

void peek_desired(node **top,int element){
        node *ttail=NULL;
        node **ttop=&ttail;
        int value,i=0,flag=0;
        while(*top){
            value=pop(top);
            if(value==element){
                printf("ELEMENT FOUND AT %d FROM TOP OF STACK",i+1);
                flag=1;
                break;
            }
            push(ttop,value);
            i++;
        }
        while(*ttop){
            value=pop(ttop);
            push(top,value);
        }
        if(flag!=1){
            printf("\nELEMENT NOT FOUND!!\n");

        }
}

void update_desired_pos(node **top,int element){
        node *ttail=NULL;
        node **ttop=&ttail;
        int value,i=0,flag=0;
        while(*top){
            value=pop(top);
            if(value==element){
                printf("\nENTER THE UPDATED VALUE: ");
                scanf("%d",&element);
                (*(top))->data=element;
                flag=1;
                break;
            }
            push(ttop,value);
            i++;
        }
        while(*ttop){
            value=pop(ttop);
            push(top,value);
        }
        if(flag!=1){
            printf("\nELEMENT NOT FOUND!!\n");

        }
}



void main(){
    node *tail=NULL;
    node **top=&tail;
    int element,loc,option;
    while(1){
      printf("\n1.PUSH \t2.POP \t3.PEEK \t4.PEEK AT DESIRED LOCATION\n5.DISPLAY  \t6.UPDATION \t7.PEEK DESIRED ELEMENT \t8.EXIT\n");
      printf("ENTER YOUR OPTION: ");
      scanf("%d",&option);
      switch(option){
        case 1:
            printf("\nENTER THE NUMBER TO BE PUSHED INTO THE STACK: ");
            scanf("%d",&element);
            push(top,element);
            //printf("\n%d HAS BEEN PUSHED INTO THE STACK",(push(top,element)->data));
            //top++;
            break;
        case 2:
            printf("\nELEMENT DELETED IS %d",pop(top));
            display_stack(top);
            break;
         case 3:
            printf("\nTHE LAST ELEMENT IN THE STACK IS: %d",(peek(top)));
            break;
         case 4:
            printf("\nENTER THE LOC YOU WANT TO SEARCH: ");
            scanf("%d",&loc);
            loc=loc-1;
            element=peek_at_desired_pos(top,loc);
            printf("\nTHE LAST ELEMENT IN THE STACK IS: %d",element);
            break;
         case 5:
            display_stack(top);
            break;
         case 6:
            printf("\nENTER THE ELEMENT YOU WANT TO UPDATE: ");
            scanf("%d",&element);
            update_desired_pos(top,element);
            printf("\nSTACK IS UPDATED!!");
            break;
         case 7:
            printf("ENTER THE ELEMENT TO BE SEARCHED: ");
            scanf("%d",&element);
            peek_desired(top,element);
            break;
         case 8:
            exit(4);
      }
   }

}
