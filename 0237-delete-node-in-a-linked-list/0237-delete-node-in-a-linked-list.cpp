/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

   
    void deleteNode(ListNode* node) {
      //so in this section i need to create the linkedlist who conteain those lement 
       node->val = node->next->val;
       node->next=node->next->next;
      
    }
};