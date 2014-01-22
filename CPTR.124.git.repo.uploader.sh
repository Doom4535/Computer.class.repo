#!/bin/bash

mkdir Temp.Cache

# wget -O Temp.Cache "http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip"

curl http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip -o Temp.Cache/CPTR_124_Class_Code.zip

cd Temp.Cache

mkdir Temp.extract

unzip *.zip -d Temp.extract

rsync -rSP Temp.extract/* /Users/Aaron/Git.Repositories/Computer.class.repo

rm -vr *.zip

rm -vr Temp.extract

cd ..

rmdir Temp.Cache

cd ~/Git.Repositories/Computer.class.repo

git add .

git commit -m "Dominion"

git remote add origin https://github.com/Doom4535/Computer.class.repo

git push

