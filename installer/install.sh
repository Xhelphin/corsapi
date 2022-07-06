#!/bin/sh

if [ "$EUID" -ne 0 ]
    then echo "Please run as root"
    exit
fi

mkdir /opt/corsapi/
mv ../controller /opt/corsapi/controller
mv /opt/corsapi/controller/service/corsapi.service /etc/systemd/system/corsapi.service
systemctl enable corsapi
systemctl start corsapi