/**
 * Description: coordinate Compression
 */

// Coordinate compression describes the process of mapping each value in a list to 
// its index if that list was sorted. (labelling coordinate with compressed values)
// When we have values from a large range, but we only care about their relative order 
// (for example, if we have to know if one value is above another), coordinate compression 
// is a simple way to help with implementation.

typedef pair<int, int> Point;
bool ycomp(Point p, Point q) { return p.second < q.second; }

// Perform compression on a set of points => Can be used as array indices
sort(P, P + N);
for (int i = 0; i < N; i++) P[i].first = i + 1;
sort(P, P + N, ycomp);
for (int i = 0; i < N; i++) P[i].second = i + 1;

// coordinate compression sometimes will also require remembering values in addition 
// to compressing them (as opposed to just replacing the original values)