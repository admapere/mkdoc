#include <stdio.h>
#include <stdlib.h>
#include <stderr.h>
#include "lexer.h"

int main(int argc, char *argv[])
{
	while(1){
		Token *tok;
		char *lexeme;

		if (feof(stdin)) break;

		tok = next_token(stdin);
		if (tok){
			printf("<%d, %s>\n",
				get_tag(tok), lexeme = get_lexeme(tok));
			free(lexeme);
			lexeme = NULL;
			tok = delete_token(tok);
		}
	}	
	return EXIT_SUCCESS;
}
