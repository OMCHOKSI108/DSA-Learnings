string removeparenthesis(const String &s){
    string res;
    int d = 0;

    for(char ch: s){
        if(ch=='('){
            if(d>0) result+=ch;
            d++;
        }
        else{
            d--;
            if(d>0) result+=ch;
        }

    }

    return res;

}

int main() {
    string input;
    cout << "Enter a string with parentheses: ";
    getline(cin, input);
    
    string output = removeparenthesis(input);
    cout << "Result: " << output << endl;
    
    return 0;
}