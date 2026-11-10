#include "Driver.h"

unsigned int Driver::getYearsOfExperience() const {return m_yearsOfExperience; }

bool Driver::hasLicenseValid() const {return m_hasLicenseValid; }

void Driver::printStandardInfo() const {
    Person::printStandardInfo();
    std::cout << "Years of Experience: " << m_yearsOfExperience << std::endl;
    std::cout << "License Valid: " << (m_hasLicenseValid ? "Yes" : "No") << std::endl;
}