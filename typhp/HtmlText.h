#ifndef TYPHP_HTMLTEXT_H
#define TYPHP_HTMLTEXT_H

#include "ASTNode.h"
#include <string>
#include <typeinfo>

namespace typhp
{
    class HtmlText : public ASTNode
    {
    public:
        std::string value;

        HtmlText(
            const std::string &html) : ASTNode(), value(html) {}

        const std::type_info &type() { return typeid(HtmlText); }
    };
}

#endif // TYPHP_HTMLTEXT_H