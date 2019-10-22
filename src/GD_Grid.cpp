#include "GD_Grid.hpp"
#include <new>

using namespace godot;

struct Test {
    Vector2 _pos;
    TextureRect* _node;
};


// static methods

void GD_Grid::_register_methods() {
    //register methods
    register_method("_ready", &GD_Grid::_ready);
    register_method("createGrid", &GD_Grid::createGrid);
    
    //register properties
    register_property<GD_Grid, Vector2>("count", &GD_Grid::_count, Vector2(5, 5));
    register_property<GD_Grid, float>("element_size", &GD_Grid::_elem_size, 5.0f);
    register_property<GD_Grid, bool>("auto_init", &GD_Grid::_auto_init, false);
}

void GD_Grid::init_callback(void* me, void* data, Vector2 pos) {
    Godot::print(pos);

    new(data) Test();
    Test* test = static_cast<Test*>(data);
    GD_Grid* me_casted = static_cast<GD_Grid*>(me);

    test->_node = TextureRect::_new();
    ImageTexture* tex = ImageTexture::_new();
    Image* image = Image::_new();
    Color color = Color(0, 0, 1);

    image->create(8, 8, false, Image::FORMAT_RGBA8);
    image->fill(color);

    tex->create_from_image(image);

    test->_node->set_texture(tex);
    test->_node->set_position(pos);
    me_casted->add_child(test->_node);
}

// constructors and destructors

GD_Grid::GD_Grid() {}
GD_Grid::~GD_Grid() {}

void GD_Grid::_init() {
    _count = Vector2(5, 5);
    _elem_size = 5.0f;
    _auto_init = false;
}

void GD_Grid::_ready() {
    if(_auto_init == true) { createGrid(); }

}

void GD_Grid::createGrid() {
    Vector2 pos = get_position();

    _grid = Grid(
        this,
        sizeof(Test),
        _elem_size,
        pos,
        Vector2Int(_count),
        init_callback
    );
}

Vector2 GD_Grid::getClosestPosition(Vector2 pos) {

}