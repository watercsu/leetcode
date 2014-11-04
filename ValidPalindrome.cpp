/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int begin=0,end=s.length()-1;
        while(begin < end) {
            if(!isalnum(s[begin])) {
                begin++;
            } else if(!isalnum(s[end])) {
                end--;
            } else if(toupper(s[begin++])!=toupper(s[end--])) {
                    return false;
            }
        }
        return true;
    }
};
