/**
 * Description: Point Struct
 */

const double INF = 1e9;
const double EPS = 1e-9;

// const double PI = acos(-1.0) or 2.0 * acos(0.0) for alternative to M_PI
double DEG_to_RAD(double d) { return d*M_PI/180.0; }

double RAD_to_DEG(double r) { return r*180.0/M_PI; }

struct point_i {
    int x, y;                                      // use this if possible
    point_i() { x = y = 0; }                       // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {}      // constructor
};

// check the required precision and set EPS appropriately.
struct point {
    double x, y;                                   // if need more precision
    point() { x = y = 0.0; }                       // default constructor
    point(double _x, double _y) : x(_x), y(_y) {}  // constructor
    bool operator < (point other) const {          // override < operator
        if (fabs(x-other.x) > EPS)                 // useful for sorting
            return x < other.x;                    // by x-coordinate
        return y < other.y;                        // if tie, by y-coordinate
    }
    // use EPS (1e-9) when testing equality of two floating points
    bool operator == (const point &other) const {
        return (fabs(x-other.x) < EPS && (fabs(y-other.y) < EPS));
    }
};

double dist(point p1, point p2) {                  // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx*dx + dy*dy)
    return hypot(p1.x-p2.x, p1.y-p2.y);            // return double
}

// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {              // theta in degrees
    double rad = DEG_to_RAD(theta);                // convert to radian
    return point(p.x*cos(rad) - p.y*sin(rad),
                p.x*sin(rad) + p.y*cos(rad));
}