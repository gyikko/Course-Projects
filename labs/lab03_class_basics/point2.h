#ifndef POINT_H
#define POINT_H

class Point2 {
    float x;
    float y;
public:
    Point2 (float xx=0, float yy=o) {xx=x; yy=y; };
    float DistanceBetween();
    void Quadrant(int x, int y);
    void Print();
};

#endif