/* Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. */

class Solution {
public:
    int maxProduct(int A[], int n) {
        int ret = A[0];
        int maxProduct = A[0];
        int minProduct = A[0];
        for(int i=1; i<n; i++) {
            int val1 = A[i]*maxProduct;
            int val2 = A[i]*minProduct;
            maxProduct=max(max(A[i],val1),val2);
            minProduct=min(min(A[i],val1),val2);
            ret = max(maxProduct,ret);
        }
        return ret;
    }
};
