#include<iostream>
using namespace std;

void pattern_13(int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            if(i%2==1){
                cout<<1<<" ";
             }
             else{
                cout<<0<<" ";
             }

        }
        cout<<endl;
    }
   
}

int main(){

    int rows;
    cout<<"ENTER ROWS :";
    cin>>rows;

    pattern_13(rows);
    return 0;
}

