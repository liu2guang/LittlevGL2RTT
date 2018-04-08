import os
from building import * 

# get current dir path
cwd = GetCurrentDir()

# init src and inc vars
src = []
inc = []

# add LittlevGL2RTT common include
inc = inc + [cwd]

# add LittlevGL2RTT basic code
src = src + ['./littlevgl2rtt.c']

# add group to IDE project
objs  = DefineGroup('LittlevGL', src, depend = ['PKG_USING_LITTLEVGL'], CPPPATH = inc)
list = os.listdir(cwd)

if GetDepend('PKG_USING_LITTLEVGL'):
    for d in list:
        path = os.path.join(cwd, d)
        if os.path.isfile(os.path.join(path, 'SConscript')):
            objs = objs + SConscript(os.path.join(d, 'SConscript'))

Return('objs')
