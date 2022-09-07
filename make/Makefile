INC =  ../inc
SRC = ../src
BIN = ../bin
OBJ = ../obj
DATA = ../data
CFLAGS = -c -g -Wall
LFLAGS = -o
GCC = gcc
IFLAGS = -I $(INC)
CVFLAGS = -v --tool=memcheck --leak-check=full --show-reachable=yes --log-file=valclient


all : $(BIN)/arp 

$(OBJ)/arp_ip.o : $(SRC)/arp_ip.c
	$(GCC) $(CFLAGS) $(SRC)/arp_ip.c $(IFLAGS)
	mv *.o ../obj

$(OBJ)/login.o : $(SRC)/login.c
	$(GCC) $(CFLAGS) $(SRC)/login.c $(IFLAGS)
	mv *.o ../obj
	
$(OBJ)/ip.o : $(SRC)/ip.c
	$(GCC) $(CFLAGS) $(SRC)/ip.c $(IFLAGS)
	mv *.o ../obj
		
$(OBJ)/account.o : $(SRC)/account.c
	$(GCC) $(CFLAGS) $(SRC)/account.c $(IFLAGS)
	mv *.o ../obj


$(BIN)/arp : $(OBJ)/login.o $(OBJ)/arp_ip.o $(OBJ)/ip.o $(OBJ)/account.o 
	$(GCC) $(OBJ)/login.o $(OBJ)/arp_ip.o $(OBJ)/ip.o $(OBJ)/account.o $(LFLAGS) $(BIN)/arp

clean:
	 rm -f $(OBJ)/*.o $(BIN)/arp
	 
	 	
valgrindclient: valgrind $(CVFLAGS) $(BIN)/arp
	mv valclient $(BIN)/
        
