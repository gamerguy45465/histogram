from ctypes import *

class Vector(object):
    



def main():
    lib = cdll.LoadLibrary("./libcalc.so")
    data = lib.getData
    print(data)
    print(lib.getHigh(data))

    






if(__name__ == "__main__"):
    main()