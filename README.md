"# CREATE_DLL TUTORIALS"

APLLICATION OF THIS:
https://batuhankoc.medium.com/use-cmake-to-create-and-use-dynamic-libraries-5f6498417b3c

(1) C-STYLE APPROACH: to develop


(2) DIRECT APPROACH:

With the direct approach, we not only need .dll file as in the CSTYLE APPROACH, but also one .dll.a file (GNU compiler do this instead of .lib)

i tried to keep the most "as pressionnal" structured project organisation,
using usual /libs, /includes, /src structuration.
The .dll is located in /libs

- in the main CMakeLists.txt, it was necessary to both target_include_directories AND target_link_directories, otherwise ERROR
- in the main CMakeLists.txt, the command "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH})" permits to force the implementation of .exe file in the /bin directory.
- Normally, it is advised to put the .dll right next to the .exe compiled application. In present case,
i wanted to see if it is possible to put the .dll in /libs, to not spread files everywhere and also centralize all data related to the libs (.dll.a, .lib and .h are required...): It works at condition to use
an executable (.bat in /bin which first sets a new PATH environment variable to the .dll) to tell the .exe where to grab the  .dll.

