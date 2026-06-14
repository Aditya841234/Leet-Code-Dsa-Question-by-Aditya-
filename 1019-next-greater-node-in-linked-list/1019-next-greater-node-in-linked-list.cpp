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
    vector<int> nextLargerNodes(ListNode* head) {
     //hand;ling edge casess
    vector<int>ans;
        ListNode* tav = head;
        while(tav){
            ListNode *temp=tav->next;
            while(temp){
                if(tav->val<temp->val){
                    ans.push_back(temp->val);
                    tav=tav->next;
                    temp=tav->next;
                }
                else{
                         temp=temp->next;
                }
                
            }
            ans.push_back(0);
            tav=tav->next;


        }
        return ans;
    }
};