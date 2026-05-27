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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        if(lists.size()==1) return lists[0];
        int n = lists.size();
        vector<ListNode*> left (lists.begin(),lists.begin()+n/2);
        vector<ListNode*> right(lists.begin()+n/2,lists.end());
        ListNode* a = mergeKLists(left);
        ListNode* b = mergeKLists(right);
        return merge(a,b);
    }

    ListNode* merge(ListNode* a, ListNode*b){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(a && b){
            if(a->val<b->val){
                curr->next = a;
                a = a->next;
                
            }
            else{
                curr->next  = b;
                b = b->next;
            }
            curr = curr->next;
        }
        curr->next = (a)?a:b;
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};
