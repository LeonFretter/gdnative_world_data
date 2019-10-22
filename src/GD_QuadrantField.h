#ifndef GD_QUADRANT_FIELD_H
#define GD_QUADRANT_FIELD_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <Color.hpp>
#include <TextureRect.hpp>
#include <ImageTexture.hpp>
#include <Image.hpp>
#include <Array.hpp>

#include "QuadrantField/Vector2Int.hpp"
#include "QuadrantField/QuadrantField.hpp"
#include "QuadrantField/QuadrantCallback.hpp"

namespace godot {

    class GD_QuadrantField : public Node2D {
        GODOT_CLASS(GD_QuadrantField, Node2D);
    public:
        //exported member-variables
        float _size;
        Vector2 _initial_count;
    private:
        QuadrantField _quadrant_field;
    public:
        static void _register_methods();
        static void init_callback(void* me, void* data, Vector2 pos);

        GD_QuadrantField();
        ~GD_QuadrantField();

        void _init();
        void _process(float delta);

        Vector2 getClosestPosition(Vector2 pos);
        Array getAllPositions();

        virtual void _ready();
    };

}


#endif // H_GD_QUADRANT_FIELD