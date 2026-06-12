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
    bool isPalindrome(ListNode* head) {

        //tacking over the edge cases 

        if(head->next==NULL) return 1;
       //for counting the total nodes in the list so first we have to take one temp pointer that point head to last element 
       ListNode *temp = head;
       int count = 0;
       while(temp){
         count ++;
         temp = temp->next;
       }
       count = count/2;
       
       //NOw we have to partition the list from the even part of the list
       
       ListNode *curr = head,*prev=NULL;

       while(count--){
         prev=curr;
         curr=curr->next;
       }

       prev->next=NULL;
       // Now i am going to reverse the second partition list 
       prev=NULL;
       ListNode *fut = NULL;
       while(curr){
          fut = curr->next;
          curr->next = prev;
          prev=curr;
          curr=fut;
       }

       //comparing the both list from the first to second if they not match return 0
        ListNode *head1 = head;
       ListNode * head2=prev;
       while(head1){
         if(head1->val != head2->val){
            return 0;
         }
         head1=head1->next;
         head2=head2->next;
       }

     return 1;
    }
};