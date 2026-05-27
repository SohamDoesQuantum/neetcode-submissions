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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        ListNode* dummy = new ListNode(-1,head);
        ListNode* lp = dummy;
        for (int i = 1; i <= left - 1; i++) {
            lp = lp->next;
        }
        ListNode* r = dummy;
        for (int i = 1; i <= right; i++) {
            r = r->next;
        }
        ListNode* rn = r->next;
        ListNode* l = lp->next;
        r->next = nullptr;
        auto [new_head,new_tail] = Reverse_List(l);
        lp->next = new_head; new_tail->next = rn;
        ListNode* actual_head = dummy->next;
        delete dummy;
        return actual_head;


        
    }
private:
    pair<ListNode*,ListNode*>Reverse_List(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return {prev,head};
    }
};