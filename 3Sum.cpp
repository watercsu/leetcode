/*Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2) */
    
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int>> ret;
		sort(num.begin(), num.end());
		for (int i = 0; i<num.size();) {
			for (int j = i + 1, k = num.size() - 1; j<k;) {
				if (num[j] + num[k]<-num[i]) {
					j++;
				}
				else if (num[j] + num[k]>-num[i]) {
					k--;
				}
				else {
					ret.push_back(vector<int>({num[i],num[j],num[k]}));
					j++; k--;
					while (j<k && num[j-1] == num[j]) { j++; }
					while (j<k && num[k+1] == num[k]) { k--; }
				}
			}			
			i++;
			while (i<num.size() - 2 && num[i] == num[i-1]) i++;
		}
    	return ret;
    }
};
