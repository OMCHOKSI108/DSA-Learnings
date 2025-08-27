#include<iostream>
using namespace std;

void pattern_8(int rows){
    for(int i=rows;i>0;i--){
        for(int j=0;j<i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int rows;
    cout<<"ENTER ROWS :";
    cin>>rows;
    pattern_8(rows);
    return 0;
}

// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1