# scons-swig-fail
This is a demonstrator of a bug I found. This demonstrates that two modifications and three builds, SCons will incorrectly believe that a file produced by swig is up to date.

Requirements: Modify swig_tool.py to point to your swig. This issue was produced against swig 3.0.2 on windows.

Process:

1. Run SCons once. This should produce a "lua_interop_wrap.cc" file that several KB in size. The invoke of GCC doesn't matter; it is just there to force SWIG to run.
2. Modify class_header.h: Change "public" to "private".
3. Run SCons once more. Swig should fail hard, with an assertion. The "lua_interop_wrap.cc" file should now be small, under 1 KB. It's just a comment block.
4. Undo the modification to class_header.h: Change the "private" to "public".
5. Run SCons one last time. Swig is not run. Instead, g++ will be invoked on the previously created "lua_interop_wrap.cc" file.
