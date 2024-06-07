//
// Created by wzx12 on 2024/6/6.
//

#include "Lexer.h"
#include <cstring>
#include <cstdio>
#include <cctype>

void C100::Lexer::GetNextChar() {
    if (Cursor == SourceCode.size())    {
        CurChar = '\0';
        Cursor++;
    } else  {
        CurChar = SourceCode[Cursor++];
    }
}

void C100::Lexer::GetNextToken() {
    /// 1. skip white space
    while (isspace(CurChar))    {
        GetNextChar();
    }

    TokenKind kind;

    int value = 0;
    int startPos = Cursor - 1;
    if (CurChar == '\0')    {
        kind = TokenKind::Eof;
    } else if (CurChar == '+')  {
        kind = TokenKind::Add;
        GetNextChar();
    } else if (CurChar == '-')  {
        kind = TokenKind::Sub;
        GetNextChar();
    } else if (CurChar == '*')  {
        kind = TokenKind::Mul;
        GetNextChar();
    } else if (CurChar == '/')  {
        kind = TokenKind::Div;
        GetNextChar();
    } else if (isdigit(CurChar))    {
        kind = TokenKind::Num;
        value = 0;
        do {
            value = value * 10 + CurChar - '0';
            GetNextChar();
        } while (isdigit(CurChar));
    } else  {
        printf("error: not support %c\n", CurChar);
    }
    CurrentToken = std::make_shared<Token>();
    CurrentToken->Kind = kind;
    CurrentToken->Value = value;
    CurrentToken->Content = SourceCode.substr(startPos, Cursor - 1 - startPos);
}