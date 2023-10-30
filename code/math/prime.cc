bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

// Sieve of Eratosthenes, Find all prime <= N
vi sieve(int n) { // O(nlogn)
    vector<bool> mark;
    vi primes;
    mark.resize(n + 1, true);
    mark[0] = mark[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (mark[i]) {
            // Mark all the multiples of i as composite numbers
            for (int j = i * i; j <= n; j += i) {
                mark[j] = false;
            }
        }
    }

    // return all primes <= n
    for (int i = 2; i <= n; i++) {
        if (mark[i]) primes.push_back(i);
    }
    return primes;
}

// Segmented Sieve: Find all prime in [left, right]
// 1 <= left <= right <= 10^12 and right-left <= 10^6
vi segmentedSieve(int left, int right, vi primes) {
    if (left == 1) left++;
    vector<bool> mark;
    mark.resize(right - left + 1, true);

    for (int i = 0; i < sz(primes) && primes[i] <= sqrt(right); i++) {
        int base = (left / primes[i]) * primes[i];
        if (base < left) base += primes[i];
        for (int j = base; j <= right; j += primes[i]) {
            if (j != primes[i]) mark[j - left] = false;
        }
    }

    vi res;
    for (int i = left; i <= right; i++) {
        if (mark[i - left]) res.push_back(i);
    }
    return res;
}

int main() {
    int left = 11, right = 34;
    vi primes = sieve(sqrt(right));
    vi res = segmentedSieve(left, right, primes);
}


// Prime Factorization. Factorization of 252 = {2,2,3,3,7}
vector<int> factor(int n) { // O(sqrt(N))
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) { ret.push_back(n); }
	return ret;
}

// Prime factorization using sieve: O(logN)
// x can have O(logx) distinct prime factors
int minPrime[n + 1];
for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) { //if i is prime
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
for (int i = 2; i <= n; ++i) {
    if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}

vector<int> factorize(int n) { 
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}