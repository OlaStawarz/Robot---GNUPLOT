#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/robot_scena

__start__: ./robot_scena
	./robot_scena

./robot_scena: obj obj/main.o obj/ObiektGraficzny.o\
           obj/lacze_do_gnuplota.o obj/Robot.o obj/Scena.o
	g++ -Wall -pedantic -std=c++11 -o ./robot_scena obj/main.o\
                        obj/lacze_do_gnuplota.o obj/ObiektGraficzny.o  obj/Robot.o obj/Scena.o


obj:
	mkdir -p obj

obj/Scena.o: inc/Scena.hh src/Scena.cpp
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Robot.o: inc/Robot.hh src/Robot.cpp
	g++ -c ${CXXFLAGS} -o obj/Robot.o src/Robot.cpp 

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp 
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp 

obj/main.o: src/main.cpp inc/ObiektGraficzny.hh 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/ObiektGraficzny.o: src/ObiektGraficzny.cpp inc/ObiektGraficzny.hh\
                       inc/Wektor2D.hh  inc/SWektor.hh inc/ZbiorWierzcholkow.hh 
	g++ -c ${CXXFLAGS} -o obj/ObiektGraficzny.o src/ObiektGraficzny.cpp 

clean:
	rm -f obj/*.o ./robot_scena
