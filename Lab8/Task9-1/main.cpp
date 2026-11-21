#include "Shape.h"
#include "Drawing.h"

int main() {
    Shape* triangle = new Triangle();
    Shape* circle = new Circle();

    Drawing* drawingTriangle = new Drawing(triangle);
    Drawing* drawingCircle = new Drawing(circle);

    drawingTriangle->drawShape();
    drawingCircle->drawShape();

    delete triangle;
    delete circle;
    delete drawingTriangle;
    delete drawingCircle;

    return 0;
}