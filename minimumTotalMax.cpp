#include <bits/stdc++.h>

using namespace std;

int minimumTotalMax(vector<int> &nums, int k)
{
    int n = (int)nums.size();
    vector<int> dp(n, -1);
    int maxi = -1;
    for (int i = 0; i < k; i++)
    {
        maxi = max(maxi, nums[i]);
        dp[i] = maxi;
    }

    for (int i = k; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            mini = min(mini, dp[i - j]);
        }
        dp[i] = mini + nums[i];
    }
    return dp[n - 1];
}

void solve()
{
    vector<int> nums = {1, 3, 4, 5, 2, 6};
    int k = 3;
    cout << minimumTotalMax(nums, k) << endl;
}

int main()
{
    solve();
    return 0;
}