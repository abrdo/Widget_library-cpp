#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include "widget.hpp"

namespace dowi{

class CheckBox : public Widget
{
private:
    bool _checked;
public:
    CheckBox(int x, int y, int sx = 25, int sy = 25);
    void set_checked(bool ch);
    bool is_checked(){ return _checked; }
    void toggle();
    void handle(genv::event ev) override;
    void show(genv::canvas &c = genv::gout) const override;


};

} // namespace

#endif // CHECKBOX_HPP
