/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
     int reverse(int x) {
         int num = x, ret = 0;
    
    	 while (num)
    	 {
    	     ret = ret*10+num%10;
    		 num = num / 10;
    	 }
    
    	 return ret;
     }
};
