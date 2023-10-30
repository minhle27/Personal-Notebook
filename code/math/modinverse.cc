/**
 * Description: Finding modular inverse
 * Time: O(logN) 
 */

// Note: Nghich dao cua b theo modulo m ton tai khi b va m la nguyen to cung nhau
// O(log(m))
// If the modular inverse of the same number(s) is/are being used many times, 
// it is a good idea to precalculate it.

// Find mod inverse, using fermat little theorem
int modInverse(int b, int m) {
    int res = modpow(b, m - 2, m);
    if ((res * b) % m == 1) return res;
    return -1; // inverse doesnt exist
}


// Using extended Euclidean algorithm
vi extendedEuclid(int b, int m) {
    vi res;
    int q, r;
    int x1 = 1, y1 = 0;
    int x2 = 0, y2 = 1;
    int x3 = 1, y3 = 0;
    while (m != 0) {
        q = b / m;
        r = b % m;
        x3 = x1 - q * x2;
        y3 = y1 - q * y2;
        x1 = x2, y1 = y2;
        x2 = x3, y2 = y3;
        b = m, m = r;
    }
    res.PB(b); res.PB(x1); res.PB(y1);
    return res;
}

void modInverse(int b, int m) {
    vi res = extendedEuclid(b, m);
    int gcd = res[0];
    int x = res[1];
    int y = res[2];
    if (gcd != 1) cout << "Inverse doesnt exist";
    else cout << "Mod inverse: " << (x + m) % m << endl;
}