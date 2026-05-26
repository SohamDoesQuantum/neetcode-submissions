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
        if(!head) return nullptr;
        int len = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            len++;
        }
        cout<<len;
        int k = len-n;
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        curr = head;
        while(k--){
            prev = curr;
            curr = curr->next;
        }
       
        prev->next = curr->next;
        delete curr;
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;

    }
};
