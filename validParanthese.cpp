bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;

    for (char c : expression)
    {
        if (c == '}')
        {
            if (s.empty() || s.top() != '{')
                return false;
            s.pop();
        }
        else if (c == ']')
        {
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
        }
        else if (c == ')')
        {
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
        }
        else
            s.push(c);
    }
    return s.empty();
}