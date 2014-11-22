/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2). */
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int min = INT_MAX, ret;
        for(int i=0; i<num.size()-1; i++) {
            for(int low=i+1,high=num.size()-1; low<high;) {
                int tmp = num[i]+num[low]+num[high];
                if(abs(tmp-target)<min) {
                    min=abs(tmp-target);
                    ret = tmp;
                }
                if(tmp>target) {
                    high--;
                } else if(tmp<target) {
                    low++;
                } else {
                    return target;
                }
            }
        }
        return ret;
    }
};
