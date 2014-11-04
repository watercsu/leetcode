/* Determine whether an integer is a palindrome. Do this without extra space. */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int init=x,num=0;
        
        while(init) {
            num = num*10+init%10;
            init = init/10;
        }
        
        return num==x;
    }
};
