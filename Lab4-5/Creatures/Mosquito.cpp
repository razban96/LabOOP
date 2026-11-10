#include "Mosquito.h"

bool Mosquito::isDeadly() const { return m_isDeadly; }

const std::string& Mosquito::getSpecies() const { return m_species; }

void Mosquito::bite(Person& p) const
{
    if (isDeadly() && p.getIsAllergicToMosquitoes()) {
        p.receiveBite();
    }
}
