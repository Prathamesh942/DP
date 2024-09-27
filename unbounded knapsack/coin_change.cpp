long long int count(int coins[], int N, int sum) {
    vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1,0));
    for(int i=0; i<=N; i++) dp[i][0]=1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=sum; j++){
            long taken = 0;
            long notTaken = dp[i-1][j];
            if(coins[i-1]<=j){
                taken=dp[i][j-coins[i-1]];
            }
            dp[i][j]=taken+notTaken;
        }
    }
    return dp[N][sum];
}


// 

long long int count(int coins[], int N, int sum) {
    vector<long long int> dp(sum+1,0);
    dp[0]=1;
    for(int i=0; i<N; i++){
        for(int j=coins[i]; j<=sum; j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[sum];
}

// Let's dry run the Coin Change Problem with the target sum sum = 3 and coins {2, 1}

// The DP array starts as:
// dp = [1, 0, 0, 0]

// Coin 1: Coin of Value 2
//     Sum 2:
//         We add the number of ways to make 2 - 2 = 0.
//         dp[2] += dp[0] → dp[2] = 0 + 1 = 1
//     dp = [1, 0, 1, 0]

//     Sum 3:
//         We add the number of ways to make 3 - 2 = 1.
//         dp[3] += dp[1] → dp[3] = 0 + 0 = 0.
//     dp = [1, 0, 1, 0]

// Coin 2: Coin of Value 1
//     Sum 1:
//         We add the number of ways to make 1 - 1 = 0.
//         dp[1] += dp[0] → dp[1] = 0 + 1 = 1
//     dp = [1, 1, 1, 0]

//     Sum 2:
//         We add the number of ways to make 2 - 1 = 1.
//         dp[2] += dp[1] → dp[2] = 1 + 1 = 2.
//     dp = [1, 1, 2, 0]

//     Sum 3:
//         We add the number of ways to make 3 - 1 = 2.
//         dp[3] += dp[2] → dp[3] = 0 + 2 = 2.
//     dp = [1, 1, 2, 2]

// Final DP Array:
// dp = [1, 1, 2, 2]