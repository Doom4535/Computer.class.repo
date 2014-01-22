#!/bin/bash

# Download the code and extract it.
mkdir Temp.Cache
curl http://www.cs.southern.edu/halterman/repository/ClassCode/124/CPTR_124_Class_Code.zip -o Temp.Cache/CPTR_124_Class_Code.zip
unzip -uo Temp.Cache/*.zip
rm -vr Temp.Cache

# Upload changes to the repository
git add .
git commit -m
git push

