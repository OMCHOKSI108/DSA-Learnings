#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy;
        ListNode *tail = &dummy;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }

    void printlist(ListNode *L)
    {
        while (L)
        {
            cout << L->val << " ";
            L = L->next;
        }
        cout << endl;
    }
};

int main()
{
    // Create first list: 1 -> 2 -> 4
    ListNode *l1 = new ListNode(1, new ListNode(2, new ListNode(4)));

    // Create second list: 1 -> 3 -> 4
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    Solution s1;
    ListNode *merged = s1.mergeTwoLists(l1, l2);

    s1.printlist(merged);

    // Clean up memory (optional for small test cases)
    while (merged)
    {
        ListNode *temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}

/*
### High-Level Explanation

The goal of the `mergeTwoLists` function is to combine two sorted linked lists (`list1` and `list2`) into a single, new sorted linked list.

The strategy is to iterate through both lists simultaneously, comparing their nodes' values at each step. The smaller-valued node is appended to a new merged list. A `dummy` node is used as a starting point for this new list to simplify the code, and a `tail` pointer keeps track of the last node in the merged list, making it easy to append the next node.

### Detailed Code Breakdown (`mergeTwoLists`)

1.  **`ListNode dummy;`**
    *   Creates a temporary `ListNode` on the stack. This node acts as a placeholder to simplify adding the first element to our merged list. We don't have to write special code for the head of the new list; we just start appending to `dummy`.

2.  **`ListNode* tail = &dummy;`**
    *   Creates a pointer `tail` that will always point to the last node of the merged list. Initially, it points to the `dummy` node.

3.  **`while (list1 && list2)`**
    *   This loop continues as long as there are still nodes to process in *both* lists.

4.  **`if (list1->val < list2->val)`**
    *   Compares the values of the current nodes of `list1` and `list2`.
    *   If `list1`'s value is smaller, `tail->next` is pointed to the `list1` node. Then, `list1` is advanced to its next node (`list1 = list1->next`).

5.  **`else`**
    *   If `list2`'s value is less than or equal to `list1`'s, `tail->next` is pointed to the `list2` node. Then, `list2` is advanced (`list2 = list2->next`).

6.  **`tail = tail->next;`**
    *   After linking the chosen node, the `tail` pointer is moved forward to that newly added node, so it's ready for the next append operation.

7.  **`tail->next = list1 ? list1 : list2;`**
    *   After the `while` loop finishes, one of the lists will be empty, but the other might still have remaining nodes.
    *   Since the lists are sorted, any remaining nodes are guaranteed to be larger than all the nodes already in the merged list.
    *   This line efficiently appends the entire remainder of the non-empty list (`list1` or `list2`) to the end of the merged list.

8.  **`return dummy.next;`**
    *   The `dummy` node itself is just a temporary placeholder. The actual merged list starts at `dummy.next`. This is what the function returns.

---

### Step-by-Step Traversal

Let's trace the execution with the example from `main`:
*   `list1`: `1 -> 2 -> 4`
*   `list2`: `1 -> 3 -> 4`
*   `dummy`: `[val: 0, next: nullptr]`
*   `tail`: points to `dummy`

**Initial State:**
*   `merged_list` (via `dummy.next`): `(empty)`
*   `l1` points to `1`.
*   `l2` points to `1`.

**Iteration 1:**
*   `list1->val` (1) is not less than `list2->val` (1). The `else` block runs.
*   `tail->next` is set to `l2` (the node with value 1).
*   `merged_list`: `1`
*   `l2` advances to point to `3`.
*   `tail` advances to the node just added (the `1` from `l2`).

**Iteration 2:**
*   `list1->val` (1) is less than `list2->val` (3). The `if` block runs.
*   `tail->next` is set to `l1` (the node with value 1).
*   `merged_list`: `1 -> 1`
*   `l1` advances to point to `2`.
*   `tail` advances to the node just added (the `1` from `l1`).

**Iteration 3:**
*   `list1->val` (2) is less than `list2->val` (3). The `if` block runs.
*   `tail->next` is set to `l1` (the node with value 2).
*   `merged_list`: `1 -> 1 -> 2`
*   `l1` advances to point to `4`.
*   `tail` advances to the node just added (the `2` from `l1`).

**Iteration 4:**
*   `list1->val` (4) is not less than `list2->val` (3). The `else` block runs.
*   `tail->next` is set to `l2` (the node with value 3).
*   `merged_list`: `1 -> 1 -> 2 -> 3`
*   `l2` advances to point to `4`.
*   `tail` advances to the node just added (the `3` from `l2`).

**Iteration 5:**
*   `list1->val` (4) is not less than `list2->val` (4). The `else` block runs.
*   `tail->next` is set to `l2` (the node with value 4).
*   `merged_list`: `1 -> 1 -> 2 -> 3 -> 4`
*   `l2` advances to `nullptr`.
*   `tail` advances to the node just added (the `4` from `l2`).

**End of Loop:**
*   The `while (list1 && list2)` condition is now false because `list2` is `nullptr`.

**Final Append:**
*   `tail->next = list1 ? list1 : list2;` is executed.
*   `list1` is not null (it points to the node with value 4), so `tail->next` is set to the rest of `list1`.
*   `merged_list`: `1 -> 1 -> 2 -> 3 -> 4 -> 4`

**Return:**
*   The function returns `dummy.next`, which is the head of the final merged list.
*/
