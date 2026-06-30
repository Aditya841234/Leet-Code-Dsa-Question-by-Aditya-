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
    void preorder(TreeNode* root, vector<int>& arr){
        if(root == NULL){
            arr.push_back(-99);
            return;
        }

        arr.push_back(root->val);

        preorder(root->left, arr);
        preorder(root->right, arr);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        vector<int> p1;
        vector<int> p2;

        preorder(p, p1);
        preorder(q, p2);

        return p1 == p2;
    }
};
