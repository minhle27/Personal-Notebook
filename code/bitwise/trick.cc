/**
 * Description: other bitwise trick
 */

a + b = 2*(a & b) + (a^b)
/*
Proof:
a^b is essentially just a + b in base 2 but we never carry over to the next bit. Recall a bit 
in a^b is 1 only if the bit in a is different from the bit in b, thus one of them must be a 1
. However, when we xor two 1 bits, we yield a 0, but we do not carry that 1 to the next bit. 
This is where a&b comes in. a&b is just the carry bits themselves, since a bit is 1 only if 
it's a 1 in both a and b, which is exactly what we need. We multiply this by 2 to shift all 
the bits to the left by one, so every value carries over to the next bit.
*/

a ^ b = ~(a & b) & (a | b)

// addition
// If we perform addition without carrying, then we are simply performing the XOR operator. 
// Then, the bits that we carry over are those equivalent to 1 in both numbers: a&b
int add(int a, int b) {
	while (b > 0) {
		int carry = a & b;
		a ^= b;
		b = carry << 1;
	}
	return a;
}

// multiplication
int prod(int a, int b) {
	int c = 0;
	while (b > 0) {
		if ((b & 1) == 1) {
			c = add(c, a);  // Use the addition function we coded previously
		}
		a <<= 1;
		b >>= 1;
	}
	return c;
}

// Biggest power of 2 that is a divisor of x
1 << __builtin_ctz(x)

// The smallest power of 2 that is not smaller than x but this is UB (undefined behavior) for x <= 1 
// so you'll often need an if for x == 1
1 << (32 - __builtin_clz (x - 1))