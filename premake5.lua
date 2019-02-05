workspace "Satellite"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Satellite/vendor/glfw"
project "Satellite"
	location "Satellite"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "satpch.h"
	pchsource "Satellite/src/satpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glfw/include"
	}
	links{
		"GLFW",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"SAT_PLATFORM_WINDOWS",
			"SAT_BUILD_DLL"
		}
		postbuildcommands{			
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/") 			 
		}
	
	filter "configurations:Debug"
		defines "SAT_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SAT_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "SAT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"Satellite/src"
	}

	links{
		"Satellite"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"SAT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SAT_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "SAT_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "SAT_DIST"
		optimize "On"