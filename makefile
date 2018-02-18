CFLAGS = -g

PA5: Rational.o PA5.o
	g++ $(CFLAGS) -Wall PA5.o Rational.o -o PA5

Rational.o: Rational.h Rational.cpp
	g++ $(CFLAGS) -Wall -c Rational.cpp

PA5.o: Rational.h PA5.cpp
	g++ $(CFLAGS) -Wall -c PA5.cpp

clean:
	rm -f Rational.o PA5.o PA5

all: PA5
