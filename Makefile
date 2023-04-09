all:
	gcc -Iinclude -Llib src/*.c -o bin/text_editor -lmingw32 -lSDL2 -lSDL2main