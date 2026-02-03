class Solution {
  public:
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL)
            return true;

        vector<int> arr;
        Node *temp = head;

        
        while (temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int l = 0;
        int r = arr.size() - 1;
 
        while (l < r) {
            if (arr[l] != arr[r]) {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};
