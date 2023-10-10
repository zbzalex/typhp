#ifndef TYPHP_ASTFUNCTION_H
#define TYPHP_ASTFUNCTION_H

#include "ASTNode.h"
#include <string>
#include <vector>
#include "ASTArg.h"

namespace typhp
{
    class ASTFunction : public ASTNode
    {
        enum MethodModifier
        {
            MethodModifier_PUBLIC,
            MethodModifier_PROTECTED,
            MethodModifier_PRIVATE,
        };

    private:
        std::string name_;
        MethodModifier modifier_;
        std::string return_type_;

    public:
        // lambda
        ASTFunction() : anonymouse_(true)
        {
        }

        ASTFunction(std::string &name) : ASTNode("function"),
                                         name_(name)
        {
        }

        ASTFunction(const std::string &name) : ASTNode("function"),
                                               name_(name) {}

        ASTFunction(std::string &name, MethodModifier modifier) : ASTNode("function"),
                                                                  name_(name),
                                                                  modifier_(modifier)
        {
        }

        ASTFunction(const std::string &name, MethodModifier modifier) : ASTNode("function"),
                                                                        name_(name),
                                                                        modifier_(modifier)
        {
        }

        inline const std::string get_name() const { return name_; }

        inline const MethodModifier get_modifier() const { return modifier_; }

        inline const std::string &get_return_type() const { return return_type_; }

        inline const std::vector<ASTArg *> get_args() const
        {
            std::vector<ASTArg *> args;

            return args;
        }
    };
}

#endif // TYPHP_ASTFUNCTION_H