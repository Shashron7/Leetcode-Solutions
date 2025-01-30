/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p=head;//fast
        ListNode* q=head; //slow

        bool check=false;

        while(p!=NULL && q!=NULL)
        {
            if(p==q && check) return true;
            p=p->next;
            if(q->next)q=q->next->next;
            else return false;

            check=true;
        }

        return false;
    }
};