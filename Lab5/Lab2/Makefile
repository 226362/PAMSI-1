G = g++
GFLAGS = -Wall -pedantic -g -std=c++11 -Iinc

tabl: obj/tabl.o src/main.cpp inc/tabl.hh inc/main.hh
	$(G) $(GFLAGS) ./obj/tabl.o ./src/main.cpp -o tabl

obj/tabl.o: src/tabl.cpp inc/tabl.hh
	$(G) $(GFLAGS) -c ./src/tabl.cpp -o ./obj/tabl.o

clean:
	rm -fr ./obj/*.o tabl
