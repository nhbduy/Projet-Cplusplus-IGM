#!/bin/bash
./server_multithreads &
./client A &
./client B &
./client C &
./client D &
