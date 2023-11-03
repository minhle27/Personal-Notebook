// find target in an monotonic array
int binary_search(int A[], int sizeA, int target) {
    int lo = 1, hi = sizeA;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (A[mid] == target)
            return mid;       	
        else if (A[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    // target not found in A
    return -1;
}  

// Find smallest x such that P(x) = true
// If P(S) is of the form true-false, just reverse P(x)
bool P(int x) {
    // Ham danh gia x
    return true;  
}

int binary_search(int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (P(mid) == true)
            hi = mid;
        else
            lo = mid+1;
    }
  	
    if (P(lo) == false)
        return -1; // P(x) = false for all x in S, no solution
  	
   return lo; // lo is smallest x that P(x) = true
}

// Find biggest x such that P(x) = false
int binary_search(int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi-lo+1)/2;
        if (P(mid) == true)
            hi = mid - 1;
        else
            lo = mid;
    }
  	
    if (P(lo) == true)
        return -1; // P(x) = true for all x in S, no solution
  	
   return lo; // lo is largest x that P(x) = false
}

// Binary search on real range
bool isTerminated(double lo, double hi) {
    // return result of check
    // Do lo and hi satisfy stop condition?
}

double binary_search(double lo, double hi) {
    while (isTerminated(lo, hi) == false) {
        double mid = lo + (hi-lo)/2;
        if (P(mid) == true)
            hi = mid;
        else
            lo = mid;
    }
    // Approximate mean of lo and hi
    // boundary between false and true
    return lo + (hi-lo)/2; 
}

// Binary search implementation with open range
// hi must be greater than actual search range by 1
// In the case we want to find the last false then the open range will be (lo, hi] 
// and search returns lo if every values in range are true
int binary_search(int lo, int hi) {
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (P(mid) == true)
            hi = mid;
        else
            lo = mid+1;
    }
  	
   return lo; // lo is smallest x that P(x) = true
}

