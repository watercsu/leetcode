/* You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */
/*   Recursive  with duplicate calculator */
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

/*Improve: Recursive  with cache, no duplicate calculator */
class Solution {
public:
    int ClimbStairs(int n,vector<int> & cache)
    {
        if(cache[n]!=0)
            return cache[n];
        if(n==1) return 1;
        if(n==2) return 2;
        return cache[n] = ClimbStairs(n-1,cache)+ClimbStairs(n-2,cache);
    }
    int climbStairs(int n) 
    {
       vector<int>  cache(n+1,0);
       return ClimbStairs(n,cache);
    }
};

/* Interactive */
class Solution {
public:
    int climbStairs(int n) {
        vector<int> fb(n+1,1);
        for(int i=2; i<=n; i++) {
            fb[i] = fb[i-1]+fb[i-2];
        }
        return fb[n];
    }
};
