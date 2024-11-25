#ifndef LABEL_H
#define LABEL_H

#include "Component.h"

class Label : public Component {
public:
    Label(const std::string& name, const Color& textColor, const Color& bgColor);
    void display() const override;
};

#endif // LABEL_H
