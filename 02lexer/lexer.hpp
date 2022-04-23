#ifndef LEXER_HPP
#define LEXER_HPP

enum TokenType {
  T_INIT,
  T_NAME,

  T_LEFT_PAR,
  T_RIGHT_PAR,

  T_PLUS,
  T_SUB
};

class Token {
public:
  TokenType type;
  const char* vlaue;
  int length;

  Token(TokenType tt, const char* v, int len);
  void print();
};

enum State {
  INIT,
  INTEGER,
  NAME,
  OP_EQ,
  OP_GT,

  OP_ADD,
  OP_SUB,
  OP_MUL,
  OP_DIV
};

class Lexer {
public:
  Lexer(const char* src);
  Token *Next();

private:
  const char *src;
  int index;
  State state;
  int length;
};
#endif