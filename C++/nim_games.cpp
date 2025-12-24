class Solution {
public:
    bool canWinNim(int n) {
    if(n%4==0){
        return false;
    }

    return true;
    }
};

int main() {
    Solution solution;
    
    cout << "n=1: " << solution.canWinNim(1) << endl;
    cout << "n=4: " << solution.canWinNim(4) << endl;
    cout << "n=5: " << solution.canWinNim(5) << endl;
    
    return 0;
}