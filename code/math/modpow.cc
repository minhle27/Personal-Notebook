/**
 * Description: Finding a^b%c
 * Time: O(logN) 
 */

// Modular exponentiation
// efficiently calculate the value of x^n mod m. (CPH)
int modpow(int x, int n, int m) {
    if (n == 0) return 1%m;
    long long u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

// Code 2:
ll exp(ll x, ll n, ll m) {
	assert(n >= 0);
	x %= m;  // note: m * m must be less than 2^63 to avoid ll overflow
	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = (res * x) % m; }
		x = (x * x) % m;
		n /= 2;
	}
	return res;
}

