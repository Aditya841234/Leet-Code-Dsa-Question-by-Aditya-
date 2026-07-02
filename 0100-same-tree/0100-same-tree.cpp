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
    // void preorder(TreeNode* root, vector<int>& arr){
    //     if(root == NULL){
    //         arr.push_back(-99);
    //         return;
    //     }

    //     arr.push_back(root->val);

    //     preorder(root->left, arr);
    //     preorder(root->right, arr);
    // }

    bool isSameTree(TreeNode* p, TreeNode* q) {

        // vector<int> p1;
        // vector<int> p2;

        // preorder(p, p1);
        // preorder(q, p2);

        // return p1 == p2;

        if(!p && !q){
            return 1;
        }

        if(!p&&q ||p&&!q){
            return 0;
        }

       // if the value exist but not to equal of each other 
        if(p->val != q->val){
            return 0;

        }

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
