#include "Level.h"

Level::Level(std::string const levelname, sf::RenderWindow& window)
{
    
    pugi::xml_document tmx;
    pugi::xml_document tsx;

    std::string tmxFile = "Maps/" + levelname;

    pugi::xml_parse_result result = tmx.load_file(tmxFile.c_str());


    std::stringstream stream;
    stream << "Maps/" << tmx.child("map").child("tileset").attribute("source").as_string();
    pugi::xml_parse_result result2 = tsx.load_file(stream.str().c_str());

    std::istringstream ss(tmx.child("map").child("layer").child("data").child_value());

    _mapSize.x = tmx.child("map").attribute("width").as_int();
    _mapSize.y = tmx.child("map").attribute("height").as_int();
    _tileSize.x = tmx.child("map").attribute("tilewidth").as_int();
    _tileSize.y = tmx.child("map").attribute("tileheight").as_int();


    /*
    std::string sourcePath = tsx.child("tileset").child("image").attribute("source").as_string();
    std::size_t found = sourcePath.find_last_of("/\\");
    std::string fileName = sourcePath.substr(found + 1);
    */

    int tileCount = tsx.child("tileset").attribute("tilecount").as_int();
    int columns = tsx.child("tileset").attribute("columns").as_int();




    
    if (!_texture.loadFromFile("Maps/PrtCave.png"))
    {
        std::cout << "Failed to load texture" << std::endl;
    }

    std::string line;
    int index = 0;
    while (std::getline(ss, line))
    {
        std::istringstream ns(line);

        while (std::getline(ns, line, ','))
        {
            int ts_y = (ceil((atoi(line.c_str()) / columns)) ) * _tileSize.y;
            int ts_x = ((atoi(line.c_str()) % columns) -1 ) * _tileSize.x;

          

            int sp_y = (ceil(index / _mapSize.x) ) * _tileSize.y;
            int sp_x = ((index % _mapSize.x) ) * _tileSize.x;

        

            _tileList.push_back(new Tile(_texture, sf::Vector2i(ts_x, ts_y), sf::Vector2i(sp_x, sp_y), _tileSize, window));

            index++;
        }
    }
}

void Level::Draw(float dt)
{
    for (size_t i = 0; i < this->_tileList.size(); i++)
    {
        this->_tileList.at(i)->Draw(dt);
    }
}