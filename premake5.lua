workspace "SOLO"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SOLO"
	location "SOLO"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SOLO/vendor/spdlog/include",
		"SOLO/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SOLO_PLATFORM_WINDOWS",
			"SOLO_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "SOLO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SOLO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SOLO_DIST"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .."/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SOLO/vendor/spdlog/include",
		"SOLO/src"
	}

	links
	{
		"SOLO"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SOLO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SOLO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "SOLO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "SOLO_DIST"
		optimize "On"
