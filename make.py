# -*- coding: utf-8 -*-

import os
from typing import List
import subprocess

SRC = "main.cpp ./func/cpu.cpp ./func/calcPI.cpp ./func/calcE.cpp ./func/calcI.cpp ./func/calcSeries.cpp ./func/mem.cpp"
FLAGS = "-Wall -fopenmp"
I = "-I./include/"
EXECUTABLE = "easybenchk"

def execute(command : str) -> tuple:
    #process = subprocess.Popen(command)
    #errcode = process.returncode
    #return errcode
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out = process.stdout.read().decode("utf-8")
    err = process.stderr.read().decode("utf-8") 
    errcode = process.returncode
    return (out, err, errcode)

def find_wc(wc : str) -> List[str]:
    '''
    Найти все файлы, которые оканчиваются на wc.
    Например, wc=".cpp" вернёт все файлы с разрешением ".cpp" (также во всех вложенных каталогах)
    '''
    res = [os.path.join(dp, f) for dp, dn, filenames in os.walk(".") for f in filenames if os.path.splitext(f)[1] == wc]
    return res

if __name__ == "__main__":
    COMMAND = f"g++ {I} {FLAGS} {SRC} -o {EXECUTABLE}"
    print(f"> {COMMAND}")

    res = execute(COMMAND)

    print(res[0])
    print(res[1])