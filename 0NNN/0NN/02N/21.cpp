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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* answer = l1;
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }
        if(l1->val > l2->val) {
            l1 = l2;
            l2 = answer;
            answer = l1;
        }
        while(l1->next) {
            if(l2 && l2->val < l1->next->val) {
                ListNode* tmp = l2->next;
                l2->next = l1->next;
                l1->next = l2;
                l2 = tmp;
            } else {
                l1 = l1->next;
            }
        }
        l1->next = l2;
        return answer;
    }
};
