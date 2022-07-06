#!/bin/sh

if [ "$EUID" -ne 0 ]
    then echo "Please run as root"
    exit
fi

systemctl stop corsapi
systemctl disable corsapi
rm -rf /opt/corsapi
rm -rf /etc/systemd/system/corsapi.service

echo "Done"