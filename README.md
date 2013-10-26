# Welcome to Disandria!

Disandria is an RPG game, whose storyline I will soon develop, and, once finished, I will release on RMN (rpgmaker.net).  
This repository is simply the engine, also referred to as Disandria.  
To build Disandria, you will need to get (on your own):

*  [The SFML library](http://www.sfml-dev.org "SFML") Version 2.0 or later required. Do **NOT** get Version 1.6. It will **NOT** compile. The coding standards changed between the two versions, so that causes an incompatibility with SFML-1.6 and SFML-2.0+.  
*  [The Poco C++ library](http://www.pocoproject.org "Poco") 
*  [The CEGUI-mk2 library](http://www.cegui.org.uk "CEGUI-mk2") CEGUI-mk2 (Version 0.8 or later...)  
*  [The Thor library](http://www.bromeon.ch/libraries/thor/index.html "Thor") I'm not sure if Version 1.1 works with SFML-2.0 or SFML-2.1, but the best bet is to go with Thor 2.0.  
*  [The Falcon Programming Language](http://www.falconpl.org "FalconPL") An wonderful project I stumbled across. Completely in C++. Easily integrated as an embeddable scripting language. A quite extensive standard library. The default scripting language of Disandria.  

For those of you who want to use what I used, here are the version numbers:  
SFML: 2.1  
Poco: 1.4.6p1  
CEGUI: 0.8.2  
Thor: 2.0-dev  
FalconPL: 0.9.6.8 (Chimera)  

PugiXML is used in this project. The files for PugiXML are included in the folder src/pugixml.
I do not own nor do I hold any rights over PugiXML.  
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
  *-- EDIT --*  
  I have redone the mapping algorithm, so that it now CAN render tiles with different widths and heights.
* Maps *must* be orthagonal.
  I've never used an isometric map. I don't know if my renderer can handle isometric maps, but try at your own downfall...
* Maps *must* be in a folder with the *exact* filename of the map (without the .tmx).
  This is so the engine can find them, and as I add scripting, everything is all in the same folder, and everything won't be mixed with each other. 
* Also, the map file must have the extension .tmx. This is the default extension for Tiled **TMX** maps, so...

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

* The default scripting language will be Falcon. I will add more in the future...

## A bit of Information on the Projects inside this Project

### PugiTMX

PugiTMX is a TMX map parser, written in C++ (obviously), based on the PugiXML parser.  
I wrote it to see if I could.


**Thank you for your interest in Disandria!**

*~~ Bob Hostern*
