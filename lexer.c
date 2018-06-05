#include "lexer.h"

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
Token *next_token(FILE *stream)
{
	Token *tok;
	size_t buflen;
	char buf[BUFSIZ], *lexeme;
	
	tok = NULL;
	while (1){
		if (feof(stream)) break;
		if (tok) break;

		fgets(buf, BUFSIZ, stream);
		buflen = strlen(buf) + 1;
		if(*buf == '/'){
			lexeme = (char *) malloc(buflen);
			strcpy(lexeme, buf);
			*(lexeme + buflen - 2) = '\0';
			tok = new_token(COMMENT, lexeme);
		}
		if(isalnum(*buf)){
			lexeme = (char *) malloc(buflen);
			strcpy(lexeme, buf);
			*(lexeme + buflen - 2) = '\0';
			tok = strchr(buf, '(') ? new_token(FUNCTION, lexeme) : new_token(VARIABLE, lexeme);	
		}
	}
	return tok;
}
