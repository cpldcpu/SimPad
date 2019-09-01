# include generator for PDK OSS toolchain
# cpldcpu Sep 1, 2019

# import pandas as pd
# import numpy as np 
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
    ioend=ramend=flashend=ihrccal=0    
    version="unknown"
    sfr16=""
    try:
        version=datadict['version'][idx]
        ioend=int(datadict['ioend'][idx],0)
        ramend=int(datadict['ramend'][idx],0)
        flashend=int(datadict['flashend'][idx],0)
        ihrccal=int(datadict['ihrccal'][idx],0)
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

        outfile.write("\n")
        if ihrccal>0: 
            outfile.write("#define __PDK_IHRCCAL *((const unsigned char*)({0}))\n".format(ihrccal))
        outfile.write("\n")
        if sfr16: 
            outfile.write("__sfr16\t{0};\n".format(sfr16))

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

