
// Intuition

// 👉 A binary tree can be uniquely constructed only if Inorder traversal is present in the given pair.

// Why?

// Inorder alone is not enough (many possible trees).

// But Inorder + Preorder → unique tree.

// Inorder + Postorder → unique tree.

// Preorder + Postorder → ❌ not unique (can form multiple trees).

// 🔹 Algorithm

// If one of the traversals is Inorder (2):

// If the other is Preorder (1) → ✅ unique.

// If the other is Postorder (3) → ✅ unique.

// Otherwise → ❌ not unique.
// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
   if(a!=2 && b!=2){
       return false;
   }
   if(a==b){
       return false;
       
   }
   return true;
    }
};