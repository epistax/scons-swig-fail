# scons-swig-fail
This is a demonstrator of a bug I found. This demonstrates that after two modifications and three builds, SCons will incorrectly believe that a file produced by swig is up to date. This issue was originally produced against swig 3.0.8 on windows. Later versions of swig seem to have addressed the original issue, and so now this demonstrator's purpose is to show the SCons side of the issue.

Requirements: You need a C++ compiler. I used MinGW. See the SConstruct for setting yours up.

Process:

1. Build the swig-crash-emulator. Run `scons swig-crash-emulator` to create an executable that emulates swig-3.0.8's behavior.
2. Run `scons run-swig`. This should pass. The swig-crash-emulator will run, and decide to not crash. It will produce a valid .cc output file which will then be compiled.
3. Modify class_header.h: Change the word "public" to "private".
4. Run `scons run-swig`. This should crash with a failed assertion. SCons will recognize that it crashed and will error out. Emulating the 3.0.8 bug, the swig-crash-emulator will write out an incomplete .cc output file.
5. Undo the change to class_header.h: Change the word "private" to "public".
6. Run `scons run-swig` one last time. You should see a C++ compilation error. This is because SCons recognizes the .cc output file as valid and does not re-run the swig-crash-emulator.

