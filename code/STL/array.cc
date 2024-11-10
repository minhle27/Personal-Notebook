/**
 * Description: In C++11, in addition to normal arrays, there exists an array class in the STL.
 * The array class supports STL operations (such as .empty() or .size()) as well as the normal square-bracket access operator
 */

// An array of 25 ints can be initialized using the following line of code:
array<int, 25> arr;

/**
 * Initialize an array to all zero
 * 1. Use a for loop (or nested for loops).
 * 2. Declare the array globally.
 * 3. Use a built-in function
 */

int arr[25]{}; 

std::fill_n(arr, 25, 0) 
std::fill(arr, arr+25, 0).

/**
 * memset(arr, 0, sizeof arr) will also zero-initialize an array. 
 * However, it's important to note that memset treats the value that is passed to it as an unsigned char . 
 * So for an array of 32-bit integers, memset(arr, -1, sizeof arr) will set each element to -1.
 * On the other hand, memset(arr, 1, sizeof arr) will set each element to 1+2^8+2^{16}+2^{24}=16843009 , not 1
 */