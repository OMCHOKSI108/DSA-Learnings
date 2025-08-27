#include<iostream>
using namespace std;

void pattern_11(int rows){
    for(int i=0;i<rows;i++){
       for(int k=rows-1;k>=i;k--){
        cout<<"  ";
       }
       for(int j=0;j<2*i+1;j++){
        cout<<i+1<<" ";
       }
       cout<<endl; 
    }

}

int main(){
   int rows;
   cin>>rows;

   pattern_11(rows);

    return 0 ;
}

