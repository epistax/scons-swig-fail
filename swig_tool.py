
import SCons

def generate(env, **kw):
    env.Tool('swig')
    env['SWIG'] = SCons.Script.File('swig-crash-emulator.exe')
    env['SWIGFLAGS'] = ['-Wextra', '-Werror', '-c++', '-w312']

def exists(env):
    return 1

