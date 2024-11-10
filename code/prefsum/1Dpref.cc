Source: VNOI

// 1D PrefSum
vector<int> buildPrefixSum(const vector<int>& a, int C = 0) {
    int n = (int)a.size();
    vector<int> prefixSum(n + 1);

    prefixSum[0] = C;

    for (int i = 0; i < n; i++)
        prefixSum[i + 1] = prefixSum[i] + a[i];

    return prefixSum;
}

// Build pref by using STL
partial_sum(first, last, result, binary_op)

vector<int> a = {3, -1, -4, 1, 5, 9, -2, -6};
int n = (int)a.size();

// manual
vector<int> prefOne = buildPrefixSum(a);
printArray(prefOne); // 0 3 2 -2 -1 4 13 11 5

// partial_sum
vector<int> prefTwo(n);
partial_sum(a.begin(), a.end(), prefTwo.begin());
printArray(prefTwo); // 3 2 -2 -1 4 13 11 5