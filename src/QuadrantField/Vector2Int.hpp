#ifndef VECTOR_2_INT_H
#define VECTOR_2_INT_H

#include "Vector2.hpp"

using namespace godot;

struct Vector2Int {
    int _x;
    int _y;
    Vector2Int();
    Vector2Int(int x, int y);
    Vector2Int(Vector2 vec);

    //operator overloading
    friend Vector2Int operator * (Vector2Int const, int const);
    friend Vector2Int operator / (Vector2Int const, int const);

    friend Vector2Int operator + (Vector2Int const, Vector2Int const);
    friend Vector2Int operator - (Vector2Int const, Vector2Int const);
    friend Vector2Int operator * (Vector2Int const, Vector2Int const);

    //conversions
    operator Vector2() const;
};

#endif // H_VECTOR_2_INT
