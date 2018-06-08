CC=gcc -std=c89 -Wpedantic -Wall
FILES=main.c lexer.c
OUT=-o mkdoc

build: $(FILES)
	$(CC) $(FILES) $(OUT)
debug: $(FILES)
	$(CC) $(FILES) $(OUT) -g
	
