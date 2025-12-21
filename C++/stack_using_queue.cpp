#include<iostream>
using namespace std;

class MyStack{
    queue<int> q;
    MyStack(){}

    void push(int x){
        q.push(x);
        int n=q.size();
        while(n>1){
            q.push(q.front());
            q.pop()
            n--;
        }
    }

    int pop(){
        x = q.front();
        q.pop();
        return x;

    }

    int top(){
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main(){


    return 0;
}
MyStack st;
st.push(1);
st.push(2);
st.push(3);

cout << st.top() << endl;    // Output: 3
st.pop();
cout << st.top() << endl;    // Output: 2
st.pop();
cout << st.top() << endl;    // Output: 1
st.pop();

cout << (st.empty() ? "Stack is empty" : "Stack has elements") << endl;