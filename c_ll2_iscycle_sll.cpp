void  HasCycle(Node* head)
{
    struct Node *fast,*slow,*Cyclehead;
    fast=slow=head;
    int cyclelength=0;
    while(fast!=NULL&&slow!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            printf("we found a cycle"); // Finding LOOP  && here keep fast pointer where they met
            break;
        }
    }
    slow=head;
    while(slow!=NULL&&fast!=NULL){  // Finding Head of the LOOP
        slow=slow->next;
        fast=fast->next;
        if(slow==fast){
            printf("we found head of Cycle");
            Cyclehead=slow;
            cyclelength++;
            break;
        }
    }
    // Finding Length of the Loop
    cyclelength=cyclelength+findcycle_length(Cyclehead);
    printf("Length of the Cycle is %d\n",cyclelength);
    // Finding Difference between stat of loop and Head of sll
    printf("The start of Cycle is %d nodes away from Head of SLL",DiffBWHeadCycleHead(head,Cyclehead));

}

int findcycle_length(struc node *cycle){
    int l=0;
    while(cycle->next!=cycle){
        l++;
        cycle=cycle->next;
    }
    return l;
}

int DiffBWHeadCycleHead(struct node *H,struct node *CH){ // Finding Difference Between Starting and Start of Cycle
    struct node *start;
    start = H;
    int l =0;
    while(start->next!=CH){
        l++;
        start=start->next;
    }
   return l;
}
