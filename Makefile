CXX ?= g++
CXXFLAGS ?= -O2 -g


default: pangck

pangck:
	$(CXX) $(CXXFLAGS) -o pangck main.cpp pangcheck.cpp

clean:
	rm -f pangck

.PHONY: default clean
