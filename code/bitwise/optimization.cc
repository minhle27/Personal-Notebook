/**
 * Description: Optimization trick
 */

// Hamming distances
/*
Given a list of n bit strings, each of length k,
calculate the minimum Hamming distance between two strings in the list.
The Hamming distance hamming(a,b) between two strings a and b of equal
length is the number of positions where the strings differ.

if k is small, we can optimize the code by storing the bit strings
as integers and calculating the Hamming distances using bit operations. In
particular, if k <= 32, we can just store the strings as int values and use the
following function to calculate distances
*/

int hamming(int a, int b) {
    return __builtin_popcount(a^b);
}

// Count intersection of two sets (O(1))
__builtin_popcount(a & b)

// For bigger set: Use unsigned long long. we can simulate a long binary number
//  with multiple unsigned long longs. The implementation isn't that bad but doing 
// binary shifts would be quite ugly. Turns out all of this can be done with bitsets easily.
// bitset<365> is a binary number with 365 bits available, and it supports most of binary operations.
bitset<MAX_D> x[MAX_N];
int intersection(int i, int j) {
	return (x[i] & x[j]).count();
}
/*
construct a bitset from int or string bitset<100> a(17); bitset<100> b("1010");. 
You can even access particular bits with b[i]
*/


// given a sequence of N <= 10^7 numbers, each from interval [0,10^9]. How many 
// different values appear in the sequence? Don't use set or unordered_set because they quite slow.
// Create bitset<1000000001> visited, mark every given number visited[x] = 1, and print 
// visited.count(). The time complexity is O(N + MAX_X/32), space is O(MAX_X/32). This will use 
// 128 MB memory (one billion bits).