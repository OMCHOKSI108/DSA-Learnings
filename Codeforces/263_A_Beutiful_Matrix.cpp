#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int rows = 5, cols = 5;
    vector<vector<int>> arr(5, vector<int>(5));

    int i_pos = 0, j_pos = 0;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                i_pos = i;
                j_pos = j;
            }
        }
    }


    int operations = abs(i_pos - 2) + abs(j_pos - 2);

    cout << operations << endl;

    return 0;
}
