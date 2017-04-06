#CPP 	= g++
CPP 	= clang++
HEADER = ./Library/Library/include
VPATH = ./Library/Library/src
CFLAGS 	= -Wall -I$(HEADER) -g

OBJ = ueb1.o tdate.o ttime.o
#OBJ2 = ueb2.o taddress.o tlocation.o tdate.o tperson.o
OBJ2 = ueb2.o TAddress.o TDate.o TLocation.o TPerson.o TTime.o
OBJ4 = ueb04.o TAddress.o TDate.o TLocation.o TPerson.o TTime.o TLibraryPool.o TMedium.o TLibrary.o
OBJ5 = ueb05.o TAddress.o TDate.o TLocation.o TPerson.o TTime.o TLibraryPool.o TMedium.o TLibrary.o TCustomer.o TEmployee.o TBook.o TCD.o TDVD.o TComic.o TAudiobook.o TLoan.o
OBJ7 = ueb05.o TAddress.o TDate.o TLocation.o TPerson.o TTime.o TLibraryPool.o TMedium.o TLibrary.o TCustomer.o TEmployee.o TBook.o TCD.o TDVD.o TComic.o TAudiobook.o TLoan.o tlist.o
LIST = list.o tlist.o

ueb07: $(OBJ7)
	$(CPP) $(CFLAGS) -o ueb07 $(OBJ7)

ueb05: $(OBJ5)
	$(CPP) $(CFLAGS) -o ueb05 $(OBJ5)

ueb04: $(OBJ4)
	$(CPP) $(CFLAGS) -o ueb04 $(OBJ4)

ueb2: $(OBJ2)
	$(CPP) $(CFLAGS) -o ueb2 $(OBJ2)

ueb1: $(OBJ)
	$(CPP) $(CFLAGS) -o ueb1 $(OBJ)
list: $(LIST)
	$(CPP) $(CFLAGS) -o list $(LIST)

clean:
	rm -f *.bak *~ *.o

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $<
