#!/bin/bash
# Author: Pavan Kumar Paluri
# Executable for main
g++ -std=c++11 -c integrator.cpp
# shellcheck disable=SC1072
if [ $? -eq 0 ]; then
  echo "Successful compilation"
else
  echo "Compilation Failure"
  fi
# Executable for FilePreProcessor
g++ -std=c++11 -c FilePreProcessor.cpp
# shellcheck disable=SC1072
if [ $? -eq 0 ]; then
  echo "Successful compilation"
else
  echo "Compilation Failure"
  fi
# Executable for DayTrade
g++ -std=c++11 -c DayTrade.cpp
# shellcheck disable=SC1072
if [ $? -eq 0 ]; then
  echo "Successful compilation"
else
  echo "Compilation Failure"
  fi
# Cumulative
g++ integrator.o FilePreProcessor.o DayTrade.o -o final_executable
# shellcheck disable=SC1072
if [ $? -eq 0 ]; then
  echo "Successful compilation"
else
  echo "Compilation Failure"
  fi
# Run Final Executable
./final_executable

# Final checks
# shellcheck disable=SC1072
if [ $? -eq 0 ]; then
  echo "Successful compilation"
else
  echo "Compilation Failure"
  fi