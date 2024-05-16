OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Cubeta.o Lavadora.o Prenda.o
	g++ -o program.exe program.o Cubeta.o Lavadora.o Prenda.o

Prenda.o: Prenda.cc Prenda.hh PRO2Excepcio.hh
	g++ -c Prenda.cc $(OPCIONS)

Lavadora.o: Lavadora.cc Lavadora.hh PRO2Excepcio.hh
	g++ -c Lavadora.cc $(OPCIONS)

Cubeta.o: Cubeta.cc Cubeta.hh PRO2Excepcio.hh
	g++ -c Cubeta.cc $(OPCIONS)

program.o: program.cc readbool.hh
	g++ -c program.cc $(OPCIONS)

entrega:
	tar -cvf entrega.tar Makefile Cubeta.cc Lavadora.cc Prenda.cc program.cc

clean:
	rm *.o
	rm *.exe