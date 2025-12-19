#include<iostream>
using namespace std;


class Solution{
public:
    ListNode* remove_from_list(ListNo)
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* cur = d;

        while(cur->next!=nullptr){
           if(cur->next-val == val){
            cur->next = cur->next->next;
           }
           else{
            cur=cur->next;
           }

           return d->next;
        }




    };


int main(){

    return 0;
}

    // Create a sample linked list: 1 -> 2 -> 3 -> 2 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(4);

    Solution sol;
    head = sol.remove_from_list(head, 2);

    // Print the result
    cout << "Result: ";
    while(head != nullptr){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;

    return 0;
}