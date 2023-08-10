#include <bits/stdc++.h>
using namespace std;

void prefixToInfix(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];

        if (isalnum(c))
        {
            string res(1, c);
            st.push(res);
        }

        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    cout << st.top() << "\n";
}

int main()
{
    string exp;
    cin >> exp;
    cout << "\n";

    prefixToInfix(exp);

    return 0;
}
