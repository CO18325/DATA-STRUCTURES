#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int info;
    struct NODE *link;
};

typedef struct NODE node;

node *head,*ptr,*nptr,*prevptr,*iptr,*jptr;
node *start=NULL;

void create_new_node(int);
void add_node_to_list();
void display();
void insert_node(int);
void delete_node(int);
void update_node(int);
void menu();
void binary_sort();
void selection_sort();

int choice,element;

void main(){
    char check='y';
    //int element;
    while(check=='y' || check=='Y'){
        printf("\nENTER THE DATA: ");
        scanf("%d",&element);
        create_new_node(element);
        add_node_to_list();
        printf("\n Y/N");
        check=getch();
    }
    menu();

}

void menu(){
       while(1){
            printf("\n1. INSERTION\t 2. UPDATION\t 3.TRAVERSING\t 4.DELETION\t 5.EXIT\t 6.RECREATE THE LL\t 7.BINARY SORT\t 8.SELECTION SORT \n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("\n ENTER THE ELEMNT AFTER WHICH YOU WANT TO ADD");
                    scanf("%d",&element);
                    insert_node(element);
                    break;
                case 2:
                    printf("\n ENTER THE ELEMENT YOU WANT TO UPDATE");
                    scanf("%d",&element);
                    update_node(element);
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    printf("ENTER THE ELEMENT YOU WANT TO DELETE:");
                    scanf("%d",&element);
                    delete_node(element);
                    break;
                case 5:
                    exit(1);
                case 6:
                    main();
                    break;
                case 7:
                    binary_sort();
                    break;
                case 8:
                    selection_sort();
                    break;
                //case 9:

                default:
                    menu();
                    break;
            }
        }

}

void create_new_node(int element){
    ptr = (node*)malloc(sizeof(node));
    ptr->info=element;
    ptr->link=NULL;
}

void add_node_to_list(){
    if(start==NULL){
        start=ptr;
        head=ptr;
    }
    else{
        start->link=ptr;
        start=ptr;
    }
}

void display(){
    ptr=head;
    //int temp=ptr->link->info;
    //printf("%d",temp);
    while(ptr){
        printf("\n%d\t",ptr->info);
        ptr=ptr->link;
    }
    printf("\n");
    menu();
}

void insert_node(int element){
    nptr=head;
    while(1){
        if(nptr->info==element){
            break;
        }
        nptr=nptr->link;
    }
    printf("\nENTER THE DATA: ");
    scanf("%d",&element);
    create_new_node(element);
    ptr->link=nptr->link;
    nptr->link=ptr;
    display();

}

void delete_node(int element){
    if(head->info==element){
        head=head->link;
    }
    else{
        nptr=head;
        prevptr=head;
        while(1){
            if(nptr->info==element){
                break;
            }
            prevptr=nptr;
            nptr=nptr->link;
        }
        prevptr->link=nptr->link;
    }
    display();


}

void update_node(int element){
    nptr=head;
    while(1){
        if(nptr->info==element){
            printf("ENTER THE NEW ELEMENT");
            scanf("%d",&nptr->info);
            break;
        }
        nptr=nptr->link;
    }
    display();

}

void binary_sort(){
    int temp;
    iptr=head;
    //jptr=iptr->link;
    for(;iptr->link;){
      jptr=head;
      for(;jptr->link;){
          if(jptr->info>jptr->link->info){
            temp=jptr->info;
            jptr->info=jptr->link->info;
            jptr->link->info=temp;
           }
           jptr=jptr->link;
      }
      iptr=iptr->link;
    }
    display();
}
void selection_sort(){
    int temp;
    iptr=head;
    while(iptr->link){
        jptr=iptr->link;
        while(jptr->link){
            if(iptr->info>jptr->info){
               temp=jptr->info;
               jptr->info=iptr->info;
               iptr->info=temp;
            }
            jptr=jptr->link;
        }
        iptr=iptr->link;
    }
    display();
}
