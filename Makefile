FLAGS = -Wall -pedantic -std=c++11 

Projekt1.out : main.o menu.o tablica.o tablica_wysw.o operacje_na_plikach.o
	g++ -o Projekt1.out main.o menu.o tablica.o tablica_wysw.o operacje_na_plikach.o

main.o : main.cpp
	g++ -c ${FLAGS} -o main.o main.cpp

menu.o : menu.cpp
	g++ -c ${FLAGS} -o menu.o menu.cpp

tablica.o : tablica.cpp
	g++ -c ${FLAGS} -o tablica.o tablica.cpp

tablica_wysw.o : tablica_wysw.cpp
	g++ -c ${FLAGS} -o tablica_wysw.o tablica_wysw.cpp

operacje_na_plikach.o : operacje_na_plikach.cpp	
	g++ -c ${FLAGS} -o operacje_na_plikach.o operacje_na_plikach.cpp