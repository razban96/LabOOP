#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"

class Drawing {

public:
    // Dependency Injection
  explicit Drawing(Shape* shape);

    void drawShape() const;

private:
    Shape* pShape;

};

#endif // DRAWING_H