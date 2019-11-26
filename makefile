CC = gcc
AR = ar
OBJECTS_MAIN = main.o
OBJECTS_LIB = myBank.o
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: myBanks myBankd libmyBank.so libmyBank.a
myBanks: $(OBJECTS_MAIN) libmyBank.a
	$(CC) $(FLAGS) -o $@ $^
myBankd: $(OBJECTS_MAIN) libmyBank.so
	$(CC) $(FLAGS) -o $@ $< ./libmyBank.so
libmyBank.so: $(OBJECTS_LIB)
	$(CC) -shared -o $@ $^
libmyBank.a: $(OBJECTS_LIB)
	$(AR) -rcs $@ $^
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c $<
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o *.a *.so myBanks myBankd
