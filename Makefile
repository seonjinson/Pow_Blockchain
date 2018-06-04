#Makefile for "pow_blockchain" c++ application
#Created by seonjin son 4/jun/2018
PROG = a_out
CC = g++
OBJS = main.o block.o sha256.o jsoncpp.o
$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)
main.o :
	$(CC) -c src/main.cpp

block.o : src/block.h
	$(CC) -c src/block.cpp

sha256.o : src/sha256.h
	$(CC) -c src/sha256.cpp

jsoncpp.o : src/json/json-forwards.h src/json/json.h
	$(CC) -c src/jsoncpp.cpp

clean:
	rm -f core $(PROG) $(OBJS)
