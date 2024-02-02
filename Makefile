CFLAGS ?= -O1 -g

default: pangck

pangck:
	g++ $(CFLAGS) -o pangck main.cpp pangcheck.cpp

clean:
	rm -f pangck
