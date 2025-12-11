workspace "Space_Invaders"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Space_Invaders"

project "Space_Invaders"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/%{cfg.buildcfg}")
    objdir ("bin/intermediates/%{cfg.buildcfg}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "vendor/SDL2/include"
    }

    libdirs {
        "vendor/SDL2/lib/x64"
    }

    links {
        "SDL2",
        "SDL2main"
    }

    filter "configurations:Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "On"

    filter {}

    postbuildcommands {
        "{COPY} vendor/SDL2/lib/x64/SDL2.dll"
    }

