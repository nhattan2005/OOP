#ifndef COMPONENT_H
#define COMPONENT_H

#include "Color.h"
#include <string>

class Component {
protected:
    std::string name;
    Color textColor, backgroundColor;
public:
    Component(const std::string& name, const Color& textColor, const Color& bgColor);
    virtual void display() const = 0; // Pure virtual function
    Color getTextColor() const;
    Color getBackgroundColor() const;
};

#endif // COMPONENT_H
