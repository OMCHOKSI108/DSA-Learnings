class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);

            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;

                int freq = 0;
                bool balanced = true;

                for (int x : cnt) {
                    if (x > 0) {
                        if (freq == 0)
                            freq = x;        // first non-zero frequency
                        else if (x != freq) {
                            balanced = false;
                            break;
                        }
                    }
                }

                if (balanced) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};
