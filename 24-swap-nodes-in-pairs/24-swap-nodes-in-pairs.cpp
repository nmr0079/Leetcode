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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* curr;
        ListNode* prev = new ListNode(); //a dummy node initially
        prev->next = head;
        ListNode* dummy = prev;
        curr = head;
        ListNode* next = curr->next;
        
        while(curr != NULL && curr->next != NULL){
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            
            prev = curr;
            curr = curr->next;
        }
        
        return dummy->next;
        
    }
};