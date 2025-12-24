class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        for(int i=0;i<=n;i++){
            arr.push_back(decTobin(i));
        }
        return arr;
    }

private:
    int decTobin(int n){
        int one_bin=0;
        vector<int> arr;
        stack<int> s1;

        if(n==0) return 0;

        while(n>0){
            s1.push(n%2);
            n=n/2;
        }

        while(!s1.empty()){
            arr.push_back(s1.top());
            s1.pop();
        }

        for(int i=0;i<arr.size();i++){
            if(arr[i]==1) one_bin++;
        }

        return one_bin;
    }
};


int main() {
    Solution sol;
    int n = 5;
    vector<int> result = sol.countBits(n);
    
    for(int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}

//more optimized 

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> a(n+1);
//         for(int i=1;i<=n;i++){
//             a[i]=a[i>>1]+(i&1);
//         }
//         return a;
//     }
// };
