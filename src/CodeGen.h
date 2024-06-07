//
// Created by wzx12 on 2024/6/6.
//

#ifndef C100_CODEGEN_H
#define C100_CODEGEN_H

#include "AstNode.h"

namespace C100  {
    class CodeGen : public AstVisitor   {
    private:
        int StackLevel{0};
    public:
        CodeGen() {}
        void VisitorProgramNode(ProgramNode *node) override;

    private:
        void VisitorBinaryNode(BinaryNode *node) override;
        void VisitorConstantNode(ConstantNode *node) override;

        void Push();
        void Pop(const char *reg);
    };
}


#endif //C100_CODEGEN_H
