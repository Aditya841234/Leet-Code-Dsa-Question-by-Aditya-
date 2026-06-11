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
    ListNode* middleNode(ListNode* head) {
      
      //this is our second approach that is help to find out my answer 
      ListNode* slow=head;
      ListNode* fast=head;
        // if you wirte fast after the fast next than it will be try to access from the null and next of the null that make it cause and give us segement fault 
      while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
      }

      return slow;
    }
};