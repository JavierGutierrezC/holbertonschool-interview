#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics"""
<<<<<<< HEAD

import sys
import fileinput

=======
import sys
import fileinput
import signal
>>>>>>> 7d3ea6a2a2ada5015c35cfa3dcc388652b3c2dee
increase = 1
status_code = [0, 0, 0, 0, 0, 0, 0, 0]
size = 0
status_L = ["200", "301", "400", "401", "403", "404", "405", "500"]


<<<<<<< HEAD
def signal_print(status_code, status_L):
=======
def signal_handler(signal, frame):
>>>>>>> 7d3ea6a2a2ada5015c35cfa3dcc388652b3c2dee
    """ Method to handle ctrl-c"""
    print("File size: {}".format(size))
    for i in range(len(status_code)):
        if status_code[i] > 0:
<<<<<<< HEAD
            print("{}: {}".format(status_L[i], status_code[i]))

try:
    for line in sys.stdin:
        each_argvs = line.split(" ")
        if len(each_argvs) == 9:
            status = each_argvs[-2]
            if status in status_L:
                i = status_L.index(status)
                status_code[i] = status_code[i] + 1
                size = size + int(each_argvs[-1][:-1])
                if increase % 10 == 0:
                    signal_print(status_code, status_L)
        increase = increase + 1
except KeyboardInterrupt:
    signal_print(status_code, status_L)
    raise
signal_print(status_code, status_L)
=======
            print("{}: {}".format(status_code[i], status_code[i]))
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

for line in fileinput.input():
    each_argvs = line.split(" ")
    if len(each_argvs) == 9:
        status = each_argvs[-2]
        if status in status_L:
            i = status_L.index(status)
            status_code[i] = status_code[i] + 1
            size = size + int(each_argvs[-1][:-1])
            if increase % 10 == 0:
                print("File size: {}".format(size))
                for i in range(len(status_code)):
                    if status_code[i] > 0:
                        print("{}: {}".format(status_L[i], status_code[i]))
    increase = increase + 1
>>>>>>> 7d3ea6a2a2ada5015c35cfa3dcc388652b3c2dee
