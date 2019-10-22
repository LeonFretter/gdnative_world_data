#ifndef GD_GRID_H
#define GD_GRID_H

#include "Godot.hpp"
#include "Node2D.hpp"
#include "Vector2.hpp"
#include "Grid/Grid.hpp"

namespace godot {

    class GD_Grid : public Node2D {
        GODOT_CLASS(GD_Grid, Node2D);
    public:
        Vector2 _count;
        float _elem_size;
        bool _auto_init;
    private:
        Grid _grid;
    public:
        static void _register_methods();
        static void init_callback(void* me, void* data, Vector2 pos);

        GD_Grid();
        ~GD_Grid();

        void _init();
        void createGrid();
        virtual void _ready();

        Vector2 getClosestPosition(Vector2 pos);
    };


}



#endif // GD_GRID_H