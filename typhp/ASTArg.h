#ifndef TYPHP_ASTARG_H
#define TYPHP_ASTARG_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class ASTArg : public ASTNode
    {
    private:
        std::string datatype_or_class_;
        std::string name_;

    public:
        ASTArg(std::string &datatype_or_class, std::string &name) : ASTNode("arg"),
                                                                    datatype_or_class_(datatype_or_class),
                                                                    name_(name)
        {
        }
    };
}

#endif // TYPHP_ASTARG_H