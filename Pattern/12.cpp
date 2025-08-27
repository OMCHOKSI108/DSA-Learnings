#include<iostream>
using namespace std;

void pattern_12(int rows){
 
    for(int i=0;i<rows;i++){
        for(int k=0;k<i;k++){
            cout<<" ";
        }
        for(int j=0;j<rows;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
   int rows;
   cout<<"ENTER ROWS :";
   cin>>rows;
   pattern_12(rows);

    return 0;
}