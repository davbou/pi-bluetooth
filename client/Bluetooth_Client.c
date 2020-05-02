
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

unsigned char* received_data;
int connection;



int main(int argc, char *argv[])
    {
    struct uinput_setup usetup;



    memset(&usetup, 0, sizeof(usetup));
    usetup.id.bustype = BUS_USB;
    usetup.id.vendor = 0x1234; /* sample vendor */
    usetup.id.product = 0x5678; /* sample product */
    strcpy(usetup.name, "Example_device");


    int sock, d, status;
    int bytes_read;
    struct sockaddr_rc laddr, raddr;
    struct hci_dev_info di;
    struct input_event InputEvent[64];
    struct input_event sync_event;

    memset(&sync_event, 0, sizeof(struct input_event));

    sync_event.type = EV_SYN;
    sync_event.code = SYN_REPORT;
    sync_event.value = 0;

    int keyboard_file = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (keyboard_file < 0)
    {
        perror("file:");
        exit(1);
    }
    ioctl(keyboard_file, UI_SET_EVBIT, EV_KEY);
    ioctl(keyboard_file, UI_SET_EVBIT, EV_SYN);
    for (size_t i = 0; i < 256; i++)
    {
        ioctl(keyboard_file, UI_SET_KEYBIT, i);
    }
    if(ioctl(keyboard_file, UI_DEV_SETUP, &usetup) < 0){
        perror("ioctl : ");
        exit(1);
    }
    ioctl(keyboard_file, UI_DEV_CREATE);
    

    if(argc < 4)
        {
        printf("%s <btaddr> <channel> <cmd>\n", argv[0]);
        exit(0);
        }

    if(hci_devinfo(0, &di) < 0) 
        {
        perror("HCI device info failed");
        exit(1);
        }

    printf("Local device %s\n", batostr(&di.bdaddr));

    laddr.rc_family = AF_BLUETOOTH;
    laddr.rc_bdaddr = di.bdaddr;
    laddr.rc_channel = 0;

    raddr.rc_family = AF_BLUETOOTH;
    str2ba(argv[1],&raddr.rc_bdaddr);
    raddr.rc_channel = atoi(argv[2]);  

    if( (sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM)) < 0)
        {
        perror("socket");
        }

    if(bind(sock, (struct sockaddr *)&laddr, sizeof(laddr)) < 0)
        {
        perror("bind");
        exit(1);
        }

    printf("Remote device %s\n", argv[1]);

    if((status = connect(sock, (struct sockaddr *)&raddr, sizeof(raddr))) < 0)    {
        perror("connect");
        exit(1);
        }
    printf("aaaa\n");
    printf("Connected.\nSending data %s\n",argv[3]);
    connection = 1;
    // Test pour voir si comm se fait
    /*
    if( status == 0 ) {
        status = write(sock, "hello!", 6);
    }
    */

    printf("aaaa\n");
    struct timeval start, stop;
    double secs = 0;



    while(connection){
        gettimeofday(&start, NULL);
        bytes_read = read(sock, InputEvent, sizeof(InputEvent));
        if (bytes_read > 0)
        {
            printf("receiving %i bytes\n", bytes_read);
            for (size_t i = 0; i < bytes_read/sizeof(struct input_event); i++)
            {
                InputEvent[i].time.tv_sec = 0;
                InputEvent[i].time.tv_usec = 0;
                write(keyboard_file, &InputEvent[i], sizeof(struct input_event));
                write(keyboard_file, &sync_event, sizeof(struct input_event));
            }
            gettimeofday(&stop, NULL);
            secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
            printf("time taken %f\n",secs);
        }
        

    }

    send(sock,argv[3],strlen(argv[3]),0);
    printf("Disconnect.\n");
    
    close(sock);
    return 0;
}