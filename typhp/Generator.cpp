#include "Generator.h"
#include <type_traits>
#include "PhpCode.h"
#include "Comment.h"
#include <iostream>
#include <typeinfo>

namespace typhp
{
    std::string Generator::generate()
    {
        std::string out{""};

        std::vector<ASTNode *> children = root_->children();
        std::vector<ASTNode *>::iterator it = children.begin();
        for (
            ;
            it != children.end();
            ++it)
        {
            auto *ast = *it;
            
            // if (ast->type() == typeid(Comment))
            // {
            //     Comment *ast_ = dynamic_cast<Comment *>(ast);
            //     out += ast_->value;
            //     out += "\n";
            // }
        }

        return out;
    }
}