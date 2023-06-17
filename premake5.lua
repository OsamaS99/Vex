workspace "Vex"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Vex/vendor/GLFW/include"
IncludeDir["GLAD"] = "Vex/vendor/GLAD/include"
IncludeDir["ImGui"] = "Vex/vendor/imgui"
IncludeDir["GLM"] = "Vex/vendor/GLM"


include "Vex/vendor/GLFW"
include "Vex/vendor/GLAD"
include "Vex/vendor/imgui"

project "Vex"
	location "Vex"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vxpch.h"
	pchsource "Vex/src/vxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/GLM/glm/**.hpp",
		"%{prj.name}/vendor/GLM/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.GLM}"
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
		systemversion "latest"

		defines
		{
			"VX_PLATFORM_WINDOWS",
			"VX_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}


	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VX_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"Vex/src",
		"Vex/vendor",
		"%{IncludeDir.GLM}"
	}

	links
	{
		"Vex"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VX_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VX_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VX_DIST"
		runtime "Release"
		optimize "on"