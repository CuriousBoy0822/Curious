#!/bin/env python
#coding=latin-1 

import traceback, Ice
import sys
import time
Ice.loadSlice('--all -I/usr/share/Ice-3.4.2/slice ../Slice/CuriousMasterInterface.ice')

import Curious

try:
    ic = Ice.initialize(sys.argv)
    base = ic.stringToProxy('MasterSrv:tcp -h localhost -p 10000')
    prx = Curious.MasterInterfacePrx.checkedCast(base)
    if not prx:
        print 'Can\'t get receiver.'
        sys.exit(2)

    ret = prx.register('localhost1')
    print ret

except:
    traceback.print_exc()
    sys.exit(1)
