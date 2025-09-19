 // soution : O(N):

 class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head == nullptr || k == 1) return head;
    
            // Step 1: Count total number of nodes
            int totalNodes = 0;
            ListNode* temp = head;
            while (temp != nullptr) {
                totalNodes++;
                temp = temp->next;
            }
    
            // Step 2: Setup dummy node and pointers
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
            ListNode* prevGroupTail = dummy;
            ListNode* current = head;
    
            // Step 3: Loop while at least k nodes remain
            while (totalNodes >= k) {
                ListNode* groupHead = current;
                ListNode* prev = nullptr;
                ListNode* next = nullptr;
    
                // Step 4: Reverse k nodes or group
                for (int i = 0; i < k; i++) {
                    next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                }
                // Step 5: Connect with previous group
                
                prevGroupTail->next = prev;  // this step is done to ensure that previous group is connected to correct head of new reversed group;
                groupHead->next = current; // this is necessary beacuse if do not do this then last group which is left becuase of less than k will not be connected to the previous group
                 
                // Move prevGroupTail to the tail of the reversed group
                prevGroupTail = groupHead;  
                
                // Decrement total node count
                totalNodes -= k;
            }
    
            return dummy->next;
        }
    };
    


    // recursive approach : O(N):

    int getlength(Node*head,int k){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;

    }
    return c;

}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    //base case
    if(head==NULL){
        return NULL;

    }

    Node*prev=NULL;
    Node*curent=head;
    Node*forward=NULL;

    int c=0;
    while(curent!=NULL && c<k){
        forward=curent->next;
        
        curent->next=prev;
        prev=curent;
        curent=forward;
        c++;
    }

    //
    if(forward!=NULL ){
        // head->next=kreverse(forwars,k);
        if(getlength(forward,k)>=k){
            head->next = kReverse(forward, k); // beacause the head is now the tail of the reversed part

        }
        else{
            head->next=forward;
        }
        
    }

    return prev;
}