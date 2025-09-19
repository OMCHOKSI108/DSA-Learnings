#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// using namespace std;

//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         vector<int> st;
//         stack<int> str;

//         // The following loop was unnecessary and has been removed.

//         for(int a : asteroids) {
//             bool destroyed = false;

//             while(!st.empty() && st.back() > 0 && a < 0) {
//                 if(st.back() < -a) {

//                     st.pop_back();
//                     continue;
//                 }
//                 else if(st.back() == -a) {

//                     st.pop_back();
//                 }
//                 destroyed = true;
//                 break;
//             }

//             if(!destroyed) st.push_back(a);
//         }
//         return st;
//     }
//     int main() {
//         vector<int> asteroids = {5,10,-5};

//         vector<int> result = asteroidCollision(asteroids);

//         cout << "Asteroids after collisions: ";
//         for(int a : result) {
//             cout << a << " ";
//         }
//         cout << endl;

//         return 0;
//     }

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{

    stack<int> st;
    for (int a : asteroids)
    {
        bool destroyed = false;
        while (!st.empty() && st.top() > 0 && a < 0)
        {
            if (st.top() < -a)
            {
                st.pop();
                continue;
            }
            else if (st.top() == -a)
            {
                st.pop();
            }
            destroyed = true;
            break;
        }
        if (!destroyed)
            st.push(a);
    }
    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    vector<int> asteroids = {5, 10, -5};

    vector<int> result = asteroidCollision(asteroids);

    cout << "Asteroids after collisions: ";
    for (int a : result)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}