#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct xrec
{
    float x;
    float y;
};

struct xrec2
{
    float width;
    float height;
};

struct xrec3
{
    CGPoint origin;
    CGSize size;
};


#typedef struct xrec CGPoint
#typedef struct xrec2 CGSize
#typedef struct xrec3 CGRect
/*
#typedef float CGPoint // is this allowed?
*/

CGRect CGRectMake(float x, float y, int height, int width);

void main(void)
{
    CGPoint p1, p2;
    CGSize s1;
    CGRect r1;

    r1.origin = p1;  // the rectangle's origin is now the point we just defined

    r1.origin.x = 10;
    r1.origin.y = 100;
    r1.size.width = 140;
    r1.size.height = 25;

    CGRect r2 = CGRectMake(5, 100, 50, 20);


}

CGRect CGRectMake(float x, float y, float height, float width)
{
    CGRect r1;
    r1.origin.x = x;
    r1.origin.y = y;
    r1.size.height = height;
    r1.size.width = width;

    return r1;
}
