#!/bin/bash

if [[ $1 = "rpi" ]]; then
  make -f Makefile.rpi
else
  if [[ $1 = "clean" ]]; then
    make clean
  else
    make
  fi
fi
