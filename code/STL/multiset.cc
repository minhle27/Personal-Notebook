/**
 * Description: A multiset is a sorted set that allows multiple copies of the same element.
 */


// Note that the functions count and erase have an additional O(k) factor
//  where k is the number of elements counted/removed.
// To remove a value once, use ms.erase(ms.find(val)).
// To remove all occurrences of a value, use ms.erase(val).


multiset<int> ms;
ms.insert(1);                  // [1]
ms.insert(14);                 // [1, 14]
ms.insert(9);                  // [1, 9, 14]
ms.insert(2);                  // [1, 2, 9, 14]
ms.insert(9);                  // [1, 2, 9, 9, 14]
ms.insert(9);                  // [1, 2, 9, 9, 9, 14]
cout << ms.count(4) << '\n';   // 0
cout << ms.count(9) << '\n';   // 3
cout << ms.count(14) << '\n';  // 1
ms.erase(ms.find(9));
cout << ms.count(9) << '\n';  // 2
ms.erase(9);
cout << ms.count(9) << '\n';  // 0
