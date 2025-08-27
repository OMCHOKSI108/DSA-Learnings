//#OUTPUT
// ENTER ROWS :5
// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5 

#include<iostream>
using namespace std;

void pattern_3(int rows){
   
    for(int i=0;i<rows;i++){
        for(int j=0;j<=i;j++){
            cout<<j+1<<" ";
        }
        cout<<endl;
    }


}
int main(){
    int rows;
    cout<<"ENTER ROWS :";
    cin>>rows;

    pattern_3(rows);

    return 0;
}

