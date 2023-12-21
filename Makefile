all: gauss

gauss: src/*.c
	gcc -Wall --pedantic $^ -o bin/$@

test: test0 test1 test2 test3 test4

test0: all
	@echo "Test 0 - domyslne dane"
	bin/gauss dane/A dane/b
	@echo

test1: all
	@echo "Test 1 - zly rozmiar ukladu"
	bin/gauss dane1/A dane1/b || true
	@echo

test2: all
	@echo "Test 2 - zera na diagonali"
	bin/gauss dane2/A dane2/b
	@echo

test3: all
	@echo "Test 3 - macierz osobliwa"
	bin/gauss dane3/A dane3/b || true
	@echo

test4: all
	@echo "Test 4 - macierz 5 na 5"
	bin/gauss dane4/A dane4/b
	@echo

clean:
	rm -f bin/*
