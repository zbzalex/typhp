#ifndef TYPHP_HTMLTEXT_H
#define TYPHP_HTMLTEXT_H

#include "ASTNode.h"
#include <string>

namespace typhp
{
    class HtmlText : public ASTNode
    {
    public:
        std::string value;

        HtmlText(
            const std::string &html) : ASTNode(), value(html) {}

        virtual const std::string generate() const override;
    };
}

#endif // TYPHP_HTMLTEXT_H