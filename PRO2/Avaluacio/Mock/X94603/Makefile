OPTIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

main.exe: main.o mergeIntoFirstList.o
	g++ -o ./main.exe ./main.o ./mergeIntoFirstList.o
	rm *.o

main.o: main.cc
	g++ -c $(OPTIONS) ./main.cc

mergeIntoFirstList.o: mergeIntoFirstList.cc
	g++ -c $(OPTIONS) ./mergeIntoFirstList.cc