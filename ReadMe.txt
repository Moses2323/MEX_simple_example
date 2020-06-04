This is a simple example of how to build MEX function using Visual Studio project
without MATLAB "mex" command.

.mexw64 file is the same .dll file, so we need to build a usual dynamic library (.dll)
using VS project tools.

IMPORTANT!!!!!!!!!!!!!!!!!!!!!!!!!!!!

The things that should be changed in this project in order to build it:
1. right click on the project -> Properties -> VC++ Directories:
	change the beginning of "Include Directories" text to "<your path to MATLAB>\extern\include;"
	change the beginning of "Library Directories" text to "<your path to MATLAB>\extern\lib\win64\microsoft;"
	
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
That's should be enough for build the MEX function. 
After building, .mexw64 will be copied automatically 
to the Solution folder near .m file, so you can use MATLAB 
in order to check the work of the MEX function.
