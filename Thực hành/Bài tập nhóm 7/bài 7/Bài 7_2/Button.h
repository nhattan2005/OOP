#ifndef BUTTON_H
#define BUTTON_H

#include "Component.h"

class Button : public Component {
public:
    Button(const std::string& name, const Color& textColor, const Color& bgColor);
    void display() const override;
};

#endif // BUTTON_H
