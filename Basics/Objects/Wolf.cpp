#include <sstream>
#include "Wolf.h"

namespace objects
{

    string Wolf::toString()
    {
        stringstream ss;
        ss << "I'm a " << age << " year old " << gender << " wolf." << endl;
        if (isSingle)
        {
            ss << "I'm single." << endl;
        }
        else
        {
            ss << "I'm married." << endl;
        }

        if (hasPack)
        {
            ss << "I have a pack." << endl;
        }
        else
        {
            ss << "I don't have a pack." << endl;
        }
        return ss.str();
    }
} // namespace objects