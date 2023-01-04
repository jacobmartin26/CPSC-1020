OBJS=mainDriver.o manip.o Pixel.o Header.o Image.o 

CFLAGS=-Wall -g

out: $(OBJS)
	g++ -Wall -o out -g $(OBJS) 

$(OBJS): $(INCLUDE) makefile

.cpp.o: $<
	-g++ -c $(CFLAGS) -c $< -o $@ 
	cat $*.err

clean:
	rm out


