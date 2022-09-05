INC =  /home/jaidev/Documents/Sprint2/inc
SRC = /home/jaidev/Documents/Sprint2/src
BIN = /home/jaidev/Documents/Sprint2/bin
OBJ = /home/jaidev/Documents/Sprint2/obj
DATA = /home/jaidev/Documents/Sprint2/data
CFLAGS = -c -g -Wall
LFLAGS = -o
GCC = gcc
IFLAGS = -I $(INC)
CVFLAGS = -v --tool=memcheck --leak-check=full --show-reachable=yes --log-file=valclient


all : $(BIN)/arp

$(OBJ)/arp_ip.o : $(SRC)/arp_ip.c
	$(GCC) $(CFLAGS) $(SRC)/arp_ip.c $(IFLAGS)
	mv *.o /home/jaidev/Documents/Sprint2/obj

$(OBJ)/login.o : $(SRC)/login.c
	$(GCC) $(CFLAGS) $(SRC)/login.c $(IFLAGS)
	mv *.o /home/jaidev/Documents/Sprint2/obj
	
$(OBJ)/ip.o : $(SRC)/ip.c
	$(GCC) $(CFLAGS) $(SRC)/ip.c $(IFLAGS)
	mv *.o /home/jaidev/Documents/Sprint2/obj
	
$(OBJ)/delay.o : $(SRC)/delay.c
	$(GCC) $(CFLAGS) $(SRC)/delay.c $(IFLAGS)
	mv *.o /home/jaidev/Documents/Sprint2/obj
	
$(OBJ)/account.o : $(SRC)/account.c
	$(GCC) $(CFLAGS) $(SRC)/account.c $(IFLAGS)
	mv *.o /home/jaidev/Documents/Sprint2/obj
	
$(OBJ)/mac_valid.o : $(SRC)/mac_valid.c
	$(GCC) $(CFLAGS) $(SRC)/mac_valid.c $(IFLAGS)
	mv *.o /home/jaidev/Documents/Sprint2/obj
	

$(BIN)/arp : $(OBJ)/login.o $(OBJ)/arp_ip.o $(OBJ)/ip.o  $(OBJ)/delay.o $(OBJ)/account.o $(OBJ)/mac_valid.o
	$(GCC) $(OBJ)/login.o $(OBJ)/arp_ip.o $(OBJ)/ip.o $(OBJ)/delay.o $(OBJ)/account.o $(OBJ)/mac_valid.o $(LFLAGS) $(BIN)/arp
        
clean:
	 rm -f $(OBJ)/*.o $(BIN)/arp
