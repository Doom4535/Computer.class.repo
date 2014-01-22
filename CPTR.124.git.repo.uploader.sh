#!/bin/bash

# wget -O /Users/Aaron/Temp/CPTR.124.Temp "http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip"

curl http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip -o /Users/Aaron/Temp/CPTR.124.Temp/CPTR_124_Class_Code.zip

cd /Users/Aaron/Temp/CPTR.124.Temp

unzip *.zip -d /Users/Aaron/Temp/CPTR.124.Temp/Temp.extract

rsync -rSP /Users/Aaron/Temp/CPTR.124.Temp/Temp.extract/* /Users/Aaron/Git.Repositories/Computer.class.repo

rm -r /Users/Aaron/Temp/CPTR.124.Temp/*.zip

rm -r /Users/Aaron/Temp/CPTR.124.Temp/Temp.extract/*

cd /Users/Aaron/Git.Repositories/Computer.class.repo

git add *

git commit -m "Add *"

git remote add origin https://github.com/Doom4535/Computer.class.repo

git push

