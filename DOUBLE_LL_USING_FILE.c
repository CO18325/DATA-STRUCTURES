#include<stdio.h>
#include<stdlib.h>
int recreate_flag=0;
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
node* delete_node(node *head,node **tailptr,int element){
    node *ptr=head;
    node *previous=NULL;
    int flag=0;
    while(ptr){
        if(ptr->data==element){
            flag=1;
            if(previous==NULL){
                 if(head->next==NULL){
                    head=NULL;
                    char check='y',save_check;
                    recreate_flag=1;
                    printf("ALL THE ELEMENTS IN THE LIST HAVE BEEN DELETED.\nDO YOU WANT TO MAKE A NEW DB:Y/N ");
                    check=getch();
                    if(check=='Y'||check=='y')
                        main();
                    else{
                        printf("\nDO YOU WANT TO SAVE THE CHANGES MADE IN YOUR DATABASE: Y/N");
                        fflush(stdin);
                        scanf("%c",&save_check);
                        save_ll_in_file(save_check,head);
                        exit(1);
                    }
                 }
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

void save_ll_in_file(char save_check,node *head){
    if(save_check=='y'||save_check=='Y'){
        node *ptr=head;
        FILE *fp;
        fp=fopen("dbs.DAT","wb");
        if(fp==NULL){
            printf("CANNOT OPEN FILE");
            exit(2);
        }
        while(ptr){
            fwrite(&(ptr->data),sizeof(int),1,fp);
            ptr=ptr->next;
        }
        fclose(fp);
        printf("FILE HAS BEEN SUCCESSFULLY MODIFIED!!!");
    }
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
    int choice;
    int null_flag=0;
    int element,positional_data;
    char check='y',save_check;
    node *head,*tail,*start,*ptr;
    node **headptr=&head;
    node **tailptr=&tail;
    start=NULL;
    if(recreate_flag==0){
        FILE *fp;
        fp=fopen("dbS.DAT","rb");
        if(fp==NULL){
            printf("CANT OPEN");
            exit(2);
        }
        while(fread(&element,sizeof(int),1,fp)==1){
            null_flag=1;
            ptr=create_node(element);
            start=add_node_to_list(headptr,start,ptr,tailptr);
        }
        if(null_flag!=1){
            printf("THE FILE IS EMPTY\n");
            printf("LETS MAKE A NEW DATABASE!!");
            recreate_flag=1;
            main();
        }
        fclose(fp);
    }else{
        while(check=='y'||check=='Y'){
            printf("\nENTER DATA: ");
            scanf("%d",&element);
            ptr=create_node(element);
            start=add_node_to_list(headptr,start,ptr,tailptr);
            printf("Y/N");
            check=getch();
        }
    }

           while(1){
            printf("\n1. INSERTION\t2. UPDATION\t3. FRONT DISPLAY\t4.DELETION\n5. EXIT\t\t6. SAVE CHANGES\t7. SEARCH AN ELEMENT\t8. SORTING\n");
            printf("9. RECREATE THE DATABASE\t10. REVERSE DISPLAY\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("\nENTER THE ELEMENT YOU WANT TO INSERT: ");
                    scanf("%d",&element);
                    printf("ENTER THE ELEMENT AFTER WHICH YOU WANT TO ENTER:");
                    scanf("%d",&positional_data);
                    head=insert_node(head,tailptr,positional_data,element);
                    break;
                case 2:
                    printf("\nENTER THE ELEMENT YOU WANT TO UPDATE: ");
                    scanf("%d",&element);
                    head=update_node(head,element);
                    break;
                case 3:
                    f_display(head);
                    break;
                case 4:
                    printf("\nENTER THE ELEMENT TO BE DELETED: ");
                    scanf("%d",&element);
                    head=delete_node(head,tailptr,element);
                    break;
                case 5:
                    printf("DO YOU WANT TO SAVE THE CHANGES MADE IN YOUR DATABASE: Y/N");
                    fflush(stdin);
                    scanf("%c",&save_check);
                    save_ll_in_file(save_check,head);
                    exit(1);
               case 6:
                    save_check='y';
                    save_ll_in_file(save_check,head);
                    break;
               case 7:
                    printf("\nENTER THE ELEMENT YOU WANT TO SEARCH: ");
                    scanf("%d",&element);
                    search_node(head,element);
               case 8:
                    printf("\nSORTED DOUBLE LINKED LIST: ");
                    head=sort_list(head);
                    break;
               case 9:
                    recreate_flag=1;
                    main();
               case 10:
                    r_display(tail);
                    break;
            }
        }
}
