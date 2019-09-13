#include<stdio.h>
#include<stdlib.h>

int push_element(int *,int,int,int);
int pop(int *,int *);
int peek(int *,int);
void display(int *,int);
int peek_at_desired_pos(int *,int,int,int);


void main(){
    int option,loc;
    int size=50;
    int stack[size];
    int top=-1,element;
    int *stackptr=stack;
    int *topptr=&top;
    while(1){
        printf("\n1.PUSH \t2.POP \t3.PEEK \t4.DISPLAY \n5.EXIT \t6.PEEK AT DESIRED LOCATION  \t7.UPDATION\n");
        printf("ENTER YOUR OPTION: ");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("ENTER THE NUMBER: ");
                scanf("%d",&element);
                top=push_element(stackptr,top,size,element);
                break;
            case 2:
                element=pop(stackptr,topptr);
                printf("ELEMENT DELETED IS: %d\n",element);
                break;
            case 3:
                element=peek(stackptr,top);
                printf("LAST ELEMENT INPUT IS %d\n",element);
                break;
            case 4:
                display(stackptr,top);
                break;
            case 5:
                exit(1);
            case 6:
                printf("ENTER THE DESIRED LOCATION");
                scanf("%d",&loc);
                if(!(loc<=(top+1) && loc>0)){
                    printf("INVALID LOCATION\n");
                    main();
                }
                loc=loc-1;
                element=peek_at_desired_pos(stackptr,top,loc,size);
                printf("ELEMENT AT THE LOCATION IS %d\n",element);
        }
    }
}
int push_element(int *stackptr,int top,int size,int element){
    if(top==(size-1)){
        printf("OVERFLOW");
        return top;
    }
    top++;
    *(stackptr+top)=element;
    return top;
}
int pop(int *stackptr,int *topptr){
    if(*topptr==-1){
        printf("UNDERFLOW\n");
        return 0;
    }
    int element=*(stackptr+(*topptr));
    *topptr=(*topptr)-1;
    return element;
}

int peek(int *stackptr,int top){
    if(top==-1){
        printf("UNDERFLOW\n");
        return 0;
    }
    return *(stackptr+top);
}

void display(int *stackptr,int top){
    for(;top>=0;top--){
        printf("%d\n",*(stackptr+top));
    }
}

int peek_at_desired_pos(int *stackptr,int top,int loc,int size){
    int tempstack[size],i;
    int temptop=0;
    int element;
    for(i=top;i>(top-loc);i--){
        tempstack[temptop]=*(stackptr+i);
        temptop++;
    }
    element=*(stackptr+i);
    i++;
    for(;temptop>=0;i++){
        temptop--;
        *(stackptr+i)=tempstack[temptop];
    }
    return element;

}
