/* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2) */
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> ret;
        if(num.size()<4) {
            return ret;
        }
        sort(num.begin(),num.end());
        for(int i=0; i<num.size()-2;) {
            for(int j=i+1; j<num.size()-1;) {
                for(int low=j+1,high=num.size()-1; low<high;) {
                    int tmp = num[i]+num[j]+num[high]+num[low];
                    if(tmp > target) {
                        high--;
                    } else if(tmp < target) {
                        low++;
                    } else {
                        ret.push_back(vector<int>{num[i],num[j],num[low],num[high]});
                        do{
                            high--;
                        }while(num[high]==num[high+1] && high>low);
                        do{
                            low++;
                        }while(num[low]==num[low-1] && high>low);
                    }
                }
                do{
                    j++;
                }while(num[j]==num[j-1] && j<num.size()-1);
            }
            do{
                i++;
            }while(num[i]==num[i-1] && i<num.size()-2);
        }
        return ret;
    }
};
