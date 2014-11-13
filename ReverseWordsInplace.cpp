/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
class Solution {
public:
    void reverseWords(string &s) {
    	s.erase(0, s.find_first_not_of(" "));
    	s.erase(s.find_last_not_of(" ") + 1);
    	int len = s.length(), low = 0, high = len - 1;
    	if (s.find(' ') != string::npos) {
    		for (int i = 0, j = high; i<j; i++, j--){
    			char tmp = s[i];
    			s[i] = s[j];
    			s[j] = tmp;
    		}
    		high = 0;
    		while (high < len) {
    			for (; s[high] != ' '&&high < len; high++);			
    			for (int i = low, j = high - 1; i < j; i++, j--) {
    				char tmp = s[i];
    				s[i] = s[j];
    				s[j] = tmp;
    			}
    			if (high < len) {
    				low = ++high;
    				for (; s[high] == ' '; high++);
    				s.erase(low, high - low);
    				len = len - (high - low);
    				high = low;
    			}
    		}
    	}
    }
};
