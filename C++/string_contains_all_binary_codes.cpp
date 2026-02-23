class Solution {
public:
    bool hasAllCodes(string s, int k) {
       if(s.length() < k){
        return false;
       }
        
    unordered_set<string> us;

    for (int i = 0; i <= s.length() - k; i++) {
        string sub = s.substr(i, k);
        us.insert(sub);
    }

    if(us.size()!=pow(2,k)){
        return false;
    }

    return true;


    }
};
