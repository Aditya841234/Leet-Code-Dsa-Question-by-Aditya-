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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head==NULL || head->next==NULL) { return head;}
      int count =  0;
      ListNode* temp = head;
      while(temp){
        count++;
        temp=temp->next;
      }
      k = k%count;
      if(k==0) return head;
      count = count-k;
      temp=head;
      
      ListNode *curr = head,*prev = NULL;
      
      while(count--){
        prev = curr;
        curr=curr->next; 

      }
     ListNode* tail = curr;
     
    

    while(tail->next){
        tail=tail->next;
    }
   
    tail->next=head;
    prev->next=NULL;
    head=curr;



      return head;

    }
};