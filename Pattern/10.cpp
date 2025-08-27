#include<iostream>
using namespace std;

void pattern_10(int rows){
  for(int i=0;i<rows;i++){

    for(int j=0;j<rows;j++){

    if(j==0 || i==0 || j==rows-1 || i==rows-1){
        cout<<"* ";
    }
    else{
        cout<<"  ";
    }

    }
      cout<<endl;
   }

}
int main(){
    int rows;
    cout<<"ENTER ROWS:";
    cin>>rows;
    pattern_10(rows);

    return 0;
}

// * * * * *
// *       *
// *       *
// *       *
// * * * * *
