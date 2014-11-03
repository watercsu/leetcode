/*Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

class Solution {
public:
     int reverse(int x) {
         int num = x, ret = 0, i = 0;
    	 vector<int> intVec;
    
    	 if (x < 0) num = x*(-1);
    
    	 while (num > 0)
    	 {
    		 intVec.push_back(num%10);
    		 num = num / 10;
    	 }
    
    	 while (i<intVec.size())
    		 ret = ret * 10 + intVec[i++];
    	 ret = x > 0 ? ret : ret*(-1);
    	 return ret;
     }
};
