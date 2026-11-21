#include "Drawing.h"

Drawing::Drawing(Shape* shape) {
    this->pShape = shape;
}

// Implementam metoda fara parametri
void Drawing::drawShape() const
{
    if (this->pShape != nullptr) {
        this->pShape->draw();
    }
}