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

    void preOrder(TreeNode* root,vector<int> &ans){
        //the stoping condition that is the 
        if(root==NULL){
            return;
        }

        //in pre order traversal we have three operation node than left after right 
        ans.push_back(root->val);

        preOrder(root->left,ans);

        preOrder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;
        preOrder(root,ans);

        return ans;
        
    }
};