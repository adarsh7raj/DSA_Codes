
// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a 
//doubly-linked list whose sum is equal to given value target.

//TC : O(n) , SC : O(1)
class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> ans;
        Node* temp=head;
        int n=1;
        while(temp->next!=nullptr){
            temp=temp->next;
            n++;
        }
        int left_it=0;
        int right_it=n-1;
        Node*left=head;
        Node*right=temp;
        temp=head;
        while(left_it<right_it){
            if(left->data+right->data==target){
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
                left_it++;
                right_it--;
            }
            else if(left->data+right->data>target){
                right=right->prev;
                right_it--;
            }
            else{
                left=left->next;
                left_it++;
            }
        }
        return ans;
    }
};