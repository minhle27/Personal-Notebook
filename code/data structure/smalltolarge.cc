/**
 * Description: Small-to-large merging technique to speed up the process of merging to data structure
 */

/*
Note that swap exchanges two sets in O(1) time. Thus, merging a smaller set of size m into 
the larger one of size n takes O(mlogn) time. We can also merge other standard library data structures 
such as std::map or std:unordered_map in the same way. However, std::swap does not always 
run in O(1) time. For example, swapping std::array s takes time linear in the sum of the sizes 
of the arrays, and the same goes for GCC policy-based data structures such as 
__gnu_pbds::tree or __gnu_pbds::gp_hash_table. To swap two policy-based data structures a and b 
in O(1), use a.swap(b) instead. Note that for standard library data structures, swap(a,b) 
is equivalent to a.swap(b) .
*/

// Always merge smaller set to larger set
if (a.size() < b.size()) swap(a, b);
for (int x : b) a.insert(x);

