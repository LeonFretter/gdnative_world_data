#include "Vector2Int.hpp"

Vector2Int::Vector2Int() {}

Vector2Int::Vector2Int(int x, int y) {
    _x = x;
    _y = y;
}

Vector2Int::Vector2Int(Vector2 vec) {
    _x = vec.x;
    _y = vec.y;
}


//operator overloading

Vector2Int operator * (Vector2Int const a, int const b) {
    return Vector2Int(
        a._x * b,
        a._y * b
    );
}

Vector2Int operator / (Vector2Int const a, int const b) {
    return Vector2Int(
        a._x / b,
        a._y / b
    );
}

Vector2Int operator + (Vector2Int const a, Vector2Int const b) {
    return Vector2Int(
        a._x + b._x,
        a._y + b._y
    );
}

Vector2Int operator - (Vector2Int const a, Vector2Int const b) {
    return Vector2Int(
        a._x - b._x,
        a._y - b._y
    );
}

Vector2Int operator * (Vector2Int const a, Vector2Int const b) {
    return Vector2Int(
        a._x * b._x,
        a._y * b._y
    );
}




//conversions

Vector2Int::operator Vector2() const {
    return Vector2(_x, _y);
}