#include "Mosquito.h"

bool Mosquito::isDeadly() const { return m_isDeadly; }

void Mosquito::bite(Person& p) const
{
    if (isDeadly() && p.getIsAllergicToMosquitoes()) {
        p.receiveBite();
    }
}
