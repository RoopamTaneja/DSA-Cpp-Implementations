#include <bits/stdc++.h>
using namespace std;

string postToPre(string post_exp)
{
    stack<string> s;
    int length = post_exp.size();

    for (int i = 0; i < length; i++)
    {

        // check if symbol is operator
        if (!isalnum(post_exp[i]))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            string temp = post_exp[i] + op1 + op2;

            s.push(temp);
        }

        // if symbol is an operand
        else
            s.push(string(1, post_exp[i]));
    }
    return s.top();
}

// T.C : O(n), aux S.C : O(n)

int main()
{
    string exp;
    cin >> exp;
    cout << "\n";
    cout << postToPre(exp) << "\n";
    return 0;
}
