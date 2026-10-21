#pragma once
#include <string>
class Rectangle {
private:
    double width{}, height{};
public:
    // constructors & destructors
    Rectangle();
    Rectangle(std::string const& width, std::string const& height);
    ~Rectangle();

    // default operations on private members
    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
    void showWidth() const;
    void showHeight() const;
    void setWidth(std::string const& width);
    void setHeight(std::string const& height);

    // calculations on object
    [[nodiscard]] double getPerimeter(std::string const& width, std::string const& height = "");
    [[nodiscard]] double getPerimeter() const;
    [[nodiscard]] double getArea(std::string const& width, std::string const& height = "");
    [[nodiscard]] double getArea() const;
    static void comparePerimeter(const Rectangle& a, const Rectangle& b);
    static void compareArea(const Rectangle& a, const Rectangle& b);
};