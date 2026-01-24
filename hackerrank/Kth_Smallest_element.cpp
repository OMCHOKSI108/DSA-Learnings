class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : arr) {
            pq.push(x);
        }

        while (--k) {
            pq.pop();
        }

        return pq.top();
    }
};
