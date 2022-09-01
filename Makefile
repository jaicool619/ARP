all: arp

arp: client.o login.o delay.o account.o mac_valid.o
	gcc arp.h client.c login.c delay.c account.c mac_valid.c -o arp
      
client.o: client.c 
	gcc -c arp.h client.c 
	
login.o: login.c
	gcc -c arp.h login.c
	
delay.o: delay.c
	gcc -c arp.h delay.c

account.o: account.c
	gcc -c arp.h account.c

mac_valid.o: mac_valid.c
	gcc -c arp.h mac_valid.c
        
clean:
	rm -f arp
