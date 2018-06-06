#include "lexer.h"

/* ENUMS */
enum Tags{
	TYPEDEF, STRUCT, ENUM, EXTERN, CONST, FUNCTION
};

/* STRUCTS */
struct Token{
	int tag;
	char *lexeme;
};

/* CONSTS */
const char *keywords[] = {
	"typedef", "struct", "enum", "extern", "const"
};

/* PRIVATE FUNCTIONS */
int lexeme_type(const char *lexeme)
{
	int i, tag;
	
	tag = FUNCTION;
	for (i = 0; i < length(keywords); i++){
		if (!strcmp(lexeme, keywords[i])){
			tag = i; break;
		}
	}
	return tag;
}

/* PUBLIC FUNCTIONS */
Token *new_token(int tag, char *lexeme)
{
	Token *tok;

	tok = (Token *) malloc(sizeof(Token));
	tok->tag = tag;
	tok->lexeme = (char *) malloc(sizeof(char) * strlen(lexeme));
	strcpy(tok->lexeme, lexeme);

	return tok;
}
Token *delete_token(Token *tok)
{
	free(tok->lexeme);
	free(tok);
	return NULL;
}
int get_tag(const Token *tok)
{
	return tok->tag;
}
char *get_lexeme(const Token *tok)
{
	char *lexeme;

	lexeme = (char *) malloc(strlen(tok->lexeme));
	strcpy(lexeme, tok->lexeme);
	return lexeme;
}
Token *next_token(FILE *stream)
{
	Token *tok;
	char buf[BUFSIZ], temp[BUFSIZ];
	
	tok = NULL;
	while (1){
		if (feof(stream)) break;
		if (tok) break;

		fgets(buf, BUFSIZ, stream);
		if (sscanf(buf, "%[A-Za-z]", temp)){
			*(buf + strlen(buf)- 2) = '\0';
			tok = new_token(lexeme_type(temp), buf);
		}
	}
	return tok;
}
