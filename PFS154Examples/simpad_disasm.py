# Simple disassembler for pdk14 intelhex files
# Not complete yet, instructions are added as needed
# cpldcpu Jan 2019

from intelhex import IntelHex16bit

# install missing libraries:
# 	pip/pip3 install intelhex

ih=IntelHex16bit()
ih.fromfile('main.ihx',format='hex')

for cursegment in ih.segments():
    start=cursegment[0]>>1       # convert address index from byte to word
    stop =cursegment[1]>>1 

    for currentaddress in range(start,stop):
        dat=ih[currentaddress]
        print("{:04X}:\t{:04X}\t".format(currentaddress,dat),end='')
        if (dat&0x3800==0x3000):
            print("goto\t${:04X}".format(dat&0x7ff))
        elif (dat&0x3800==0x3800):
            print("call\t${:04X}".format(dat&0x7ff))
        elif (dat&0x3fc0==0x00c0):
            print("xorio \t${:02X},A".format(dat&0x3f))
        elif (dat&0x3fc0==0x0180):
            print("movio \t${:02X},A".format(dat&0x3f))
        elif (dat&0x3fc0==0x01c0):
            print("movio \tA,${:02X}".format(dat&0x3f))
        elif (dat&0x3f80==0x0e00):
            print("and\tA,${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x0e80):
            print("or\t$A,{:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x0f00):
            print("xor\t$A,{:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x0f80):
            print("mov \tA,${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x0B00):
            print("xor \t${:02X},A".format(dat&0x7f))
        elif (dat&0x3f80==0x0B80):
            print("mov \t${:02X},A".format(dat&0x7f))
        elif (dat&0x3f80==0x1000):
            print("addc\t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1080):
            print("subc\t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1100):
            print("izsn\t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1180):
            print("dzsn\t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1200):
            print("inc \t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1280):
            print("dec \t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1500):
            print("sr \t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1580):
            print("sl \t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1600):
            print("src \t${:02X}".format(dat&0x7f))
        elif (dat&0x3f80==0x1680):
            print("slc \t${:02X}".format(dat&0x7f))
        elif (dat&0x3e00==0x1800):
            print("t0snio \t${:02X},#{:01X}".format(dat&0x3f,(dat>>6)&7))
        elif (dat&0x3e00==0x1a00):
            print("t1snio \t${:02X},#{:01X}".format(dat&0x3f,(dat>>6)&7))
        elif (dat&0x3e00==0x1c00):
            print("set0io \t${:02X},#{:01X}".format(dat&0x3f,(dat>>6)&7))
        elif (dat&0x3e00==0x1e00):
            print("set1io \t${:02X},#{:01X}".format(dat&0x3f,(dat>>6)&7))
        elif (dat&0x3e00==0x2000):
            print("t0sn\t${:02X},#{:01X}".format(dat&0x3f,(dat>>6)&7))
        elif (dat&0x3e00==0x2200):
            print("t1sn\t${:02X},#{:01X}".format(dat&0x3f,(dat>>6)&7))
        elif (dat&0x3f00==0x2800):
            print("add\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2900):
            print("sub\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2a00):
            print("ceqsn\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2b00):
            print("cneqsn\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2c00):
            print("and \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2d00):
            print("or \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2e00):
            print("xor \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3f00==0x2f00):
            print("mov \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3fff==0x007a):
            print("ret")
        elif (dat&0x3fff==0x0000):
            print("nop")
        else:
            print("????")

