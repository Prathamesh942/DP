// Given a rod of length n inches and an array of prices that includes prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. We are mainly given a price array such that the size of the price array is same as rod length and price[i] represents price of length i+1

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n+1,0);
        for(int i=1; i<=n; i++){
            for(int j=0; j<=i; j++){
                dp[i] = max(dp[i], price[i-j-1]+dp[j]);
            }
        }
        return dp[n];
    }
};

// alternate approach

//  j-> 0 1 2 3 4 5   max length
// i   
// 0    0 0 0 0 0 0
// 1    0
// 2    0
// 3    0
// 4    0
// 5    0

//  i - possible choice subsets 0->{0} 1->{1} 2->{1,2} 3->{1,2,3}