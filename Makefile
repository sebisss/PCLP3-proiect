build:
	gcc *.c -g  main.c optiuni.c restaurant.h -o Comenzi


run: build
	./Comenzi


