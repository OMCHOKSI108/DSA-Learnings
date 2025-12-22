#include<iostream>
using namespace std;


class Solution{

    public:
    bool isPalidrome(ListNode* head){
        if(!head || !head->next) return true;


        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* cur = slow;
        ListNode* nxt;
        ListNode* prev=NULL;

        while(cur){
            nxt = cur->next;
            cur->next = prev;
            prev=cur;
            cur=nxt;

        }

        ListNode* l=head;
        ListNode* r = prev;

        while(r){
            if(l->val!=r->val){
                return false;
            }

            l = l->next;
            r = r->next;

        }

        return true;

        
        
    }

};



int main(){


    return 0;
}
// Example test case
ListNode* head = new ListNode(1);
head->next = new ListNode(2);
head->next->next = new ListNode(2);
head->next->next->next = new ListNode(1);

Solution sol;
cout << (sol.isPalidrome(head) ? "true" : "false") << endl;

return 0;