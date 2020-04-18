#!/usr/bin/python3


def canUnlockAll(boxes):

    key = 0
    KeyC = [0]
    if len(boxes) == 0:
        return(True)
    for key in KeyC:
        for key in range(len(boxes[key])):
            # print("estos es boxes key",boxes[llave])
            # print("estos es keys",key)
            if key in KeyC:
                # llavero.append(key)
                # print(KeyC)
                continue
            else:
                KeyC.append(key)
                # key = keys
                # a = keys
                # break
    if len(KeyC) == len(boxes):
        return(True)
    else:
        return(False)
