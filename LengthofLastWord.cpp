/* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5. */
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(!s || s[0]=='\0') return 0;
        int num = s[0]==' '?0:1;
        bool bReset = true;
        if(s[1]=='\0') return s[0]==' '?0:1;
        for(int i=1; s[i]!='\0'; i++) {
            if(s[i]!=' ') {
                if(s[i-1]==' ') {
                    num = 1;
                } else {
                    num++;
                }
            }
        }
        return num;
    }
};
