#include <iostream>
#include <vector>
#include "Label.h"
#include "Button.h"

int main() {
    std::vector<Component*> components;
    int choice;

    std::cout << "Enter number of components: ";
    int n;
    std::cin >> n;

    // Input components
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter 1 for Label, 2 for Button: ";
        std::cin >> choice;

        std::string name;
        int tr, tg, tb, br, bg, bb;

        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter text color (R G B): ";
        std::cin >> tr >> tg >> tb;
        std::cout << "Enter background color (R G B): ";
        std::cin >> br >> bg >> bb;

        Color textColor(tr, tg, tb);
        Color backgroundColor(br, bg, bb);

        if (choice == 1) {
            components.push_back(new Label(name, textColor, backgroundColor));
        } else if (choice == 2) {
            components.push_back(new Button(name, textColor, backgroundColor));
        }
    }

    // Display components
    for (auto& component : components) {
        component->display();
    }

    // Check complementary colors for the first component
    if (!components.empty()) {
        Color textColor = components[0]->getTextColor();
        Color backgroundColor = components[0]->getBackgroundColor();

        if (textColor.isComplementary(backgroundColor)) {
            std::cout << "Text and background colors of the first component are complementary.\n";
        } else {
            std::cout << "Text and background colors of the first component are NOT complementary.\n";
        }
    }

    // Check color harmony for all components
    for (size_t i = 0; i < components.size(); ++i) {
        Color bgColor = components[i]->getBackgroundColor();

        if (bgColor.getRed() == bgColor.getGreen() && bgColor.getGreen() == bgColor.getBlue()) {
            std::cout << "Component " << i + 1 << " follows the monochromatic color scheme.\n";
        } else {
            std::cout << "Component " << i + 1 << " does NOT follow the monochromatic color scheme.\n";
        }
    }

    // Clean up dynamically allocated memory
    for (auto& component : components) {
        delete component;
    }

    return 0;
}
