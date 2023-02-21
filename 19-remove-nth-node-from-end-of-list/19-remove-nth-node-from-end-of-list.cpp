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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr;
        int count = 0;
        ListNode* nptr = head;
        
        
        while(count < n){
            nptr = nptr->next;
            count++;
        }
        if(!nptr)
            return head->next;
       
        ptr = head;
        while(nptr->next!=nullptr){
            ptr = ptr->next;
            nptr= nptr->next;
        }
        
        ptr->next = ptr->next->next;
        
        return head;
        
    }
};