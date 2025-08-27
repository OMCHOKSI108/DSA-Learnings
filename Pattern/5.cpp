#include<iostream>
using namespace std;
void pattern_5(int rows){
   
    for(int i=0;i<rows;i++){
        for(int k=rows-1;k>i;k--){
            cout<<"  ";
        }
        for(int j=0;j<=i;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }

}

int main(){
   
    int rows;
    cout<<"ENTER ROWS:";
    cin>>rows;

    pattern_5(rows);

    return 0;

}

//           1
//         2 2
//       3 3 3
//     4 4 4 4
//   5 5 5 5 5