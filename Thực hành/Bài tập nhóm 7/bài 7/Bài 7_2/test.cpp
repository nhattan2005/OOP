#include "Label.h"
#include "Button.h"
#include <vector>

int main() {
    std::vector<Component*> components;

    // Thêm các thành phần vào danh sách
    components.push_back(new Label("Title", Color(255, 0, 0), Color(0, 255, 255))); // Bổ túc
    components.push_back(new Button("Submit", Color(0, 255, 0), Color(255, 0, 255))); // Bổ túc

    // Hiển thị thông tin
    for (const auto& comp : components) {
        comp->display();
    }

    // Kiểm tra màu bổ túc
    if (components[0]->getTextColor().isComplementary(components[0]->getBackgroundColor())) {
        std::cout << "Thành phần đầu tiên có màu chữ và màu nền bổ túc trực tiếp." << std::endl;
    }

    // Giải phóng bộ nhớ
    for (auto& comp : components) {
        delete comp;
    }
    return 0;
}
