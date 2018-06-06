#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define length(x) (sizeof(x) / sizeof(*x))

typedef struct Token Token;

Token *new_token(int tag, char *lexeme);
Token *delete_token(Token *tok);
int get_tag(const Token *tok);
char *get_lexeme(const Token *tok);
Token *next_token(FILE *stream);

#endif
