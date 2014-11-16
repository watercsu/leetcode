/* Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] */
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> ret(numRows, vector<int>());
        for(int i=0; i<numRows; i++) {
            for(int j=0; j<=i; j++) {
                if(j==0 || j==i) {
                    ret[i].push_back(1);
                }
                else {
                    ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
                }
            }
        }
        return ret;
    }
};
