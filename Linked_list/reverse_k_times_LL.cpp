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
                groupHead->next = current; // this step is done to ensure that new reversed group's tail is connected to next node.
                 
                // Move prevGroupTail to the tail of the reversed group
                prevGroupTail = groupHead;  
                cout<<prevGroupTail->next->val;
                cout<<groupHead->next->val;
                // Decrement total node count
                totalNodes -= k;
            }
    
            return dummy->next;
        }
    };
    