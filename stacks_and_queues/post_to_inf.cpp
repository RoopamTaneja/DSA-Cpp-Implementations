#include <bits/stdc++.h>
using namespace std;

void postfixToInfix(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalnum(c))
        {
            string res(1, c);
            st.push(res);
        }

        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push("(" + op1 + c + op2 + ")");
        }
    }
    cout << st.top() << "\n";
}

// T.C : O(n), aux S.C : O(n)

int main()
{
    string exp;
    cin >> exp;
    cout << "\n";

    postfixToInfix(exp);

    return 0;
}
