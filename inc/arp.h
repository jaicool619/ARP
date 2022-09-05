#include <stdio.h>
#include <stdlib.h>
#include <string.h>       //for strings:
#include <unistd.h>       //defines miscellaneous symbolic constants and types,and declares miscellaneous functions:
#include <math.h>         //used for arithmatic function:
#include <sys/types.h>  //it defines the data types and structure
#include <sys/socket.h> //it contains a datatype declaration of socket
#include <net/if_arp.h>
#include <errno.h>
#include <sys/ioctl.h> //it contains definitions related to display window like TTY window,socket controls,tcp/ip (network)etc.
#include <complex.h>      //Expands to a constant expression of type const float _Complex:
#include <arpa/inet.h>    //header makes available the in_addr structure:
#include <netinet/in.h>   //used for network programming:
#include <net/ethernet.h> // enables network connection (local and Internet):
#include <ctype.h> //it declares several functions that are useful for testing and mapping characters:

// macro definition:
#define TRUE 1
#define FALSE 0
#define NUM 30
#define VAR 20
#define DELAY 1000000
#define MIN_LIMIT 0
#define MAX_LIMIT 5
#define SIZE 20
#define PRE_PASS "123" // pre-defined password for the admin login

int ip();
int adminLogin(); // declaration of admin login function:
int intoAcc();    // declaration of intoAcc function:
void fordelay(int);
int isValidMacAddress(const char *); // declaration of isValidMacAddress function
