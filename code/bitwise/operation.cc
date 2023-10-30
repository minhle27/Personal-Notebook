/**
 * Description: Bitwise Trick
 */


/*
x << k corresponds to multiplying x by 2k
x >> k corresponds to dividing x by 2k rounded down to an integer.

x & 1 = 1 if x is odd, = 0 if x is even
x | (1 << k): sets the kth bit of x to one
x & (2^k-1) = 0 <=> x is divisible by 2^k
~x = -x-1
x << k: multiplying x by 2k
x >> k: dividing x by 2k rounded down to an integer.
x &~(1 << k): sets the kth bit of x to zero
x ^ (1 << k): inverts the kth bit of x.
x & (x-1): sets the last one bit of x to zero
x & -x: sets all the one bits to zero, except for the last one bit
x | (x-1): inverts all the bits after the last one bit

T = ((S) & -(S)): get the value of the least significant bit of S that is on. 
T = LSOne(S) is a power of 2, i.e., 2^j. To get the actual index j (from the right), 
we can use __builtin_ctz(T)

a positive number x is a power of two exactly when x & (x-1) = 0.

111..1 (k one bits) = 2^k-1

__builtin_clz(x): the number of zeros at the beginning of the number
__builtin_ctz(x): the number of zeros at the end of the number
__builtin_popcount(x): the number of ones in the number
__builtin_parity(x): the parity (even or odd) of the number of ones
there are also long long versions of the functions available with the suffix ll.
cout << bitset<8>(x); prints a number after converting it into a bitset, which can be printed
*/


// print a number in binary format. 
string to_binary(int x) {
	string s;
	while(x > 0) {
		s += (x % 2 ? '1' : '0');
		x /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}



// Representing sets
/*
The following code declares an int variable x that can contain a subset of
{0,1,2,...,31}. After this, the code adds the elements 1, 3, 4 and 8 to the set
and prints the size of the set.
*/
int x = 0;
x |= (1<<1);
x |= (1<<3);
x |= (1<<4);
x |= (1<<8);
cout << __builtin_popcount(x) << "\n"; // 4

for (int i = 0; i < 32; i++) {
    if (x&(1<<i)) cout << i << " ";
}
// output: 1 3 4 8

// Set operations
// Intersection: a & b
// Union: a | b
// Complement: ~a
// Difference: a&(~b)

//The following code first constructs the sets x = {1,3,4,8} and
// y = {3,6,8,9}, and then constructs the set z = xUy = {1,3,4,6,8,9}:
int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);
int y = (1<<3)|(1<<6)|(1<<8)|(1<<9);
int z = x|y;
cout << __builtin_popcount(z) << "\n"; // 6

// goes through the subsets of {0,1,...,n-1}:
for (int b = 0; b < (1<<n); b++) {
    // process subset b
}

// goes through the subsets with exactly k elements:
for (int b = 0; b < (1<<n); b++) {
    if (__builtin_popcount(b) == k) {
        // process subset b
    }
}

// goes through the subsets of a set x:
int b = 0;
do {
    // process subset b
} while (b=(b-x)&x);

// Note: 2^k is just 1 << k or 1LL << k if you need long longs