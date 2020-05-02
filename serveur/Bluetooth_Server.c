
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#define CHANNEL 4

int open_input_file(){
    int file;

	if ((file = open("/dev/input/event0", O_RDONLY)) < 0)		
	{
		perror("KeyboardMonitor can't open input device");
		close(file);
		exit(1);
	}

    return file;
}

int main(void)
{
    int sock, client, connection, bytes_read;
    size_t alen;
    struct sockaddr_rc addr;
    char buf[1024] = { 0 };
    int bytes_read_from_keyboard = 0;
    int keyboard_file = open_input_file();
	struct input_event InputEvent[64];


    if( (sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM)) < 0)
    {
        perror("socket");
        exit(1);
    }

    addr.rc_family = AF_BLUETOOTH;
    bacpy(&addr.rc_bdaddr, BDADDR_ANY);
    addr.rc_channel = htobs(CHANNEL);
    alen = sizeof(addr);

    if(bind(sock, (struct sockaddr *)&addr, alen) < 0)
    {
        perror("bind");
        exit(1);
    }

    listen(sock,1);
    printf("Waiting for connections...\n\n");  

    client = accept(sock, (struct sockaddr *)&addr, &alen);
    printf("Got a connection attempt!\n");

    connection = 1;

    

    while(connection){

        bytes_read = read(keyboard_file, InputEvent, sizeof(InputEvent));
        if( bytes_read > 0 ) {
            send(client ,(char*) InputEvent ,bytes_read,0);
            printf("sending %i bytes\n", bytes_read);
        }
    }
    close(client);


    close(sock);
    return 0;
}