int find_lis(vi &a) {
    vi dp;
    for (int i : a) {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == sz(dp)) dp.push_back(i);
        else {
            dp[pos] = i;
        }
    }
    return dp.size();
}