#!/bin/python
import os
import sys

source_file = open(sys.argv[1], "r")
source = source_file.read()
source_file.close()

size = os.path.getsize(sys.argv[1])
splitted_name = sys.argv[1].split(".")
reps = int(sys.argv[2])
limit = int(sys.argv[3])
result = open(f"{splitted_name[0]}repeated{reps}times.{splitted_name[1]}", "w")
if(size * reps < limit):
    for i in range(0,reps):
        result.write(source)
result.close()
