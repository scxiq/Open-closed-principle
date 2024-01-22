#include <iostream>
#include <vector>

// Базовий клас, який є закритим для модифікації
class Shape {
public:
    virtual double area() const = 0;
};

// Клас прямокутника, який розширює базовий клас Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }
};

// Клас кола, який також розширює базовий клас Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14 * radius * radius;
    }
};

// Функція для обчислення суми площ всіх об'єктів Shape
double sumOfAreas(const std::vector<Shape*>& shapes) {
    double totalArea = 0.0;
    for (const auto& shape : shapes) {
        totalArea += shape->area();
    }
    return totalArea;
}

int main() {
    // Використання принципу відкритості/закритості
    Rectangle rectangle(5.0, 3.0);
    Circle circle(2.5);

    std::vector<Shape*> shapes;
    shapes.push_back(&rectangle);
    shapes.push_back(&circle);

    double totalArea = sumOfAreas(shapes);

    std::cout << "Total area of shapes: " << totalArea << "\n";

    return 0;
}
