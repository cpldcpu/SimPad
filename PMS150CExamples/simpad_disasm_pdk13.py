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
        if (dat&0x1c00==0x1800):
            print("goto\t${:04X}".format(dat&0x3ff))
        elif (dat&0x1c00==0x1c00):
            print("call\t${:04X}".format(dat&0x3ff))
        # elif (dat&0x3fc0==0x00c0):
        #     print("xorio \t${:02X},A".format(dat&0x3f))
        elif (dat&0x1fe0==0x0080):
            print("movio \t${:02X},A".format(dat&0x1f))
        elif (dat&0x1fe0==0x00a0):
            print("movio \tA,${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0700):
            print("and\tA,${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0740):
            print("or\t$A,{:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0780):
            print("xor\t$A,{:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x07c0):
            print("mov \tA,${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0580):
            print("xor \t${:02X},A".format(dat&0x3f))
        elif (dat&0x1fc0==0x05c0):
            print("mov \t${:02X},A".format(dat&0x3f))
        # elif (dat&0x3f80==0x1000):
        #     print("addc\t${:02X}".format(dat&0x7f))
        # elif (dat&0x3f80==0x1080):
        #     print("subc\t${:02X}".format(dat&0x7f))
        elif (dat&0x1fc0==0x0880):
            print("izsn\t${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x08c0):
            print("dzsn\t${:02X}".format(dat&0x3f))
        # elif (dat&0x3f80==0x1200):
        #     print("inc \t${:02X}".format(dat&0x7f))
        # elif (dat&0x3f80==0x1280):
        #     print("dec \t${:02X}".format(dat&0x7f))
        elif (dat&0x1fc0==0x0A80):
            print("sr \t${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0AC0):
            print("sl \t${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0B00):
            print("src \t${:02X}".format(dat&0x3f))
        elif (dat&0x1fc0==0x0B40):
            print("slc \t${:02X}".format(dat&0x3f))
        elif (dat&0x1f00==0x0c00):
            print("t0snio \t${:02X},#{:01X}".format(dat&0x1f,(dat>>5)&7))
        elif (dat&0x1f00==0x0d00):
            print("t1snio \t${:02X},#{:01X}".format(dat&0x1f,(dat>>5)&7))
        elif (dat&0x1f00==0x0e00):
            print("set0io \t${:02X},#{:01X}".format(dat&0x1f,(dat>>5)&7))
        elif (dat&0x1f00==0x0f00):
            print("set1io \t${:02X},#{:01X}".format(dat&0x1f,(dat>>5)&7))
        elif (dat&0x1f01==0x0200):
            print("t0sn\t${:02X},#{:01X}".format((dat&0x1e)>>1,(dat>>6)&7))
        elif (dat&0x1f01==0x0201):
            print("t1sn\t${:02X},#{:01X}".format((dat&0x1e)>>1,(dat>>6)&7))
        elif (dat&0x1f00==0x1000):
            print("add\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1100):
            print("sub\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1200):
            print("ceqsn\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1300):
            print("cneqsn\tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1400):
            print("and \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1500):
            print("or \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1600):
            print("xor \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x1f00==0x1700):
            print("mov \tA,#${:02X}".format(dat&0xff))
        elif (dat&0x3fff==0x003a):
            print("ret")
        elif (dat&0x1fff==0x0000):
            print("nop")
        else:
            print("????")

