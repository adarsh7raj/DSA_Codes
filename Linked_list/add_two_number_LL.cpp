// brute force approach : but this will not work of large size linked list :
// You are given two non-empty linked lists representing two non-negative integers.

// Digits are stored in reverse order.

// Each node contains a single digit.

// Add the two numbers and return the sum as a linked list (in reverse order).

// Example
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]


// Explanation:

// Number from l1 = 342

// Number from l2 = 465

// Sum = 807

// Linked list = [7 → 0 → 8] (reverse order)



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy=new ListNode(0,nullptr);
            ListNode*temp=dummy;
            string num1="";
            string num2="";
            while(l1!=nullptr || l2!=nullptr){
                if(l1!=nullptr){
                num1=num1+to_string(l1->val);
                l1=l1->next;
                }
                if(l2!=nullptr){
             num2=num2+to_string(l2->val);
             l2=l2->next;
                }
            }
            reverse(num1.begin(),num1.end());
            reverse(num2.begin(),num2.end());
            long long result= stoll(num1)+ stoll(num2);
            cout<<result;
            string result_node=to_string(result);
            int i=result_node.size()-1;
            while(i>=0){
                int digit=result_node[i]-'0';
    temp->next=new ListNode(digit);
    temp=temp->next;
    i--;
            }
            return dummy->next;
        }
    };

    //optimal solution :

    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0);
            ListNode* temp = dummy;
            int carry = 0;
    
            while (l1 != nullptr || l2 != nullptr || carry) {
              
                int sum = l1 ? l1->val : 0 +l2 ? l2->val : 0  + carry;
    
                carry = sum / 10;
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
    
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
    
            return dummy->next;
        }
    };
    