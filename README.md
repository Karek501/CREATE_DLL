"# CREATE_DLL TUTORIALS"

APLLICATION OF THIS:
https://batuhankoc.medium.com/use-cmake-to-create-and-use-dynamic-libraries-5f6498417b3c


DIRECT APPROACH:

With the direct approach, we not only need .dll file as in the CSTYLE APPROACH, but also one .dll.a file (GNU compiler do this instead of .lib)

i tried to keep the most "as pressionnal" structured project organisation,
using usual /libs, /includes, /src structuration.
The .dll 

- in the main CMakeLists.txt, it was necessary to both target_include_directories AND target_link_directories, otherwise ERROR
- it was found impossible to put the .dll file in another location than the directory of the .exe file.
- in the main CMakeLists.txt, the command "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_PATH})" permits to force the implementation of .exe file in the /bin directory.

