#include "rectangle.h"
#include <iostream>
#include <stdexcept>

Rectangle::Rectangle() : width(1), height(1) {
}

Rectangle::Rectangle(std::string const &width, std::string const &height) {
    setWidth(width);
    setHeight(height);
}

Rectangle::~Rectangle() = default;

double Rectangle::getWidth() const {
    return this->width;
}

double Rectangle::getHeight() const {
    return this->height;
}

void Rectangle::showWidth() const {
    std::cout << "Width: " << this->width << std::endl;
}

void Rectangle::showHeight() const {
    std::cout << "Height: " << this->height << std::endl;
}

void Rectangle::setWidth(std::string const& width) {
    std::size_t idx = 0;
    double value = std::stod(width, &idx);

    if (idx < width.length() || value <= 0) {
        throw std::invalid_argument("Invalid number format!");
    }
    this->width = value;
}

void Rectangle::setHeight(std::string const& height) {
    std::size_t idx = 0;
    double value = std::stod(height, &idx);
    if (idx < height.length() || value <= 0) {
        throw std::invalid_argument("Invalid number format!");
    }
    this->height = value;
}

double Rectangle::getPerimeter(std::string const &width, std::string const &height) {
    setWidth(width);

    if (height.empty()) {
        setHeight(width);
    }
    else setHeight(height);

    return (this->width * 2) + (this->height * 2);
}

double Rectangle::getPerimeter() const {
    return (this->width * 2) + (this->height * 2);
}

double Rectangle::getArea(std::string const& width, std::string const& height) {
    setWidth(width);

    if (height.empty()) {
        setHeight(width);
    }
    else setHeight(height);

    return this->width * this->height;
}

double Rectangle::getArea() const {
    return this->width * this->height;
}

void Rectangle::comparePerimeter(const Rectangle &a, const Rectangle &b) {
    double first = a.getPerimeter();
    double second = b.getPerimeter();

    if (first > second) std::cout << "Perimeter: " << first << '\n';
    else if (first < second) std::cout << "Perimeter: " << second << '\n';
    else std::cout << "Perimeters are equal\n";
}

void Rectangle::compareArea(const Rectangle &a, const Rectangle &b) {
    double first = a.getArea();
    double second = b.getArea();

    if (first > second) std::cout << "Area: " << first << '\n';
    else if (first < second) std::cout << "Area: " << second << '\n';
    else std::cout << "Areas are equal\n";
}


int main() {
    Rectangle rect;

    // pointer to function from Rectangle class
    double (Rectangle::*areaPtr)(std::string const &, std::string const &) = &Rectangle::getArea;
    double (Rectangle::*perimeterPtr)(std::string const &, std::string const &) = &Rectangle::getPerimeter;
    /* try catch
     * tries the code for computing the area
     * catches errors like Caught exception: stod if non numbers
     * or catches in function for setting height/width
     * if mixed parameter (ex: "192a")
     */
    try {
        double area = (rect.*areaPtr)("5", "4");
        std::cout << "Area: " << area << '\n';
        double perimeter = (rect.*perimeterPtr)("5", "2");
        std::cout << "Perimeter: " << perimeter << '\n';

        Rectangle rect2("3", "6");
        Rectangle rect3("3", "6");
        Rectangle::comparePerimeter(rect2, rect3);
        Rectangle::compareArea(rect2, rect3);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    return (rect.*areaPtr)("2", "3") == 6.0 ? 0 : 1;
    //return 0;
}
