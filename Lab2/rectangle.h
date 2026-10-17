#pragma once
#include <string>
class Rectangle {
private:
    double width{}, height{};
public:
    Rectangle();
    Rectangle(std::string const& width, std::string const& height);
    ~Rectangle();

    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
    void showWidth() const;
    void showHeight() const;

    void setWidth(std::string const& width);
    void setHeight(std::string const& height);

    [[nodiscard]] double getArea(std::string const& width, std::string const& height = "");
    [[nodiscard]] double getArea() const;
};