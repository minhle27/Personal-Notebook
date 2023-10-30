/**
 * Description: Quadrilaterals
 */

// Given a rectangle described with its bottom left corner (x, y) plus its width w and height h, 
// we can use the following checks to determine if another point (a, b) is inside, at the border, 
// or outside this rectangle:
int insideRectangle(int x, int y, int w, int h, int a, int b)
{
    if ((x < a) && (a < x + w) && (y < b) && (b < y + h))
        return 1; // strictly inside
    else if ((x <= a) && (a <= x + w) && (y <= b) && (b <= y + h))
        return 0; // at border
    else
        return -1; // outside
}