/**
 * Description: Circle
 */

int insideCircle(point_i p, point_i c, int r) {  // all integer version
  int dx = p.x-c.x, dy = p.y-c.y;
  int Euc = dx*dx + dy*dy, rSq = r*r;            // all integer
  return Euc < rSq ? 1 : Euc == rSq ? 0 : -1;    // inside/border/outside
}

// constant pi
// M_PI in C++ <cmath> library. or use PI = arccos(-1.0) or PI = 2 * arccos(0.0).
// Length of arc: alpha*c/360.0 (c is circum)
// Length of chord: sqrt(2*r^2*(1-cos(alpha))) or 2*r*sin(alpha/2)

/*
Sector of a circle is defined as a region of the circle enclosed by two radii and an arc
lying between the two radii. A circle with area A and a central angle alpha (in degrees)
has the corresponding sector area alpha*A/360.0 
*/

/*
Given 2 points on the circle (p1 and p2) and radius r of the corresponding circle, we can determine 
the location of the centers (c1 and c2) of the two possible circles
*/
bool circle2PtsRad(point p1, point p2, double r, point &c) {
  // to get the other center, reverse p1 and p2
  double d2 = (p1.x-p2.x) * (p1.x-p2.x) + 
              (p1.y-p2.y) * (p1.y-p2.y);
  double det = r*r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x+p2.x) * 0.5 + (p1.y-p2.y) * h;
  c.y = (p1.y+p2.y) * 0.5 + (p2.x-p1.x) * h;
  return true;
}

/*
To check if three line segments of length a, b and c can form a triangle, we can simply 
check these triangle inequalities: (a+b>c)&&(a+c>b)&&(b+c>a).
If the three lengths are sorted, with a being the smallest and c the largest, then we c
an simplify the check to just (a + b > c).
*/
