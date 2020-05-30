#!/usr/bin/python3
""" script that reads stdin line by line and computes metrics"""
import sys
import fileinput
import signal
increase = 1
status_code = [0, 0, 0, 0, 0, 0, 0, 0]
size = 0
status_L = ["200", "301", "400", "401", "403", "404", "405", "500"]


def signal_handler(signal, frame):
    """ Method to handle ctrl-c"""
    print("File size: {}".format(size))
    for i in range(len(status_code)):
        if status_code[i] > 0:
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
