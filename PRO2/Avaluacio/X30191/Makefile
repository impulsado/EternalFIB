OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o numNegative.o utils.o
	g++ -o ./main.exe ./main.o ./numNegative.o ./utils.o
	rm *.o

main.o: main.cc
	g++ -c  $(OPCIONS) ./main.cc

numNegative.o: numNegative.cc
	g++ -c  $(OPCIONS) ./numNegative.cc

utils.o: utils.cc
	g++ -c  $(OPCIONS) ./utils.cc

clean:
	rm *.o