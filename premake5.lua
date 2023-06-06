workspace "Vex"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Vex/vendor/GLFW/include"
IncludeDir["GLAD"] = "Vex/vendor/GLAD/include"
IncludeDir["ImGui"] = "Vex/vendor/imgui"


include "Vex/vendor/GLFW"
include "Vex/vendor/GLAD"
include "Vex/vendor/imgui"



project "Vex"
	location "Vex"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vxpch.h"
	pchsource "Vex/src/vxpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"GLAD",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"VX_PLATFORM_WINDOWS",
			"VX_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir ..  "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VX_Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "VX_DIST"
		runtime "Release"
		optimize "On"

startproject "Sandbox"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vex/vendor/spdlog/include",
		"Vex/src"
	}

	links
	{
		"Vex"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines 
		{
			"VX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VX_Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "VX_DIST"
		runtime "Release"
		optimize "On"
