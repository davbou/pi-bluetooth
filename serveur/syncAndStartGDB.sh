#!/bin/bash
set -e

# Sync executable
bn=$(basename $1)
rsync -az $1/build/tp5bluetooth pi@$2:/home/pi/projects/pi-bluetooth/tp5bluetooth
#laboratoire2/tp2serveur

# Execute GDB
#ssh pi@$2 "nohup gdbserver :4567 /home/pi/projects/pi-bluetooth/tp5bluetooth > /dev/null 2> /dev/null < /dev/null &"
sleep 1