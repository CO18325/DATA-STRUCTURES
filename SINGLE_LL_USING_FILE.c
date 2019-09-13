
#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int info;
    struct NODE *link;
};

typedef struct NODE node;

int recreate_flag=0;

node* create_new_node(int element){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->info=element;
    ptr->link=NULL;

    return ptr;
}

node* add_node_to_list(node **headptr,node *start,node *ptr){
    if(start==NULL){
        start=ptr;
        *headptr=ptr;
    }
    else{
        start->link=ptr;
        start=ptr;
    }
    return start;
}

node* insert_node(int element,node *head){
    node *nptr=head;
    int flag=0;
    while(1){
        if(nptr->info==element){
            flag=1;
            break;
        }
        nptr=nptr->link;
    }
    if(flag==1){
        printf("\nENTER THE DATA: ");
        scanf("%d",&element);
        node *ptr=create_new_node(element);
        ptr->link=nptr->link;
        nptr->link=ptr;
    }else{
        printf("ELEMENT AFTER WHICH YOU WANT TO INSERT NOT FOUND!!\n");
    }

    return head;

}

node* update_node(node *head,int element){
    node *nptr=head;
    while(1){
        if(nptr->info==element){
            printf("ENTER THE NEW ELEMENT");
            scanf("%d",&nptr->info);
            break;
        }
        nptr=nptr->link;
    }

    return head;
}

void display(node *head){
    node *ptr=head;
    printf("\n");
    while(ptr){
        printf("%d->",ptr->info);
        ptr=ptr->link;
    }
    printf("NULL\n");
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
            fwrite(&(ptr->info),sizeof(int),1,fp);
            ptr=ptr->link;
        }
        fclose(fp);
        printf("FILE HAS BEEN SUCCESSFULLY MODIFIED!!!");
    }
}

void search_node(node *head,int element){
    node *ptr=head;
    int flag=0,count=1;
    while(ptr){
        if(ptr->info==element){
            flag=1;
            printf("ELEMENT FOUND AT %d",count);
            break;
        }
        ptr=ptr->link;
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
        jptr=iptr->link;
        while(jptr){
            if(iptr->info>jptr->info){
                temp=iptr->info;
                iptr->info=jptr->info;
                jptr->info=temp;
            }
            jptr=jptr->link;
        }
        iptr=iptr->link;
    }
    return head;
}

node*  delete_node(node* head, int element){
    if(head->link==NULL && head->info==element){
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
    node *ptr=head;
    node *prevptr=NULL;
    while(ptr){
        if(ptr->info==element){
            if(prevptr==NULL){
                head=head->link;
            }else{
                prevptr->link=ptr->link;
            }
            break;
        }
        prevptr=ptr;
        ptr=ptr->link;
    }
    return head;
}

void main(){
    int choice;
    int null_flag=0;
    int element,positional_data;
    char check='y',save_check;
    node *head,*start,*ptr;
    node **headptr=&head;
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
            ptr=create_new_node(element);
            start=add_node_to_list(headptr,start,ptr);
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
            ptr=create_new_node(element);
            start=add_node_to_list(headptr,start,ptr);
            printf("Y/N");
            check=getch();
        }
    }
         while(1){
            printf("\n1. INSERTION\t2. UPDATION\t3. TRAVERSING\t4.DELETION\n5. EXIT\t\t6. SAVE CHANGES\t7. SEARCH AN ELEMENT\t8. SORTING\n");
            printf("9. RECREATE THE DATABASE\t\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                    printf("\n ENTER THE ELEMNT AFTER WHICH YOU WANT TO ADD");
                    scanf("%d",&element);
                    head=insert_node(element,head);
                    break;
                case 2:
                    printf("\n ENTER THE ELEMENT YOU WANT TO UPDATE");
                    scanf("%d",&element);
                    head=update_node(head,element);
                    break;
                case 3:
                    display(head);
                    break;
                case 4:
                    printf("\nENTER THE ELEMENT TO BE DELETED: ");
                    scanf("%d",&element);
                    head=delete_node(head,element);
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
                    head=sort_list(head);
                    break;
               case 9:
                    recreate_flag=1;
                    main();
            }
        }
}


