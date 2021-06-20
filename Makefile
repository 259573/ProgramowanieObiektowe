Projekt1: main.o menu.o tablica.o tablica_wysw.o operacje_na_plikach.o
	g++ main.cpp menu.cpp tablica.cpp tablica_wysw.cpp operacje_na_plikach.cpp -g -o Projekt1
clean:
	rm -f Projekt1