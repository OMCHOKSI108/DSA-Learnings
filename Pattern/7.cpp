#include<iostream>
using namespace std;

void pattern_7(int rows){
    for(int i=0;i<rows;i++){
        for(int k=0;k<i;k++){
           cout<<"  ";
        }
        for(int j=rows-1;j>i;j--){
            cout<<"* ";
        }
        
        for(int j=rows-1;j>=i;j--){
            cout<<"* ";
        }
        cout<<endl;
    }

}

int main(){

    int rows;
    cout<<"ENTER ROWS:";
    cin>>rows;

    pattern_7(rows);
    return 0;
}

// * * * * * * * * *
//   * * * * * * *
//     * * * * *
//       * * *
//         *