#pragma once

#include <iostream>
#include <string>
#include <vector>

//wrapper class
class Group {
public:
    explicit Group(std::string  groupName = "");
    ~Group();

    Group(const Group& other);
    Group& operator=(const Group& other);

    Group(Group&& other) noexcept;
    Group& operator=(Group&& other) noexcept;

    void addStudent(const std::string& name, int id);
    void displayGroup() const;

private:

    // enclosed class
    class Student {
    public:
        Student(std::string  name, int id);
        ~Student() = default;

        void displayInfo() const;

    private:
        std::string m_name;
        int m_id;
    };

private:
    std::string m_groupName;
    std::vector<Student*> m_students{};
};