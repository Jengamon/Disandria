# Welcome to Disandria!

Disandria is an RPG game, whose storyline I will soon develop, and, once finished, I will release on RMN (rpgmaker.net).  
This repository is simply the engine, also referred to as Disandria.  
To build Disandria, you will need:

*  [The SFML library](http://www.sfml-dev.org "SFML")
*  [The Poco C++ library](http://www.pocoproject.org "Poco")
*  [The CEGUI-mk2 library (v0.8+)](http://www.cegui.org.uk "CEGUI-mk2 (0.8+)")
*  (TBI) [The Thor library (2.0)](http://www.bromeon.ch/libraries/thor/index.html "Thor 2.0")
*  (TBI) [The SDL library](http://www.libsdl.org "SDL")

PugiXML is used in this project. I do not own nor do I hold any rights over PugiXML.  
For more information on this project, look over here: [PugiXML library][pxml].

[pxml]: http://www.pugixml.org "PugiXML"

There are a few limitations to the engine:

### Map-related

* You can only use Tiled TMX maps in their *XML* format.
* The engine does *not* support TMX terrains.
* The engine can *only* use 32 x 32 tiles. No more, no less.  
  This is due to the algorithim it uses to calculate where to render the tiles.
* Maps *must* be orthagonal.
* Maps *must* be in a folder with the *exact* filename of the map.

Thank you for your interest in Disandria!

**Bob Hostern**
