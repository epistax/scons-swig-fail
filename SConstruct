
import os

# You may need to tweak the compiler configuration below. Any native C++11 compiler should do.

# Path to your compiler!
compiler_bin_path = 'path-to-your-compiler/bin'

env = Environment(tools = ['swig_tool', 'mingw'], 
                  toolpath = ['.'],
                  ENV = {'COMSPEC' : os.environ['COMSPEC'],
                         'PATH' : [compiler_bin_path],
                         'TEMP' : os.environ['TEMP']})
                         
interop_build = env.Object('lua_interop.i')

swig_crash_emulator = env.Program('swig-crash-emulator', 'swig-crash-emulator.cpp')

env.Alias('swig-crash-emulator', swig_crash_emulator)
env.Alias('run-swig', interop_build)

