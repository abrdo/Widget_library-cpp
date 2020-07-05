#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"
#include "../window.hpp"
#include <sstream>

class Window;


class Widget{
public:
    int _x, _y, _size_x, _size_y;
    Window* _window; // the window what contains this widget. (not necessary to provide with value to use a widget properly)

    bool _focused;
    bool _focusable;
    bool _targeted;

    int _fonthight;
    std::string __fontfile;
    int __fontsize;

    unsigned char _r, _g, _b;
    unsigned char _bgcol_r, _bgcol_g, _bgcol_b; //backgroundcolor
    unsigned char _frame_r, _frame_g, _frame_b;

public:
    Widget(){}
    Widget(int x, int y, int sx, int sy, int fontsize = 14, Window* window = 0);
    Widget(int x, int y, int sx, int sy, unsigned char backgroundcolor_r, unsigned char backgroundcolor_g, unsigned char backgroundcolor_b);
    virtual ~Widget(){}
    bool is_focused();
    void set_focused(bool f);
    bool is_focusable();
    void set_focusable(bool f);
    void set_color(unsigned char r, unsigned char g, unsigned char b){ _r=r; _g=g; _b=b;}


    bool mouse_above(genv::event ev) const;
    virtual void handle(genv::event ev) = 0;

    virtual void show(genv::canvas &c = genv::gout) const = 0;
    void show_frame(genv::canvas &c = genv::gout) const;

    bool focusing_click(genv::event ev) const;
    void focus_by_click(genv::event ev);

    // ------------------------------------------------------------------------------


    static std::string to_str(int i){
        std::stringstream ss;
        ss<<i;
        std::string s;
        ss>>s;
        return s;
    }

    static int to_int(std::string s){
        std::stringstream ss;
        ss<<s;
        int i;
        ss>>i;
        return i;
    }

    inline bool is_inside(int px, int py, int x1, int x2, int y1, int y2){ //is (px, py) in a rectangle?
        return x1<=px && px<=x2 && y1<=py && py<=y2;
    }

};

#endif // WIDGET_HPP
