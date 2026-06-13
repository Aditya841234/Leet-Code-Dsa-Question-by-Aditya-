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
    ListNode* deleteMiddle(ListNode* head) {
       if(head->next==NULL){
        return NULL;
       }
       ListNode* temp = head;
       int count = 0;
       while(temp){
        count++;
        temp=temp->next;
       } 
       temp=head;
       ListNode* prev =NULL;

       count = count /2; // if youdivide 7/3 than you get 3 so the lopp will be go 3 2 1 0 that not possible 
       while(count--){
         prev=temp;
         temp= temp->next;
       }

       prev->next=temp->next;
       delete temp;
       return head;


    }
};