class Solution {
public:
    string largestEven(string s) {
        int i = -1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '2') i = j;
        }
        if (i == -1) return "";
        return s.substr(0, i + 1);
    }
};


// example :

// intput = 1112
// output = 1112

// intput = 221
// output = 22

  

  
  
