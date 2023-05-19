class Solution {
public:
  bool isValid(string s)
{
    // create a stack to store opening brackets
    stack<char> st;

    // loop through each character in the input string
    for(char &ch:s)
    {
        // if current character is an opening bracket, push the corresponding closing bracket onto the stack
        if(ch=='(')
           st.push(')');
        else if(ch=='{')
           st.push('}');
        else if(ch=='[')
           st.push(']');
        // if current character is a closing bracket, check if the top of the stack contains its corresponding opening bracket
        else
        {
            // if the stack is empty or the top of the stack does not contain the corresponding opening bracket, the input string is invalid
            if(st.empty() || ch!=st.top())
               return false;
            // if the top of the stack contains the corresponding opening bracket, pop it from the stack
            else
               st.pop();
        }
    }
    // if the stack is empty, the input string is valid; otherwise, it is invalid
    return st.empty();
}

};