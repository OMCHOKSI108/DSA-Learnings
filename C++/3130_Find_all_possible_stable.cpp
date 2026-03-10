class Solution {
public:
    int M = 1e9 + 7;
    int t[1001][1001][2];

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(t,-1,sizeof(t));

        int startwithOne = 0;
        int startwithZero = 0;

        for(int len = 1; len <= min(one, limit); len++){
            startwithOne = (startwithOne + solve(one-len, zero, true, limit)) % M;
        }

        for(int len = 1; len <= min(zero, limit); len++){
            startwithZero = (startwithZero + solve(one, zero-len, false, limit)) % M;
        }

        return (startwithOne + startwithZero) % M;
    }

    int solve(int OnesLeft,int ZerosLeft,bool LastWasOne,int limit){

        if(OnesLeft == 0 && ZerosLeft == 0)
            return 1;

        if(t[OnesLeft][ZerosLeft][LastWasOne] != -1)
            return t[OnesLeft][ZerosLeft][LastWasOne];

        int result = 0;

        if(LastWasOne){ 
            for(int len = 1; len <= min(ZerosLeft, limit); len++){
                result = (result + solve(OnesLeft, ZerosLeft-len, false, limit)) % M;
            }
        }
        else{
            for(int len = 1; len <= min(OnesLeft, limit); len++){
                result = (result + solve(OnesLeft-len, ZerosLeft, true, limit)) % M;
            }
        }

        return t[OnesLeft][ZerosLeft][LastWasOne] = result;
    }
};
