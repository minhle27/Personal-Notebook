/**
 * Description: use complex number to represent points and vector
 */

// define x, y as real(), imag()
typedef complex<double> point;
#define x real()
#define y imag()
const double pi = acos(-1.0);
const double EPS = 1e-9;

#define P(p) const point &p
#define L(p0, p1) P(p0), P(p1)
#define C(p0, r) P(p0), double r
#define PP(pp) pair<point,point> &pp

// Note: std::complex has issues with integral data types. The library will work 
// for simple arithmetic like vector addition and such, but not for polar or abs. 
// It will compile but there will be some errors in correctness! The tip then is 
// to rely on the library only if you're using floating point data all throughout.

double dot(P(a), P(b)) { 
    return real(conj(a) * b); 
}

// x1y2-x2y1
// The cross product tells us whether b turns left (positive value), 
// does not turn (zero) or turns right (negative value) when it is placed
// directly after a
double cross(P(a), P(b)) { 
    return imag(conj(a) * b); 
}

point rotate(P(p), double radians = pi / 2, P(about) = point(0,0)) { 
    return (p - about) * exp(point(0, radians)) + about; 
}
point proj(P(u), P(v)) { 
    return dot(u, v) / dot(u, u) * u; 
}
point normalize(P(p), double k = 1.0) { 
    return abs(p) == 0 ? point(0,0) : p / abs(p) * k; 
}
bool parallel(L(a, b), L(p, q)) { 
    return abs(cross(b - a, q - p)) < EPS; 
}
double ccw(P(a), P(b), P(c)) { 
    return cross(b - a, c - b); 
}
bool collinear(P(a), P(b), P(c)) { return abs(ccw(a, b, c)) < EPS; }
double angle(P(a), P(b), P(c)) {
    return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); 
}
bool intersect(L(a, b), L(p, q), point &res, bool segment = false) {
    // NOTE: check for parallel/collinear lines before calling this function
    point r = b - a, s = q - p;
    double c = cross(r, s), t = cross(p - a, s) / c, u = cross(p - a, r) / c;
    if (segment && (t < 0-EPS || t > 1+EPS || u < 0-EPS || u > 1+EPS))
        return false;
    res = a + t * r;
    return true;
}
point closest_point(L(a, b), P(c), bool segment = false) {
    if (segment) {
        if (dot(b - a, c - b) > 0) return b;
        if (dot(a - b, c - a) > 0) return a;
    }
    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}

typedef vector<point> polygon;
#define MAXN 1000
point hull[MAXN];
bool cmp(const point &a, const point &b) {
    return abs(real(a) - real(b)) > EPS ?
        real(a) < real(b) : imag(a) < imag(b); }
int convex_hull(vector<point> p) {
    int n = p.size(), l = 0;
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i] == p[i - 1])
            continue;
        while (l >= 2 && ccw(hull[l - 2], hull[l - 1], p[i]) >= 0)
            l--;
        hull[l++] = p[i];
    }
    int r = l;
    for (int i = n - 2; i >= 0; i--) {
        if (p[i] == p[i + 1])
            continue;
        while (r - l >= 1 && ccw(hull[r - 2], hull[r - 1], p[i]) >= 0)
            r--;
        hull[r++] = p[i];
    }
    return l == 1 ? 1 : r - 1;
}

int main() {
	point a = 2;
	point b(3, 7);
	cout << a << ' ' << b << endl; // (2, 0) (3, 7)
	cout << a + b << endl;         // (5, 7)

	point v = {3,1};
	point u = {2,2};
	point s = v+u;
	cout << s.x << " " << s.y << "\n"; // 5 3

	point a = {4,2};
	point b = {3,-1};
	cout << abs(b-a) << "\n"; // distance between points 

	// A vector can be rotated by an angle a by multiplying it by a vector with length 1 and angle a.
	P v = {4,2};
	cout << arg(v) << "\n"; // 0.463648
	v *= polar(1.0,0.5);
	cout << arg(v) << "\n"; // 0.963648
}

// If the input coordinates are integer, 
// most computations can be done in integers, 
// but the result may be real (for example, in line intersection, as we'll see later). 
// So, it's useful to have different point types in one program. And here's the first advice: 
// do computations in integers as long as possible, for two obvious reasons:
// they are faster; they avoid precision issues.