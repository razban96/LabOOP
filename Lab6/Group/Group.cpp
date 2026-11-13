#include "Group.h"

#include <utility>

// Student
Group::Student::Student(std::string  name, const int id)
    : m_name(std::move(name)), m_id(id) {}

void Group::Student::displayInfo() const {
    std::cout << "Student ID: " << m_id << ", Name: " << m_name << "\n";
}

// Group

Group::Group(std::string groupName)
    : m_groupName(std::move(groupName)) {}

Group::~Group() {
    for (const Student* s : m_students) {
        delete s;
    }
    m_students.clear();
}

// Copy Constructor
Group::Group(const Group& other)
    : m_groupName(other.m_groupName) {

    // dam emplace la studenti
    m_students.reserve(other.m_students.size());
    for (const Student* s : other.m_students) {
        m_students.emplace_back(new Student(*s));
    }
}

//Copy Assignment Operator
Group& Group::operator=(const Group& other) {
    if (this == &other) {
        return *this;
    }


    for (const Student* s : m_students) {
        delete s;
    }
    m_students.clear();

    m_students.reserve(other.m_students.size());
    // emplace back la studenti
    m_groupName = other.m_groupName;
    for (const Student* s : other.m_students) {
        m_students.emplace_back(new Student(*s));
    }

    return *this;
}

//Move Constructor
Group::Group(Group&& other) noexcept
    : m_groupName(std::move(other.m_groupName)),
      m_students(std::move(other.m_students)) {

    //other.m_groupName = "";
    other.m_students.clear();
}

//Move Assignment Operator
Group& Group::operator=(Group&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    for (const Student* s : m_students)
    {
        delete s;
    }
    m_students.clear();

    m_groupName = std::move(other.m_groupName);
    m_students = std::move(other.m_students);

    //other.m_groupName = "";
    other.m_students.clear();

    return *this;
}

void Group::addStudent(const std::string& name, const int id) {
    m_students.push_back(new Student(name, id));
}

void Group::displayGroup() const {
    std::cout << "Group: " << m_groupName << "\n";
    for (const Student* s : m_students) {
        s->displayInfo();
    }
}