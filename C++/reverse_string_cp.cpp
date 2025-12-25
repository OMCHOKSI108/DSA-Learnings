class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++)
            st.push(s[i]);

        for(int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};


int main(){
    vector<string> s = "PENTAGON";
    cout<<reverseString(s);


    return 0;
}


// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int l = 0, r = s.size() - 1;
//         while(l < r) {
//             char t = s[l];
//             s[l] = s[r];
//             s[r] = t;
//             l++;
//             r--;
//         }    
//     }
// };
