/**
 * Description: A sliding window is a constant-size subarray that moves 
 * from left to right through the array.
 * 
 * The most straightforward way to do this is to store an sorted set of integers 
 * representing the integers inside the window. If the window currently spans the 
 * range i...j, we observe that moving the range forward to i+1...j+1 only removes 
 * a[i] and adds a[j + 1] to the window. We can support these two operations and 
 * query for the minimum / maximum in the set in O(logN)
 */

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
	multiset<int> s;
	vector<int> ret;
	for (int i = 0; i < k; i++) { s.insert(nums[i]); }
	for (int i = k; i < nums.size(); i++) {
		ret.push_back(*s.rbegin());
		s.erase(s.find(nums[i - k]));
		s.insert(nums[i]);
	}
	ret.push_back(*s.rbegin());
	return ret;
}