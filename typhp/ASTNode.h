#ifndef TYPHP_ASTNODE_H
#define TYPHP_ASTNODE_H

#include <vector>
#include <string>

namespace typhp
{

    class ASTNode
    {
    protected:
        ASTNode *parent_;
        std::vector<ASTNode *> children_;
        std::string id_;

    public:
        ASTNode() {}
        ASTNode(std::string &id) : id_(id) {}
        ASTNode(const std::string &id) : id_(id) {}
        ASTNode(ASTNode *parent) : parent_(parent) {}
        void add(ASTNode *child);
        void remove(ASTNode *child);
        void remove(std::string &id);
        void remove(const std::string& id);
        inline std::vector<ASTNode *> children() const { return children_; }
        inline void set_parent(ASTNode *parent) { parent_ = parent; }
        inline ASTNode *parent() const { parent_; }
        inline const std::string &get_id() const { return id_; }
    };
} // namespace typhp

#endif // TYPHP_ASTNODE_H