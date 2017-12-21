TARGETS := $(patsubst %.cpp,%,$(wildcard *.cpp))
CXXFLAGS += -std=c++14 -O3

all: $(TARGETS)

%: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
