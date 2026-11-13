#include "Group.h"

int main() {
    Group g1("Grupa 6769");
    g1.addStudent("Popescu Ion", 101);
    g1.addStudent("Ionescu Maria", 102);

    // Test Copy Constructor
    Group g2 = g1;

    // Test Copy Assignment
    Group g3("Grupa Temporara");
    g3 = g1;

    // Test Move Constructor
    Group g4 = std::move(g2);

    // Test Move Assignment
    Group g5;
    g5 = std::move(g3);

    g1.displayGroup();
    g4.displayGroup();
    g5.displayGroup();

    return 0;
}