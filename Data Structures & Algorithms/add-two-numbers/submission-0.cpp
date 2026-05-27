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
        int sum = 0;
        int carry = 0;
        ListNode* prev = nullptr;
        ListNode* newhead = prev;
        while (l1 && l2) {
            sum = (carry + l1->val + l2->val) % 10;
            carry = (carry+ l1->val + l2->val) / 10;
            ListNode* node = new ListNode(sum);
            if (!prev) {newhead = node;}
            else prev->next = node;
            prev = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int total = l1->val+carry;
            ListNode* node = new ListNode(total%10);
            carry = total/10;
            prev->next = node;
            prev = node;
            l1 = l1->next;
        }
        while(l2){
           int total = l2->val+carry;
            ListNode* node = new ListNode(total%10);
            carry = total/10;
            prev->next = node;
            prev = node;
            l2 = l2->next;
        }
        if(carry>0){
            ListNode* node = new ListNode(carry);
            prev->next = node;
        }
        return newhead;
    }
};
