workspace "FireEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FireEngine"
	location "FireEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FIRE_ENGINE_WINDOWS",
			"FIRE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "FIRE_ENGINE_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "FIRE_ENGINE_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "FIRE_ENGINE_DIST"
			optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"FireEngine/vendor/spdlog/include",
		"FireEngine/src"
	}

	links
	{
		"FireEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FIRE_ENGINE_WINDOWS"
		}

		filter "configurations:Debug"
			defines "FIRE_ENGINE_DEBUG"
			symbols "On"
		
		filter "configurations:Release"
			defines "FIRE_ENGINE_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "FIRE_ENGINE_DIST"
			optimize "On"