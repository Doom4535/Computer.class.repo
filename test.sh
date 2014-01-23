#!/bin/bash

# Now includes both the 124 and 318 level programming classes.
# Download the code and extract it. 
mkdir Temp.Cache
curl http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip -o /Users/Aaron/Temp.Cache/CPTR_124_Class_Code.zip
curl http://www.cs.southern.edu/halterman/repository/ClassCode/318/CPTR_318_Class_Code.zip -o /Users/Aaron/Temp.Cache/CPTR_318_Class_Code.zip
unzip -uo /Users/Aaron/Temp.Cache/CPTR_124_Class_Code.zip
unzip -uo /Users/Aaron/Temp.Cache/CPTR_318_Class_Code.zip 
cd /Users/Aaron
rm Temp.Cache/*.zip
rsync -vrSP /Users/Aaron/Temp.Cache/* /Users/Aaron/Git.Repositories/Computer.class.repo
rm -vr Temp.Cache

# Upload changes to the repository
cd /Users/Aaron/Git.Repositories/Computer.class.repo
git add .
git commit -m "Added level 318 Data Structures and Algorithms to the repository"
git push

