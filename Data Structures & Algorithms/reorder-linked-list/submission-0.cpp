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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head1 = slow->next;
        slow->next = nullptr;
        head1 = reverse_List(head1);
        while(head1 && head){
            ListNode* t = head->next;
            head->next = head1;
            ListNode* t1 = head1->next;
            head1->next = t;
            head = t;
            head1 = t1;
        }
        
    }
    private:
    ListNode* reverse_List(ListNode* head1){
        ListNode* prev = nullptr;
        ListNode* curr = head1;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
};
