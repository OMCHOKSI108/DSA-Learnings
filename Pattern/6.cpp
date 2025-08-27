//         * 
//       * * * 
//     * * * * * 
//   * * * * * * * 
// * * * * * * * * * 

#include<iostream>
using namespace std;

void pattern_6(int rows){
   for(int i=0;i<rows;i++){
    for(int k=rows-1;k>i;k--){
        cout<<"  ";
    }
    for(int j=0;j<=i;j++){
        cout<<"* ";
        
    }
    for(int j=0;j<i;j++){
        cout<<"* ";
        
    }
    cout<<endl;
   }

}
int main(){
    int rows;
    cout<<"ENTER ROWS:";
    cin>>rows;

    pattern_6(rows);


    return 0;
}

