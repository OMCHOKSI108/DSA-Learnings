class Solution {
public:
    int numSteps(string s) {
        return CountSteps(s, 0);
    }

    long long Decimal(string s) {
        long long value = 0;
        for(char c : s) {
            value = value * 2 + (c - '0');
        }
        return value;
    }

    int CountSteps(string s, int cnt) {
      
        if (s == "1") {
            return cnt;
        }

        
        if (s.back() == '0') {
            s.pop_back();
            return CountSteps(s, cnt + 1);
        }
        else {
        
            s = addOne(s);
            return CountSteps(s, cnt + 1);
        }
    }

    string addOne(string s) {
        int i = s.size() - 1;

        while (i >= 0 && s[i] == '1') {
            s[i] = '0';
            i--;
        }

        if (i >= 0) {
            s[i] = '1';
        } else {
            s = "1" + s;
        }

        return s;
    }
};
