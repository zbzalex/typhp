#ifndef TYPHP_ASTVAR_H
#define TYPHP_ASTVAR_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class ASTVar : public ASTNode
    {
    private:
        std::string datatype_or_class_;
        std::string name_;

    public:
        ASTVar(
            std::string &name,
            std::string &datatype_or_class) : ASTNode("var"),
                                              name_(name),
                                              datatype_or_class_(datatype_or_class) {}
    }
}

#endif // TYPHP_ASTVAR_H