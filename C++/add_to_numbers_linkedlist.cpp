#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addnum(ListNode *L, int x)
{
    ListNode *current = L;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = new ListNode(x);
}

void printList(ListNode *L)
{
    while (L != nullptr)
    {
        cout << L->val << "  ";
        L = L->next;
    }
    cout << endl;
}

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     ListNode* dummy = new ListNode(0);
//     ListNode* current = dummy;
//     int carry = 0;
//     while (l1 != nullptr || l2 != nullptr || carry != 0) {
//         int sum = carry;
//         if (l1 != nullptr) {
//             sum += l1->val;
//             l1 = l1->next;
//         }
//         if (l2 != nullptr) {
//             sum += l2->val;
//             l2 = l2->next;
//         }
//         carry = sum / 10;
//         current->next = new ListNode(sum % 10);
//         current = current->next;
//     }
//     return dummy->next;
// }

ListNode *addTwoNum(ListNode *l1, ListNode *l2)
{
    ListNode *ans = new ListNode(0);
    ListNode *tail = ans;
    int temp = 0;

    while (l1 != nullptr || l2 != nullptr || temp != 0)
    {
        int dg1 = (l1 != nullptr) ? l1->val : 0;
        int dg2 = (l2 != nullptr) ? l2->val : 0;

        int sum = dg1 + dg2 + temp;
        int digit = sum % 10;
        temp = sum / 10;

        ListNode *newNode = new ListNode(digit);
        tail->next = newNode;
        tail = tail->next;

        l1 = (l1 != nullptr) ? l1->next : nullptr;
        l2 = (l2 != nullptr) ? l2->next : nullptr;
    }

    return ans->next;
}
int main()
{
    ListNode *L1 = new ListNode(2);
    addnum(L1, 4);
    addnum(L1, 3);

    ListNode *L2 = new ListNode(5);
    addnum(L2, 6);
    addnum(L2, 4);

    printList(L1);
    printList(L2);

    ListNode *result = addTwoNum(L1, L2);
    printList(result);

    return 0;
}

/*
Explanation: addTwoNum (adds two numbers represented by linked lists)

Algorithm summary:
- Each input list `l1` and `l2` stores a non-negative integer in reverse order
    (each node holds a single digit; head is least significant digit).
- We traverse both lists simultaneously, summing corresponding digits plus a carry
    from the previous position. The digit to store in the result is `sum % 10` and
    the new carry is `sum / 10`.
- We use a dummy head (`ans`) and a `tail` pointer to build the result list
    easily without special-casing the head node.

Key variables:
- `ans`: dummy head node (value 0) whose `next` points to the actual result.
- `tail`: pointer to the last node in the result list (initially `ans`).
- `temp`: the carry (0 or 1, but using int allows larger carries if digits were larger).

Loop invariant:
- At the start of each loop iteration, `tail` points to the last node of the
    partially-built result, and `temp` contains the carry to add to the next digit.

Detailed step-by-step example (from `main`):
Input lists (digits shown left-to-right as stored, which is least->most significant):
- l1: 2 -> 4 -> 3   (represents 342)
- l2: 5 -> 6 -> 4   (represents 465)

We expect: 342 + 465 = 807, so result should be 7 -> 0 -> 8

Iteration table (each row is one loop iteration):
| Iter | dg1 | dg2 | temp_in | sum = dg1+dg2+temp | digit = sum % 10 | temp_out | result list (so far) |
|------|-----|-----|---------|-------------------:|------------------:|---------:|---------------------|
|  1   |  2  |  5  |    0    |                7   |                 7 |        0 | 7                   |
|  2   |  4  |  6  |    0    |               10   |                 0 |        1 | 7 -> 0              |
|  3   |  3  |  4  |    1    |                8   |                 8 |        0 | 7 -> 0 -> 8         |

After loop: both lists null and temp == 0, so we exit. `ans->next` is head of
the result list: 7 -> 0 -> 8 as expected.

Edge cases handled by this code:
- Different lengths: when one list is shorter we treat missing digits as 0
    (dg1 or dg2 computed with conditional operator).
- Final carry: loop continues while `temp != 0` so a leftover carry (e.g., 5+5)
    will create an extra digit.

Complexity:
- Time: O(max(n, m)) where n and m are lengths of `l1` and `l2`. We visit each
    node of both lists at most once.
- Space: O(max(n, m)) for the output list (we allocate a new node for each
    output digit). Auxiliary space (excluding output) is O(1) — a few variables.

Notes / improvements:
- The code uses `new` for nodes; callers should delete nodes to avoid leaks.
- The commented alternative `addTwoNumbers` implementation (above) is
    functionally equivalent and uses a `dummy` created on heap instead of stack.
*/
