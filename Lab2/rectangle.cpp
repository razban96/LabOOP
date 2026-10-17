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
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

void Rectangle::showWidth() const {
    std::cout << "Width: " << width << std::endl;
}

void Rectangle::showHeight() const {
    std::cout << "Height: " << height << std::endl;
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


int main() {
    Rectangle rect;

    // pointer to function from Rectangle class
    double (Rectangle::*areaPtr)(std::string const &, std::string const &) = &Rectangle::getArea;

    /* try catch
     * tries the code for computing the area
     * catches errors like Caught exception: stod if non numbers
     * or catches in function for setting height/width
     * if mixed parameter (ex: "192a")
     */
    try {
        double area = (rect.*areaPtr)("5", "abc");
        std::cout << "Area: " << area << '\n';
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    return (rect.*areaPtr)("2", "3") == 6.0 ? 0 : 1;
    //return 0;
}
