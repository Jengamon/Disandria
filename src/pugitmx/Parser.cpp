#include "Parser.h"
#include "../helplib/Log.h"

using namespace pugitmx;

Map* Parser::parseMap(std::string filename)
{
    pugi::xml_document mapfile;
    pugi::xml_parse_result result = mapfile.load_file(filename.c_str());
    Map* max;
    if(result) {
        if(!mapfile.child("map").attribute("background")) {
            max = new Map(mapfile.child("map").attribute("version").as_double(),
                          mapfile.child("map").attribute("orientation").value(),
                          mapfile.child("map").attribute("width").as_int(),
                          mapfile.child("map").attribute("height").as_int(),
                          mapfile.child("map").attribute("tilewidth").as_int(),
                          mapfile.child("map").attribute("tileheight").as_int());
        } else {
            max = new Map(mapfile.child("map").attribute("version").as_double(),
                          mapfile.child("map").attribute("orientation").value(),
                          mapfile.child("map").attribute("width").as_int(),
                          mapfile.child("map").attribute("height").as_int(),
                          mapfile.child("map").attribute("tilewidth").as_int(),
                          mapfile.child("map").attribute("tileheight").as_int(),
                          mapfile.child("map").attribute("background").value());
        }
        for(pugi::xml_node properties = mapfile.child("map").child("properties").child("property"); properties; properties = properties.next_sibling("property")) {
            max->registerProperty(properties.attribute("name").value(), properties.attribute("value").value());
        }
        for(pugi::xml_node tilesets = mapfile.child("map").child("tileset"); tilesets; tilesets = tilesets.next_sibling("tileset")) {
            Tileset* tlst = parseTileset(tilesets);
            max->registerTileset(*tlst);
            delete tlst;
        }
        for(pugi::xml_node layers = mapfile.child("map").child("layer"); layers; layers = layers.next_sibling("layer")) {
            TileLayer* tlly = parseTileLayer(layers);
            max->registerTileLayer(*tlly);
            delete tlly;
        }
        for(pugi::xml_node objectgroups = mapfile.child("map").child("objectgroup"); objectgroups; objectgroups = objectgroups.next_sibling("objectgroup")) {
            ObjectGroup* objgrp = parseObjectGroup(objectgroups);
            max->registerObjectGroup(*objgrp);
            delete objgrp;
        }
        return new Map(*max);
    } else {
        Log::log(result.description() + String<const char*>::toString("\nError at: ") + (filename.c_str() + result.offset));
    }
}

Tileset* Parser::parseTileset(pugi::xml_node tlxml)
{
    Image* im = parseImage(tlxml.child("image"));
    Tileset* tileset = new Tileset(tlxml.attribute("firstgid").as_int(),
                                   tlxml.attribute("name").value(),
                                   tlxml.attribute("tilewidth").as_int(),
                                   tlxml.attribute("tileheight").as_int(),
                                   *im);
    for(pugi::xml_node tile = tlxml.child("tile"); tile; tile = tile.next_sibling("tile")) {
        TilePropertyKey tkey;
        tkey.id = tile.attribute("id").as_int();
        for(pugi::xml_node props = tile.child("properties").child("property"); props; props = props.next_sibling("property")) {
            tkey.propertyname = props.attribute("name").value();
            tileset->registerProperty(tkey, props.attribute("value").value());
        }
    }
    delete im;
    return tileset;
}

Image* Parser::parseImage(pugi::xml_node imxml)
{
    Image* image = new Image(imxml.attribute("source").value(), imxml.attribute("width").as_int(), imxml.attribute("height").as_int(), imxml.attribute("trans").value());
    return new Image(*image);
}

TileLayer* Parser::parseTileLayer(pugi::xml_node tlxml)
{
    TileLayer* tilelayer = new TileLayer(tlxml.attribute("name").value(),
                                         tlxml.attribute("width").as_int(),
                                         tlxml.attribute("height").as_int());
    for(pugi::xml_node tiles = tlxml.child("data").child("tile"); tiles; tiles = tiles.next_sibling("tile")) {
        Tile* tl = parseTile(tiles);
        tilelayer->addTile(*tl);
        delete tl;
    }
    for(pugi::xml_node props = tlxml.child("properties").child("property"); props; props = props.next_sibling("property")) {
        tilelayer->registerProperty(props.attribute("name").value(), props.attribute("value").value());
    }
    return tilelayer;
}

Tile* Parser::parseTile(pugi::xml_node tlxml)
{
    Tile* tile = new Tile(tlxml.attribute("gid").as_int());
    return tile;
}

ObjectGroup* Parser::parseObjectGroup(pugi::xml_node objgrpxml)
{
    ObjectGroup* objectgroup = new ObjectGroup(objgrpxml.attribute("name").value(),
            objgrpxml.attribute("width").as_int(),
            objgrpxml.attribute("height").as_int());
    for(pugi::xml_node object = objgrpxml.child("object"); object; object = object.next_sibling("object")) {
        Object* obj = parseObject(object);
        objectgroup->registerObject(*obj);
        delete obj;
    }
    for(pugi::xml_node props = objgrpxml.child("properties").child("property"); props; props = props.next_sibling("property")) {
        objectgroup->registerProperty(props.attribute("name").value(), props.attribute("value").value());
    }
    return objectgroup;
}

Object* Parser::parseObject(pugi::xml_node objxml)
{
    bool setellipse;
    if(objxml.child("ellipse"))
        setellipse = true;
    else
        setellipse = false;

    Polygon* poly = parsePolygon(objxml.child("polygon"));

    Object* object = new Object(objxml.attribute("name").value(),
                                objxml.attribute("type").value(),
                                objxml.attribute("gid").as_int(),
                                objxml.attribute("x").as_int(),
                                objxml.attribute("y").as_int(),
                                objxml.attribute("width").as_int(),
                                objxml.attribute("height").as_int(),
                                setellipse,
                                *poly);
    delete poly;
    for(pugi::xml_node props = objxml.child("properties").child("property"); props; props = props.next_sibling("property")) {
        object->registerProperty(props.attribute("name").value(), props.attribute("value").value());
    }
    return object;
}

Polygon* Parser::parsePolygon(pugi::xml_node plgnxml)
{
    Polygon* polygon = new Polygon(plgnxml.attribute("points").value());
    return polygon;
}
