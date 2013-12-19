#!/bin/bash
cd ~/Documents/Programming/git/edward
git add .
DATE=$(date)
git commit -m "$DATE"
git push
./ftp.sh $1
