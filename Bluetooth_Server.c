
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>

#define CHANNEL 4

int main(void)
{
    int sock, client, alen,connection,bytes_read;
    struct sockaddr_rc addr;
    char buf[1024] = { 0 };

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

        bytes_read = read(client, buf, sizeof(buf));
        if( bytes_read > 0 ) {
            printf("received [%s]\n", buf);
        }
    }
    close(client);


    close(sock);
    return 0;
}