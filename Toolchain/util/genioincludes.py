# include generator for PDK OSS toolchain
# cpldcpu Sep 1, 2019

# import pandas as pd
import numpy as np 
import csv
import datetime

with open('PDK_register_map.csv','r') as infile:
    csviterator = csv.reader(infile)
    headings=next(csviterator)[1:]

    datadict={}
    for row in csviterator:
        try:
            key=int(row[0],0)
        except ValueError:
            key=row[0].lower()
        datadict[key]=row[1:]

print("Generating include files...")
for idx, mcu in enumerate(headings):    
    ioend=ramend=flashend=ihrccal=bgtrcal=0    
    version="unknown"
    sfr16=""
    try:
        version=datadict['version'][idx]
        ioend=int(datadict['ioend'][idx],0)
        ramend=int(datadict['ramend'][idx],0)
        flashend=int(datadict['flashend'][idx],0)
        ihrccal=int(datadict['ihrccal'][idx],0)
        bgtrcal=int(datadict['bgtrcal'][idx],0)
        sfr16=datadict['sfr16'][idx]
    except KeyError:
        print("One of the keys: 'ioend/ramend/flashend/ihrccal' not found. Omitting defines.")
    except ValueError:
        pass

    with open("output/io_{0}.h".format(mcu.lower()),'w+') as outfile:
        outfile.write("// I/O include file for Padauk {0}\n".format(mcu))
        outfile.write("// Version: {0}\n".format(version))
        outfile.write("// Automatically generated on {0}\n\n".format(datetime.datetime.now()))
        outfile.write("#ifndef __PDK_IO_{0}_H\n".format(mcu))
        outfile.write("#define __PDK_IO_{0}_H\n\n".format(mcu))

        outfile.write("#include <pdk/io_common.h>\n\n")

        if ramend>0: 
            outfile.write("#define __PDK_RAMEND {0}\n".format(ramend))
        if ioend>0: 
            outfile.write("#define __PDK_IOEND {0}\n".format(ioend))
        if flashend>0: 
            outfile.write("#define __PDK_FLASHEND {0}\n".format(flashend))

        if (ihrccal>0 or bgtrcal>0):
            flashbits=int(np.log2(flashend))+4
            print(flashbits)
            rcall=7<<(flashbits-3)  # encode rcall for all machine types
            outfile.write("\n")
            outfile.write("#define PDK_USE_FACTORY_TRIMMING() {__asm__ (\"")
            if ihrccal>0: 
                outfile.write(".word (0x{0:04x})\\nmov _ihrcr,a\\n".format(ihrccal|rcall))
            if bgtrcal>0: 
                outfile.write(".word (0x{0:04x})\\nmov _bgtr,a\\n".format(bgtrcal|rcall))
            outfile.write("\");}\n\n")
        else:
            outfile.write("\n")
            outfile.write("#define PDK_USE_FACTORY_TRIMMING() {#error 'this device does not support factory trimming'}\n\n")

        if sfr16: 
            outfile.write("#define {1:8}\t{2} // __sfr16 __at(0x{0:02x}) {1}\n".format(0,sfr16.upper(),sfr16.lower()))
            outfile.write("__sfr16\t{0};\n".format(sfr16))

            outfile.write("\n")

        for reg in range(0,ioend+1):
            # if reg%8 == 0:
                # outfile.write("\n")
            try:
                val=datadict[reg][idx]
            except KeyError:
                val=''            
            if len(val)>0:
                outfile.write("#define {1:8}\t{2} // __sfr __at(0x{0:02x}) {1}\n".format(reg,val.upper(),val.lower()))

        for reg in range(0,ioend+1):
            if reg%8 == 0:
                outfile.write("\n")
            try:
                val=datadict[reg][idx]
            except KeyError:
                val=''            
            if len(val)>0:
                outfile.write("__sfr __at(0x{0:02x})\t{1};\n".format(reg,val.lower()))

        outfile.write("\n#endif\n")

