/* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not. */
class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
                charStack.push(s[i]);
            }
            else {
                if(charStack.empty() ||
                   (s[i]==')' && charStack.top()!='(') ||
                   (s[i]=='}' && charStack.top()!='{') ||
                   (s[i]==']' && charStack.top()!='[') ) {
                       return false;
                   }
                charStack.pop();
            }
        }
        return charStack.empty();
    }
};
