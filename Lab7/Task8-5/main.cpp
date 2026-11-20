#include "ArrayHelper.h"
#include "Student.h"
#include <iostream>

int main()
{
    Student students[] = {Student("Alice", 8), Student("Bob", 10), Student("Charlie", 9)};
    const size_t count = std::size(students);

    const Student topStudent = getMaximumElement(students, count);

    std::cout << "Studentul cu cea mai mare nota este: " << topStudent.getName() << " cu nota "
              << topStudent.getGrade() << std::endl;

    return 0;
}