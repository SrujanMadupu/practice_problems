#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addnode(struct node **q,int num);
void addbeg(struct node **q,int num);
void show(struct node *q);
int count(struct node *q);
struct node* addtwoSLL(struct node *head1,struct node *head2);
void addrecursion(struct node *first,struct node *second,struct node **sum);
void remainingrecursion(struct node *head1,int k,struct node **q);
int main(){

struct node *head1 = NULL;

int Array1[]={ 5,9,3,3,2,4 };

int l1=sizeof(Array1)/sizeof(Array1[0]),i;

for(i=0;i<l1;i++){
    addnode(&head1,Array1[i]);
}

struct node *head2 = NULL;

int Array2[]={ 9,9,9,9 };

int l2=sizeof(Array2)/sizeof(Array2[0]);

for(i=0;i<l2;i++){
    addnode(&head2,Array2[i]);
}

printf("First SLL\n");
show(head1);

printf("second SLL\n");
show(head2);
struct node *SumofTWoSLL = addtwoSLL(head1,head2);
show(SumofTWoSLL);
return 0;
}
void addnode(struct node **q,int num)
{
    struct node *temp,*r;
    temp=*q;
    if(*q==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->data=num;
        temp->next=NULL;
        *q=temp;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        r=malloc(sizeof(struct node));
        r->data=num;
        temp->next=r;
        r->next=NULL;

    }
}

void addbeg(struct node **q,int num)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    if(*q==NULL)
    {
        temp->next=NULL;
    }
    else
    {
        temp->next=*q;
    }
    *q=temp;
}

void show(struct node *q)
{
    struct node *temp;
    temp=q;
    printf("Elements in the linked list are\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int count(struct node *q)
{
    struct node *temp;
    temp=q;
    int c=0;
    while(temp!=NULL)
    {
        c=c+1;
        temp=temp->next;
    }
    return c;
}

struct node* addtwoSLL(struct node *head1,struct node *head2)
{
    int l1=count(head1),i;
    int l2=count(head2);
    struct node *temp1,*temp2,*result;
    result=NULL;
    temp1=head1;
    temp2=head2;
    int d = abs(l1-l2);
    if(l1>l2)
    {
        for(i=0;i<d;i++){
            int n = temp1->data;
            temp1=temp1->next;
        }
    }
    else
    {
       for(i=0;i<d;i++){
           temp2=temp2->next;
       }
    }
    addrecursion(temp1,temp2,&result);
    remainingrecursion(head1,d,&result);
    if(result->data > 9){
        result->data = (result->data)%10;
        addbeg(&result,1);
    }
    //show(result);
    return result;
}
void addrecursion(struct node *first,struct node *second,struct node **sum)
{
    if(first==NULL && second==NULL)
    {
        *sum = NULL;
        return ;
    }

    addrecursion(first->next,second->next,sum);
    int carry =0;
    if(*sum!=NULL && (*sum)->data > 9 ){
        (*sum)->data = ((*sum)->data)%10;
        carry = 1;
    }
    int x = first->data+second->data+carry;
    addbeg(sum,x);
}
void remainingrecursion(struct node *head1,int k,struct node **q){
   if(k==0){
    return ;
   }
   remainingrecursion(head1->next,--k,q);
   int carry =0;
   if((*q)->data > 9 ){
       (*q)->data= (*q)->data %10;
       carry =1;
   }
   int x = head1->data + carry ;
   addbeg(q,x);
}
