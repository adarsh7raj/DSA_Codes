Node*(int arr[],n){
    if(n==0){
        retrun nullptr;
    }
    Node* head=new Node(arr[0]);
    Node*temp=head;
    int i=1;
    while(i<n){
Node * new_node=new Node(arr[i]);
temp->next=new_node;
new_node->prev=temp;
temp=temp->next;

    }
}