/**
 * Description: Sparse Table. LG la so lon nhat thoa 2^LG < N. 
 * vi du: N = 10^5 thi LG = 16 vi 2^16 = 65536
 */


// a is 1-based index
int a[N], st[LG + 1][N];
void preprocess() {
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

// Preprocessing: O(NlogN)
// query: O(1)
// __lg(x) = floor(log_2(x)) while log2(x) return double
