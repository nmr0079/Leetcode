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
    int pairSum(ListNode* head) {
        int twinSum = INT_MIN;
        ListNode* temp = head;
        ListNode* forPotr = head;
        ListNode* revPotr = head;
       
        
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        int c = 0;
        while(c < n/2){
            revPotr = revPotr->next;
            c++;
        }
        
        //Reversing half of the linked list
        
        //step 1
        ListNode* prev_p = NULL;
        ListNode* current_p = revPotr;
        ListNode* next_p;
       
       //step 2
        while(current_p) {

            next_p = current_p->next;
            current_p->next = prev_p;
            
            prev_p = current_p;
            current_p = next_p;
        }

        revPotr = prev_p; //step 3
        
        int i = 0;
        while(i <= (n/2) - 1){
            twinSum = max(twinSum, forPotr->val+revPotr->val);
            forPotr = forPotr->next;
            revPotr = revPotr->next;
            ++i;
        }
        return twinSum;
    }
};