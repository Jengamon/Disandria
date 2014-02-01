solution "Disandria"
	newoption {
		trigger = "falcon1",
		description = "Use Falcon 1.0 rather than 0.9.6.8."
	}
	
	includedirs { "src" }
	
	location "build"
	configurations { "Debug", "Release" }
	
	configuration { "linux", "gmake" }
		buildoptions "-std=c++11"
	
	configuration  "Debug"
		flags { "Symbols" }
		defines "DEBUG"

	configuration "Release"
		flags { "Optimize" }
		defines "NDEBUG"
		
	configuration "falcon1"
		defines "FALCON1"

	project "miniLOGlib"
		kind "SharedLib"
		language "C++"
		files { "src/helplib/**.cpp", "src/helplib/**.h" }
		links { "PocoUtil", "PocoFoundation" }
	
	project "pugixml"
		kind "SharedLib"
		language "C++"
		files { "src/pugixml/**.cpp", "src/pugixml/**.h" }
	
	project "pugitmx"
		kind "SharedLib"
		language "C++"
		files { "src/pugitmx/**.cpp", "src/pugitmx/**.h" }
		links { "pugixml", "miniLOGlib" }
	--[[	
	project "sneslib"
		kind "SharedLib"
		language "C++"
		files { "src/sneslib/**.cpp", "src/sneslib/**.h" }
		links { "sfml-graphics", "sfml-system" }
	]]--
	
	if not _OPTIONS["falcon1"] then
		project "DisandriaFalcon"
			kind "SharedLib"
			language "C++"
			files { "src/lib/script/falcon/falcon/**.cpp", "src/lib/script/falcon/falcon/**.cpp" }
			links { "falcon_engine", "sfml-graphics", "sfml-window", "sfml-audio", "sfml-system" }
	else
		project "DisandriaFalcon"
			kind "SharedLib"
			language "C++"
			files { "src/lib/script/falcon/falcon1/**.cpp", "src/lib/script/falcon/falcon1/**.cpp" }
			links { "falcon_engine", "sfml-graphics", "sfml-window", "sfml-audio", "sfml-system" }
	end
	
	project "DisandriaLib"
		kind "SharedLib"
		language "C++"
		files { "src/lib/**.cpp", "src/lib/**.h" }
		excludes { "src/lib/script/falcon/**.cpp", "src/lib/script/falcon/**.h" }
		links { "miniLOGlib", "pugitmx", "CEGUIBase-0", "CEGUIOpenGLRenderer-0", "sfml-graphics", "sfml-window", "sfml-audio", "sfml-system", "PocoUtil", "PocoFoundation", "thor", "box2d", "falcon_engine", "DisandriaFalcon" }

	project "disandria-game"
		kind "ConsoleApp"
		language "C++"
		files { "src/main.cpp" }
		links { "miniLOGlib", "DisandriaLib", "falcon_engine", "DisandriaFalcon", "PocoUtil", "pugitmx", "pugixml", "thor" }
