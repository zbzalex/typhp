#ifndef TYPHP_IFSTMT_H
#define TYPHP_IFSTMT_H

#include "ASTNode.h"

namespace typhp {
    class IfStmt : public ASTNode {
    public:
        IfStmt() : ASTNode() {
            
        }
    };
}

#endif // TYPHP_IFSTMT_H