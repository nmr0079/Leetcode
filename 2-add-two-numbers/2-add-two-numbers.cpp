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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L3 = new ListNode(0);
        ListNode* res = L3;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val+l2->val+carry;
            if(sum > 9){
                L3->next = new ListNode(sum%10);
                carry = 1;
                L3 = L3->next;
            }
            else{
                L3->next = new ListNode(sum);
                carry = 0;
                L3 = L3->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr){
            int sum = l1->val+carry;
            if(sum > 9){
                L3->next = new ListNode(sum%10);
                carry = 1;
                L3 = L3->next;
            }
            else{
                L3->next = new ListNode(sum);
                carry = 0;
                L3 = L3->next;
            }
            l1 = l1->next;
        }
        
         while(l2 != nullptr){
            int sum = l2->val+carry;
            if(sum > 9){
                L3->next = new ListNode(sum%10);
                carry = 1;
                L3 = L3->next;
            }
            else{
                L3->next = new ListNode(sum);
                carry = 0;
                L3 = L3->next;
            }
            l2 = l2->next;
        }
        
        if(carry){
            L3->next = new ListNode(carry);
        }
        
        return res->next;
        
    }
};