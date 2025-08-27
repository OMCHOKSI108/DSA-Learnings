#include<iostream>
using namespace std;

void pattern_04(int rows){
     
    for(int i=0;i<rows;i++){
        for(int k=rows-1;k>=i;k--){
            cout<<"  ";
        }

        for(int j=0;j<=i;j++){
            cout<<j+1;
            cout<<" ";
        }
        cout<<endl;
    }
    
}

int main(){

    int rows;
    cout<<"ENTER ROWS :";
    cin>>rows;

    pattern_04(rows);
    return 0;
}

// ENTER ROWS :5
//           1
//         1 2
//       1 2 3
//     1 2 3 4
//   1 2 3 4 5