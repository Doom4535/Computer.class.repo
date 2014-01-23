#!/bin/bash

# Now includes both the 124 and 318 level programming classes.
# Download the code and extract it. 
mkdir Temp.Cache
curl http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip -o Temp.Cache/CPTR_124_Class_Code.zip
curl http://www.cs.southern.edu/halterman/repository/ClassCode/318/CPTR_318_Class_Code.zip -o Temp.Cache/CPTR_318_Class_Code.zip
unzip -uo Temp.Cache/CPTR_124_Class_Code.zip
unzip -uo Temp.Cache/CPTR_318_Class_Code.zip 
rm -vr Temp.Cache

# Upload changes to the repository
git add .
git commit -m '$(hostname) " by " $(whoami)'
git push
