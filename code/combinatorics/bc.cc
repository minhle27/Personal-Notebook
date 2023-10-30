/**
 * Description: Binomial coefficient
 */

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

ll fac[MAXN + 1];
ll inv[MAXN + 1];

/** Computes x^n modulo m in O(log mod) time. */
ll exp(ll x, ll n, ll m) {
	x %= m;
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial() {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % MOD; }
}

/**
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log mod) time
 */
void inverses() {
	inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % MOD; }
}

/** Computes nCr mod p */
ll choose(int n, int r) { return fac[n] * inv[r] % MOD * inv[n - r] % MOD; }


factorial();
inverses();
choose(a, b);