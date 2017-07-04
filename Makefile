CC=g++
CFLAGS=-std=c++14 -O2 -Wall
ODIR=obj

%: $(ODIR)/%.o
	${CC} -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 