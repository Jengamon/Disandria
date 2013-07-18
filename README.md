# Welcome to Disandria!

Disandria is an RPG game, whose storyline I will soon develop, and, once finished, I will release on RMN (rpgmaker.net).  
This repository is simply the engine, also referred to as Disandria.  
To build Disandria, you will need:

*  [The SFML library](http://www.sfml-dev.org "SFML")
*  [The Poco C++ library](http://www.pocoproject.org "Poco")
*  [The CEGUI-mk2 library (v0.8+)](http://www.cegui.org.uk "CEGUI-mk2 (0.8+)")
*  [The Thor library (2.0)](http://www.bromeon.ch/libraries/thor/index.html "Thor 2.0")

PugiXML is used in this project. I do not own nor do I hold any rights over PugiXML.  
For more information on this project, look over here: [The PugiXML library][pxml].

[pxml]: http://www.pugixml.org "PugiXML"

There are some limitations to the engine:

### Map-related

* You can only use Tiled TMX maps in their *XML* format.  
  This is different from the default settings. In order to change this, you must
  open the Tiled Map Editor, then go to Edit->Preferences, then click the item box beside
  "Store tile layer data as:", then choose "XML".
* The engine currently does *not* support TMX terrains.  
  PugiTMX cannot currently parse TMX terrains, and I don't know what they do, so no terrains right now.
* The engine currently does *not* support TMX image layers.
  PugiTMX cannot currently parse TMX image layers, and I don't know what they do, so no image layers either.
* The engine can *only* use tilesets with the same tile width and tile height as the map they are used on.
  This is due to the algorithim it uses to calculate where to render the tiles.
* Maps *must* be orthagonal.
  I've never used an isometric map. I don't know if my renderer can handle isometric maps.
* Maps *must* be in a folder with the *exact* filename of the map.
  This is so the engine can find them, and so that when I add scripting, everything is all in the same folder.

### Sound-related

* The audio formats the engine supports are:

		- ogg 
		- wav
		- flac
		- aiff
		- au
		- raw
		- paf
		- svx
		- nist
		- voc
		- ircam
		- w64
		- mat4
		- mat5 pvf
		- htk
		- sds
		- avr
		- sd2
		- caf
		- wve
		- mpc2k
		- rf64

### Scripting-related

* The scripting language will be JavaScript, through Mozilla's SpiderMonkey 24.  
  ...which is expected to be released November 2013. So you see why there is no scripting engine right now.

### Image-related

* Images must be RGBA-8. No CMYK stuff.

## A bit of Information on the Projects inside the Project

### PugiTMX

PugiTMX is a TMX map parser, written in C++ (obviously), based on the PugiXML parser.  
I wrote it to see if I could.

### RPGeom

This is a geometry/collision library specifically tailored toward RPGs.  
The reasoning behind this is... nothing. A simple test to see if I could.


**Thank you for your interest in Disandria!**

*~~ Bob Hostern*
