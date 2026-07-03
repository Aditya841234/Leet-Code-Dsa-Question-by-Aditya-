/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   bool Check(TreeNode* l,TreeNode* r){
      // so if both side are empty than it return the true 
      if(l==NULL && r==NULL){
        return true;
      }

      //if one of them false and another is not false than it return false 
      if(l==NULL || r==NULL){
        return false;
      }

      //one condition is that both are not false than you can simply make the logic
       if(l->val == r->val && Check(l->left,r->right) && Check(l->right,r->left) ){
        return true;
       }

       return false;
   }
    bool isSymmetric(TreeNode* root) {
       if(root==NULL){ //because when the root is null than it simply you can say it is symmetric
        return true;
       }
       return Check(root->left,root->right);
    }
};