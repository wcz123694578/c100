//
// Created by wzx12 on 2024/6/6.
//

#include "AstNode.h"

using namespace C100;

void BinaryNode::Accept(AstVisitor *visitor) {
    visitor->VisitorBinaryNode(this);
}

void ConstantNode::Accept(AstVisitor *visitor) {
    visitor->VisitorConstantNode(this);
}

void ProgramNode::Accept(AstVisitor *visitor) {
    visitor->VisitorProgramNode(this);
}
