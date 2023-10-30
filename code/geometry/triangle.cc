/**
 * Author: Ulf Lundstrom
 * Date: 2009-02-26
 * License: CC0
 * Source: My head with inspiration from tinyKACTL
 * Description: Triangle
 * Status: Works fine, used a lot
 */

/*
To check if three line segments of length a, b and c can form a triangle, we can simply 
check these triangle inequalities: (a+b>c)&&(a+c>b)&&(b+c>a).
If the three lengths are sorted, with a being the smallest and c the largest, then we can 
simplify the check to just (a + b > c).
*/

// Heron: A = sqrt(s(s-a)(s-b)(s-c)) with s is nua chu vi

// A triangle with area A and semi-perimeter s has an inscribed circle (incircle) with radius r = A/s.
double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca)); }

double rInCircle(point a, point b, point c) {
  return rInCircle(dist(a, b), dist(b, c), dist(c, a)); }

// The center of incircle is the meeting point between the triangle's angle bisectors. 
// We can get the center if we have two angle bisectors and find their intersection point
// assumption: the required points/lines functions have been written
// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
  r = rInCircle(p1, p2, p3);
  if (fabs(r) < EPS) return 0;                   // no inCircle center

  line l1, l2;                    // compute these two angle bisectors
  double ratio = dist(p1, p2) / dist(p1, p3);
  point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
  pointsToLine(p1, p, l1);

  ratio = dist(p2, p1) / dist(p2, p3);
  p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
  pointsToLine(p2, p, l2);

  areIntersect(l1, l2, ctr);           // get their intersection point
  return 1; }

// A triangle with 3 sides: a, b, c and area A has a circumscribed circle (circumcircle) 
// with radius R = abc/(4A).
double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca)); }

double rCircumCircle(point a, point b, point c) {
  return rCircumCircle(dist(a, b), dist(b, c), dist(c, a)); }

// The center of circumcircle is the meeting point between the triangle's perpendicular bisectors
