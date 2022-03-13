// Balanced Brackets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;


bool isBalancedBrackets(const string& input)
{
    // No need to continue if input string is empty
    if (input.empty())
        return false;


    // Solve using a stack
    // Ignore all non-brackets, make sure brackets are properly balanced
    stack<char> st;
    for (auto ch : input)
    {
        switch (ch)
        {
        case '{':
        case '[':
        case '(':
            st.push(ch);
            break;
        case '}':
        case ']':
        case ')':
            // Check to make sure the stack has content before checking top
            if (!st.empty())
            {
                if ((st.top() == '{' && ch == '}') ||
                    (st.top() == '[' && ch == ']') ||
                    (st.top() == '(' && ch == ')'))
                {
                    st.pop();
                }
                else
                {
                    // Unbalanced bracket found
                    return false;
                }
            }
            break;
        }
    }

    // All brackets have been balanced if stack is empty
    return st.empty();
}


int main()
{
    cout << "{[()]} isBalanced :" << isBalancedBrackets("{[()]}") << endl;  // bracket balanced
    cout << "{a()]} isBalanced :" << isBalancedBrackets("{a()]}") << endl;  // a is ignored but brackets are not properly balanced
    cout << "{[a()]} isBalanced :" << isBalancedBrackets("{[a()]}") << endl;  // a is ignored, brackets are properly balanced
}
