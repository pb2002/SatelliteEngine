workspace "Satellite"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Satellite/vendor/glfw"
include "Satellite/vendor/glad"
include "Satellite/vendor/imgui"

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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"Satellite/vendor/glfw/include",
		"Satellite/vendor/glad/include",
		"Satellite/vendor/imgui",
		"Satellite/vendor/glm"
	}
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"SAT_PLATFORM_WINDOWS",
			"SAT_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		postbuildcommands{			
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/") 			 
		}
	
	filter "configurations:Debug"
		defines "SAT_DEBUG"
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines "SAT_RELEASE"
		runtime "Release"
		optimize "On"
	filter "configurations:Dist"
		defines "SAT_DIST"
		runtime "Release"
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
		"Satellite/src",
		"Satellite/vendor/glm"
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
		runtime "Debug"
		symbols "On"
	filter "configurations:Release"
		defines "SAT_RELEASE"
		runtime "Release"
		optimize "On"
	filter "configurations:Dist"
		defines "SAT_DIST"
		runtime "Release"
		optimize "On"