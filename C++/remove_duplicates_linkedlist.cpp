// 83. Remove Duplicates from Sorted List
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:


// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.

// Code:

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head; // If the list is empty, return null

    ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) {
            // Duplicate found, skip the next node
            ListNode* temp = current->next;
            current->next = current->next->next;
            delete temp; // Free memory of the duplicate node
        } else {
            // Move to the next distinct element
            current = current->next;
        }
    }

    return head; // Return the modified list
}

int main(){

    return 0;
}