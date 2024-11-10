/**
 * Description: This function takes in a range and modifies it to the next lexicographically greater permutation.
 * If the sequence is already the largest permutation, it transforms the sequence into the smallest (sorted) permutation and returns false. Otherwise, it returns true.
 * Each call to next_permutation makes a constant number of swaps on average if we go through all N! permutations of size N.
 * 
 * As long as the container supports bidirectional iterators (like begin() and end(), iterators that can move both forward and backward), you can apply next_permutation.
 * These include most of the STL containers such as vector, string, deque, list, and even ranges of raw pointers.
 */


// Sort to smallest lexicographical order in advance in order to iterate through all permutation
do {
	check(v);  // process or check the current permutation for validity
} while (next_permutation(v.begin(), v.end()));