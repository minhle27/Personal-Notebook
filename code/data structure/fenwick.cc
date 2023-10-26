/**
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], 
 * and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(log N)$.
 */

// 0 based index
template<
    typename T  
> struct FT {
    FT(int _n) : n(_n), f(_n + 1) {}

    // a[u] += val
    void update(int u, T val) {
        assert(0 <= u && u < n);
        ++u;
        for (; u <= n; u += u & -u) {
            f[u] += val;
        }
    }

    // return a[0] + .. + a[u-1]
    T get(int u) const {
        assert(0 <= u && u <= n);
        T res = 0;
        for (; u > 0; u -= u & -u) {
            res += f[u];
        }
        return res;
    }

    // return a[l] + .. + a[r-1]
    T get(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return 0;  // empty
        return get(r) - get(l);
    }

    void reset() {
        std::fill(f.begin(), f.end(), T(0));
    }

    int lower_bound(T sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(f) && f[pos + pw-1] < sum)
				pos += pw, sum -= f[pos-1];
		}
		return pos;
	}

    int n;
    vector<T> f;
};

int main () {
    FT<ll> ft(n);
}
