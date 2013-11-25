solution "Disandria"
	location "build"
	configurations { "Debug", "Release" }
	buildoptions "-std=c++11"
	
	configuration  "Debug"
		flags { "Symbols" }
		defines { "DEBUG" }

	configuration "Release"
		flags { "Optimize" }
		defines { "NDEBUG" }

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

	project "DisandriaLib"
		kind "SharedLib"
		language "C++"
		files { "src/lib/**.cpp", "src/lib/**.h" }
		links { "miniLOGlib", "pugitmx", "CEGUIBase-0", "CEGUIOpenGLRenderer-0", "sfml-graphics", "sfml-window", "sfml-audio", "sfml-system", "PocoUtil", "PocoFoundation", "thor", "box2d", "falcon_engine" }

	project "disandria-game"
		kind "ConsoleApp"
		language "C++"
		files { "src/main.cpp" }
		links { "miniLOGlib", "DisandriaLib", "pugitmx", "pugixml", "thor" }
