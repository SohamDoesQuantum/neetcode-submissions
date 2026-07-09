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
        if(!head || !head->next) return nullptr;
        head = reverseList(head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        for(int i = 1; i<n&&curr;i++){
            prev = curr;
            curr = curr->next;
        }
        
        if(curr)prev->next = curr->next;
        return reverseList(dummy->next);


    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* n= curr->next;
            curr->next = prev;
            prev = curr;
            curr =  n;
        }
        return prev;
    }
};
