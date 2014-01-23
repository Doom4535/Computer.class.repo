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
# The commit message that was here was static
# the commit message talks about that specific update
# so, a commit about adding 318 support isn't a commit message to script
# it is a commit message to use once, a better commit message in this case would be:
# "Added number_to_text program"
# another one could be
# "Auto update from $(hostname) by $(whoami)" (which becomes) "Auto update from goAwayS by acovrig".
# and specifying -m without anything pulls up the default editor for the user to specify a message.
git commit -m
git push

