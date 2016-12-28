//=============================================================================
#include "StackEntry.hpp"
//=============================================================================
namespace Nelson {
    StackEntry::StackEntry(std::string cntxt, std::string det, int id)
    {
        cname.assign(cntxt);
        detail.assign(det);
        tokid = id;
    }
    //=============================================================================
    StackEntry::StackEntry()
    {
    }
    //=============================================================================
    StackEntry::~StackEntry()
    {
    }
    //=============================================================================
}
//=============================================================================
