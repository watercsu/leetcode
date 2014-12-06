/* A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity. */
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        return findPeakElement(num,0,num.size()-1);
    }
    
    int findPeakElement(const vector<int> &num,int start, int end) {
        int low=start,high=end;
        if(start==end) return start;
        if(end-start==1) return max(num[end],num[start])==num[end]?end:start;
        for(; low<high; ) {
            int mid = (low+high)/2;
            if(num[mid]<=num[mid-1] && num[mid]>num[mid+1]) {
                high = mid-1;
            } else if (num[mid]<=num[mid+1] && num[mid]>num[mid-1]) {
                low = mid+1;
            } else if (num[mid]>num[mid+1]&&num[mid]>num[mid-1]) {
                return mid;
            } else {
                return max(findPeakElement(num,mid+1,end),findPeakElement(num,start,mid-1));
            }
        }
        
        if(low==start && num[low]>num[low+1]) return low;
        if(high==end && num[high]>num[high-1]) return high;
        if(low==high && num[low]>num[low-1] &&num[low]>num[low+1]) return low;
        return -1;
    }
};
