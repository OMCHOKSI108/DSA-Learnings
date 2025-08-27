//#OUTPUT
// ENTER ROWS :5
// 1 
// 2 2 
// 3 3 3 
// 4 4 4 4 
// 5 5 5 5 5 

#include<iostream>
using namespace std;

void pattern_2(int rows){
   
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }


}
int main(){
    int rows;
    cout<<"ENTER ROWS :";
    cin>>rows;

    pattern_2(rows);

    return 0;
}

