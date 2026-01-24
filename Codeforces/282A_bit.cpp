#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = 0;
    vector<string> str;

    while (n--) {
        string c;
        cin >> c;
        str.push_back(c);
    }

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == "++X" || str[i] == "++x") {
            ++x;
        }
        else if (str[i] == "--X" || str[i] == "--x") {
            --x;
        }
        else if (str[i] == "X++" || str[i] == "x++") {
            x++;
        }
        else if (str[i] == "X--" || str[i] == "x--") {
            x--;
        }
    }

    cout << x << endl;
    return 0;
}
