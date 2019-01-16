import serial
import time
from intelhex import IntelHex16bit

# Very hacky tool to convert ihx from SDCC-PDK14 to a C include
# Corrects adresses of GOTO instruction.

# install missing libraries:
# 	pip install pyserial
# 	pip install intelhex

ih=IntelHex16bit()
ih.fromfile('main.ihx',format='hex')
# ih.dump()

for cursegment in ih.segments():
    start=cursegment[0]/2       # convert address index from byte to word
    stop =cursegment[1]/2 

    for currentaddress in range(start,stop):
        dat=ih[currentaddress]
        if (dat&0x3800==0x3000):
            print("{:04X}\t\tgoto\t${:04X}".format(currentaddress,dat&0x7ff))
        elif (dat&0x3800==0x3800):
            print("{:04X}\t\tcall\t${:04X}".format(currentaddress,dat&0x7ff))
        elif (dat&0x3f00==0x2f00):
            print("{:04X}\t\tmov \tA,#${:02X}".format(currentaddress,dat&0xff))
        elif (dat&0x3f80==0x0f80):
            print("{:04X}\t\tmov \tA,${:02X}".format(currentaddress,dat&0x7f))
        elif (dat&0x3f80==0x0B80):
            print("{:04X}\t\tmov \t${:02X},A".format(currentaddress,dat&0x7f))
        elif (dat&0x3fc0==0x0180):
            print("{:04X}\t\tmov \t${:02X}_io,A".format(currentaddress,dat&0x7f))
        elif (dat&0x3fc0==0x01c0):
            print("{:04X}\t\tmov \tA,${:02X}_io".format(currentaddress,dat&0x7f))
        else:
            print("{:04X}\t\tdc.w\t#${:04X}".format(currentaddress,dat&0x3fff))

