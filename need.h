#pragma once
class CPoint {

public:
    double x;
    double y;

    friend bool operator== (const CPoint &left, const CPoint &right);
};

bool operator== (const CPoint &left, const CPoint &right) {
    return (left.x == right.x && left.y == right.y);
}
bool operator!= (const CPoint &left, const CPoint &right) {
    return (left.x != right.x && left.y != right.y);
}