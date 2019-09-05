
import SCons

def generate(env, **kw):
    env.Tool('swig')
    env['SWIG'] = SCons.Script.File('../tools/swigwin-3.0.8/swig.exe')
    env['SWIGFLAGS'] = ['-Wextra', '-Werror', '-c++', '-w312']

def exists(env):
    return 1

