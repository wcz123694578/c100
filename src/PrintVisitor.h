//
// Created by wzx12 on 2024/6/6.
//

#ifndef C100_PRINTVISITOR_H
#define C100_PRINTVISITOR_H

#include "AstNode.h"
#include <iostream>

namespace C100  {
    class PrintVisitor : public AstVisitor  {
    public:
        std::string Content;
    public:
        void VisitorProgramNode(ProgramNode *node) override;

    private:
        void VisitorBinaryNode(BinaryNode *node) override;
        void VisitorConstantNode(ConstantNode *node) override;
    };
}



#endif //C100_PRINTVISITOR_H
