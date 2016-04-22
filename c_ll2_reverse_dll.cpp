
struct node* Reverse(struct node* head)
{
    struct node *temp,*r;
    temp=head;
    while(temp!=NULL){
        r=temp->next;
        temp->next=temp->prev;
        temp->prev=r;
        head=temp;
        temp=r;
    }
return head;
}

