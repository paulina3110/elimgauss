all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all test1 test2 test3 test4 test5

test: all
	@echo "Test 0 - domyslne dane"
	bin/gauss dane/A dane/b

test1: all
	@echo "Test 1 - zly rozmiar ukladu"
	bin/gauss dane1/A dane1/b

test2: all
	@echo "Test 2 - zera na diagonali"
	bin/gauss dane2/A dane2/b

test3: all
	@echo "Test 3 - macierz osobliwa"
	bin/gauss dane3/A dane3/b

test4: all
	@echo "Test 4 - macierz 5na 5"
	bin/gauss dane4/A dane4/b
