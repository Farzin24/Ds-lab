#include<stdio.h>
#include<stdlib.h>
int n,count=0;
void insert_begin();
void insert_end();
void insert_pos();
void traversal();
void delt_begin();
void delt_end();
void delt_pos();
void search();

        struct node
                {
                        int data;
                        struct node*next;
                };
                struct node*head=NULL,*newnode,*temp,*prev;


int main(){
                int ch;
                while(ch!=8){
                        printf("\nenter your choice:\n1.INSERT AT BEGINNING\n2.INSERT AT END\n3.INSERT AT A POSITION\n4.TRAVERSAL\n5.DELETION AT BEGINNING\n6.DELETION AT END\n7.DELETION AT A POSITION\n 8.search\n  9.EXIT");
                        scanf("%d",&ch);


                switch(ch)
                {

                        case 1:
                                insert_begin();
                                break;

                        case 2:
                                insert_end();
                                break;

                        case 3:
                                insert_pos();
                                break;

                        case 4:
                                traversal();
                                break;

                        case 5:
                                delt_begin();
                                break;

                        case 6:
                                delt_end();
                                break;

                        case 7:
                                delt_pos();
                                break;

                        case 8:
                                search();
                                break;
                        default:

                                printf("invalid choice");
                }
                                }
        }



void insert_begin(){
                        newnode=(struct node*)malloc(sizeof(struct node*));
                        printf("enter the data:\t");
                        scanf("%d",&newnode->data);


                                newnode->next=head;
                                head=newnode;
                        traversal();
                        count++;
                }

void traversal(){
                        if(head==NULL)
                        {
                                printf("no node is present");
                        }
                        else
                        {
                                temp=head;
                                while(temp->next!=NULL)
                                {
                                        printf("%d",temp->data);
                                        temp=temp->next;
                                }
                                printf("%d",temp->data);

                        }


                }

void insert_end(){
                        newnode=(struct node*)malloc(sizeof(struct node*));
                        printf("enter the data:\t");
                        scanf("%d",&newnode->data);
                        if(head==NULL)
                        {
                                newnode->next=NULL;
                                head=newnode;
                        }
                        else
                        {
                                 temp=head;
                                while(temp->next!=NULL)
                                {
                                        temp=temp->next;
                                }
                                newnode->next=NULL;
                                temp->next=newnode;
                        }
                        traversal();
                        count++;
                }

void insert_pos(){
                        newnode=(struct node*)malloc(sizeof(struct node*));
                        printf("enter the data:\t");
                        scanf("%d",&newnode->data);
                        if(head==NULL)
                        {
                                newnode->next=NULL;
                                head=newnode;
                        }
                        else
                        {
                                printf("enter the location to insert:");
                                scanf("%d",&n);
                                if(n>count)
                                {
                                        printf("insertion not possible");
                                }
                                else
                                {
                                int i=1;
                                temp=head;
                                while(i<n)
                                {


                                        temp=temp->next;
                                        i++;
                                }
                                newnode->next=temp->next;
                                temp->next=newnode;
                        }
                }
                        traversal();
                        count++;
}
void delt_begin(){
                        if(head==NULL)
                        {
                                printf("no node found");
                        }
                        else
                        {
                                temp=head;
                                head=temp->next;
                                free(temp);
                        }
                        traversal();
                        count--;

                }

void delt_end(){
                        if(head==NULL)
                        {
                                printf("no node found");
                        }
                        else
                        {
                                temp=head;
                                while(temp->next!=NULL)
                                {
                                        prev=temp;
                                        temp=temp->next;
                                }
                                prev->next=NULL;
                                free(temp);
                        }
                        traversal();
                        count--;
                }

void delt_pos(){

                        if(head==NULL)
                        {
                                printf("no node found");
                        }
                        else
                        {
                                printf("enter the location to delete:");
                                scanf("%d",&n);
                                if(n>count)
                                        {
                                                printf("deletion not possible");
                                        }
                                else
                                {
                                int i=1;
                                prev=head;
                                while(i<n-1)
                                {

                                        prev=prev->next;
                                        i++;
                                }
                                temp=prev->next;
                                prev->next=temp->next;
                                free(temp);
                        }}
                        traversal();
                        count--;
                }




void search(){
                        int search,shiya=0,i=1;
                        printf("enter the elements:");
                        scanf("%d",&search);
                        if(head==NULL)
                        {
                                printf("no node is present");
                        }
                        else
                        {
                                temp=head;
                                while(temp->next!=NULL)
                                {
                                        if(temp->data==search)
                                        {
                                                shiya=1;
                                                printf("its found @%d postn",i);
                                                break;
                                        }
                                        temp=temp->next;
i++;
 }

                                if(shiya==0)
                                {
                                        printf("not found");
                                        }
                        }


}
