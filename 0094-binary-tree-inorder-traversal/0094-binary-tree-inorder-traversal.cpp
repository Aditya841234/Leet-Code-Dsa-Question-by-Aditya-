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

    void InOrder(TreeNode* root,vector<int> &ans){
        //stoping condition
        if(root==NULL){
            return;
        }

        //inorder- left,node,right

        //left
        InOrder(root->left,ans);

        //node
        ans.push_back(root->val);

        //right

        InOrder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        InOrder(root,ans);
        return ans;
    }
};