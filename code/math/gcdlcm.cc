/**
 * Description: GCD and LCM
 * Time: O(logab) for gcd 
 */

// For C++14, you can use the built-in __gcd(a,b).
// In C++17, there exists std::gcd and std::lcm in the <numeric> header
// Note: lcm(a, b) = ab/gcd(a, b)

// Also, these two functions are associative, meaning that
// if we want to take the GCD or LCM of more than two elements, we can do so two at
// a time, in any order. For example,

// gcd(a1, a2, a3, a4) = gcd(a1, gcd(a2, gcd(a3, a4)))
