#include<iostream>
using namespace std;
void pattern_9(int rows){
  
    for(int i=0;i<rows;i++){
        
        for(int k=0;k<=i;k++){
            cout<<"  ";
        }
        for(int j=rows-1;j>i;j--){
            cout<<i+1<<" ";
        }
        for(int j=rows-1;j>=i;j--){
            cout<<i+1<<" ";
        }

        cout<<endl;

    }
    

}

int main(){

    int rows;
    cout<<"ENTER ROWS:";
    cin>>rows;

    pattern_9(rows);
    return 0;
}

// 1 1 1 1 1 1 1 1 1
//   2 2 2 2 2 2 2
//     3 3 3 3 3
//       4 4 4
//         5