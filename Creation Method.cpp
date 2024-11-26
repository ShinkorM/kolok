#include <vector>
class Shape {
public:
    virtual void draw() = 0; // Абстрактный метод
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Rectangle\n";
    }
};

class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "Circle") return std::make_unique<Circle>();
        if (type == "Rectangle") return std::make_unique<Rectangle>();
        throw std::invalid_argument("Unknown shape type");
    }
};
