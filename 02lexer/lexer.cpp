#include "lexer.hpp"

Token::Token(TokenType tt, const char* v, int len) {
  type = tt;
  vlaue = v;
  length = len;
}