#include <bits/stdc++.h>
using namespace std;

string preToPost(string exp)
{
    stack<string> s;
    int length = exp.size();

    for (int i = length - 1; i >= 0; i--)
    {

        // check if symbol is operator
        if (!isalnum(exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + exp[i];
            s.push(temp);
        }

        // if symbol is an operand
        else
            s.push(string(1, exp[i]));
    }
    return s.top();
}

// T.C : O(n), aux S.C : O(n)

int main()
{
    string exp;
    cin >> exp;
    cout << "\n";
    cout << preToPost(exp) << "\n";
    return 0;
}
