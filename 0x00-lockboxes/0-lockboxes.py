#!/usr/bin/python3


def canUnlockAll(boxes):

    key = 0
    KeyC = [0]
    for llave in KeyC:
        for key in boxes[llave]:
            # print("estos es boxes key",boxes[llave])
            # print("estos es keys",key)
            if key in KeyC:
                # llavero.append(key)
                # print(KeyC)
                # continue
            else:
                KeyC.append(key)
                # key = keys
                # a = keys
                # break
    if len(KeyC) == len(boxes):
        return(True)
    else:
        return(False)
