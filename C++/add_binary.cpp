#include<iostream>
#include<string.h>
#include<cmath>

using namespace std;

class Solution{
    public:

    string addBinary(string a,string b){
        string binary="";
        int a1=0;
        int b1=0;

        for(int i = a.size() - 1, p = 0; i >= 0; p++, i--) {
            if(a[i]=='1'){
                a1+=pow(2,p);
            }
        }

        for(int i = b.size() - 1, p = 0; i >= 0; p++, i--) {
            if(b[i]=='1'){
                b1+=pow(2,p);
            }
        }

        int sum = a1+b1;
        if(sum=='0'){
            binary="0";
        }
        else{

            while(sum>0){
                int bit = sum % 2;
                binary = char('0'+bit) + binary;
                sum/=2;

            }
        }


        



        
        return binary;
    }

};

/*

class Solution {
public:

    string addBinary(string a, string b) {
        
        
        if(b.size() > a.size()) swap(a,b);
        
        
        while(b.size() < a.size()) b = "0" + b;

        int carry = 0;

        string res = "";

        for(int i = b.size()-1; i >= 0 ; --i)
        {
             
             if(b[i] == '1' && a[i]=='1')
             {

                if(carry == 0) res = "0" + res;
                
                else    res = "1" + res;
                    
                carry = 1;
             }

             else if(b[i] =='0' && a[i] =='0')
             {

                if(carry == 0) res = "0" + res;
                 
                else
                {
                    res = "1" + res;
                    carry = 0;
                }
             }

             else if((b[i]=='0' && a[i]=='1') || (b[i]=='1' && a[i] == '0'))
             {
                 
                if(carry == 0) res = "1" + res;
                 
                else res = "0" + res;
                 
             }
             
        }
        
        if(carry == 1) res = "1" + res;
        
        return res;
    }
};

*/


int main(){
    string a="11";
    string b="1";

    Solution s1;
    string ans = s1.addBinary(a,b);
    cout<<ans;


    
    return 0;

}



