#ifndef TYPHP_ASTCLASS_H
#define TYPHP_ASTCLASS_H

#include "ASTNode.h"
#include <string>
#include "ASTArg.h"
#include "ASTFunction.h"

namespace typhp
{
    class ASTClass : public ASTNode
    {
        enum ClassFlag
        {
            ClassFlag_NONE,
            ClassFlag_ABSTRACT,
            ClassFlag_FINAL,
        };

    private:
        ClassFlag flag_;
        std::string name_;

    public:
        ASTClass(std::string &name) : ASTNode("class"), name_(name)
        {
        }

        ASTClass(const std::string &name, ClassFlag flag) : ASTNode("class"),
                                                            name_(name),
                                                            flag_(flag) {}

        ASTFunction *get_method(std::string &name)
        {
            std::vector<ASTNode *>::iterator it = children_.begin();

            for (;
                 it != children_.end();
                 it++)
            {
                ASTNode *node = *it;

                if (node->get_type() == "function")
                {
                    ASTFunction *func = static_cast<ASTFunction *>(node);
                    if (func->get_name() == name)
                        return func;
                }
            }

            return nullptr;
        }

        ASTFunction *get_method(const std::string &name)
        {
            return get_method(name);
        }

        bool is_invokable()
        {
            return get_method("__invoke") != nullptr;
        }

        ASTFunction *get_constructor()
        {
            return get_method("__construct");
        }

        ASTFunction *get_destructor()
        {
            return get_method("__destruct");
        }

        bool is_abstract()
        {
            return flag_ == ClassFlag_ABSTRACT;
        }

        bool is_final()
        {
            return flag_ == ClassFlag_FINAL;
        }
    };
}

#endif //