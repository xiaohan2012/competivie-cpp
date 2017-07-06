CXX=g++
CPPFLAGS=-std=c++11 -O2 -Wall
ODIR=obj
DEPS=my_macros.h

%: $(ODIR)/%.o
	$(CXX) -o $@ $^ $(CPPFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 