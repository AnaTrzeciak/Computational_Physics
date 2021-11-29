#! /bin/bash
#
cp rk4.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include rk4.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rk4.o ~/libcpp/rk4.o
#
echo "Normal end of execution."
