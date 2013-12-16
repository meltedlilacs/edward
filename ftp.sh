#!/bin/bash

cd /home/gabriel/Documents/Programming/git/edward

HOST='members.cruzio.com'
USER='laovel'
PASSWD=$(more password)

ftp -n -v $HOST << EOT
ascii
user $USER $PASSWD
prompt
cd edward
bye
EOT
