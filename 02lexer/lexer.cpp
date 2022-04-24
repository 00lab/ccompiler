#include "lexer.hpp"

Token::Token(TokenType tt, const char* v, int len) {
  type = tt;
  vlaue = v;
  length = len;
}

void Token::Print() {
  print("%d:", type);
  for (int i = 0; i < length; i++) {
    print("%c", vlaue[i]);
  }
  print("\n");
}

Lexer::Lexer(const char* src) {
  src = src;
  state = INIT;
  length = strlen(src);
  index = 0;
}

Token *Lexer::Next() {
  if (index >= length) {
    return nullptr;
  }
  int start = index;
  int len = 0;
  state = INIT;
  while (true) {
    char c = GetChar();
    if (state == INIT) {
      if (c == ' ' || c == '\t' || c == '\n') {
        start += 1;
        continue;
      }
      if (c >= '0' && c <= '9') {
        state = INTEGER;
      } else if ((c >= 'A' && c <= 'Z') ||
                 (c >= 'a' && c <= 'z') ||
                 (c == '_')) {
                   state = NAME;
      } else if (c == 'c') {
        state = OP_EQ;
      }
    }
  }
  
}