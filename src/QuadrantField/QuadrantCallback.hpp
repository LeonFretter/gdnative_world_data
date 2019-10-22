#ifndef QUADRANT_CALLBACK_H
#define QUADRANT_CALLBACK_H

#include <functional>
#include <Vector2.hpp>

using namespace godot;

/*
    first void* is pointer to(from) calling class
    second void* is pointer to element/memory in quadrant-class
    Vector2 is position associated associated with element/memory
*/
typedef std::function<void(void*, void*, Vector2)> QuadrantCallback;

/*
    a wrapper around the QuadrantCallback,
    which transports the pointer to the caller
*/
struct QuadrantCallbackWrapper {
    void* _caller;
    QuadrantCallback _callback;
};


#endif //QUADRANT_CALLBACK_H