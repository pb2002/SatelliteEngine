git submodule update --init Satellite/vendor/spdlog
git submodule update --init Sandbox/vendor/spdlog
git submodule update --init Satellite/vendor/glfw

call premake.bat
call Satellite.sln
