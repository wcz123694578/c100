#include <stdio.h>
#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "PrintVisitor.h"
#include "CodeGen.h"

using namespace C100;

const char *code = " 5 + 1a100 + (1 - 3) * 4 / 2";

void testLex()  {
    Lexer lex(code);
    do {
        lex.GetNextToken();
        std::cout << lex.CurrentToken->Content << std::endl;
    } while (lex.CurrentToken->Kind != C100::TokenKind::Eof);
}

void testParser()   {
    Lexer lex(code);
    lex.GetNextToken();

    Parser parser(lex);
    PrintVisitor visitor;

    auto root = parser.Parse();
    root->Accept(&visitor);
    std::cout << visitor.Content;
}

void testCodeGen(int argc, char *argv[])  {
    if (argc != 2)  {
        printf("please input: .\\c100 code\n");
        return;
    }

    const char *source = argv[1];

    Lexer lex(source);
    lex.GetNextToken();

    Parser parser(lex);
    CodeGen codeGen;

    auto root = parser.Parse();
    root->Accept(&codeGen);
}

int main(int argc, char *argv[]) {
    testLex();
    // testParser();
    // testCodeGen(argc, argv);
    return 0;
}
