// OUTPUT :
// ENTER ROWS :5
// *
// * *
// * * *
// * * * *
// * * * * *

#include <iostream>
using namespace std;

void pattern_1(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int rows;
    cout << "ENTER ROWS :";
    cin >> rows;

    pattern_1(rows);
}


