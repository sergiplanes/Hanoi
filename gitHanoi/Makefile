# Programa: Torres de Hanoi
# Makefile
# Autor:Sergi Planes, 16-06-2015

cn22: inputoutput.o ordena.o main.o hanoi.o
	gcc -o cn22 inputoutput.o ordena.o main.o hanoi.o

inputoutput.o:  inputoutput.c cap.h
	gcc -c inputoutput.c

ordena.o: ordena.c cap.h
	gcc -c ordena.c

hanoi.o: hanoi.c cap.h
	gcc -c hanoi.c

main.o: main.c cap.h
	gcc -c main.c

clean:
	rm *.o cn22