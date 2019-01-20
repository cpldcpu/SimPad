from intelhex import IntelHex16bit

# Very hacky tool to convert ihx from SDCC-PDK14 to a C include


# install missing libraries:
# 	pip install pyserial
# 	pip install intelhex

ih=IntelHex16bit()
ih.fromfile('main.ihx',format='hex')
# ih.dump()

for cursegment in ih.segments():
    start=cursegment[0]>>1       # convert address index from byte to word
    stop =cursegment[1]>>1 

    for currentaddress in range(start,stop,2):
        dat16bitl=ih[currentaddress]
        dat16bith=ih[currentaddress+1]
        print("\tSP_WriteWords(0x{:04X},0x{:04X},0x{:04X});".format(dat16bitl,dat16bith,currentaddress))
