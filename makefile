default: help

help:
	@echo "my homework"

dependencies: src/IntVector.c
	gcc -c -o src/IntVector.o -Wall -Werror src/IntVector.c

compile: main.c dependencies
	gcc -o app -Wall -Werror main.c src/IntVector.o

run: app
	./app

clean:
	rm app
	rm src/IntVector.o