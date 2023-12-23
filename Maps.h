#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

const int MAP_WIDTH = 26;
const int MAP_HIGHT = 26;
sf::String firstLevelMap[MAP_HIGHT] =
{
	"                          ",
	"                          ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##          ##  ##  ",
	"  ##  ##          ##  ##  ",
	"          ##  ##          ",
	"          ##  ##          ",
	"##  ####          ####  ##",
	"ww  ####          ####  ww",
	"          ##  ##          ",
	"          ######          ",
	"  ##  ##  ######  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##          ##  ##  ",
	"  ##  ##          ##  ##  ",
	"  ##  ##   ####   ##  ##  ",
	"           #qo#           ",
	"           #er#           ",
};

std::vector<std::string> botsFirstLevel =
{
	"Enemy2", "Enemy2", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1"
};

sf::String secondLevelMap[MAP_HIGHT] =
{
	"                          ",
	"                          ",
	"  ##  ww      ##  ##  ##  ",
	"  ##  ww      ##  ##  ##  ",
	"  ##        ####  ##ww##  ",
	"  ##        ####  ##ww##  ",
	"      ##          ww      ",
	"      ##          ww      ",
	"      ##    ww    ##  ##ww",
	"      ##    ww    ##  ##ww",
	"          ##    ww        ",
	"          ##    ww        ",
	"  ######      ww      ##  ",
	"  ######      ww      ##  ",
	"      ww  ##  ##  ##  ##  ",
	"      ww  ##  ##  ##  ##  ",
	"ww##  ww  ##  ##      ##  ",
	"ww##  ww  ##  ##      ##  ",
	"  ##  ##  ######  ##ww##  ",
	"  ##  ##  ######  ##ww##  ",
	"  ##  ##  ######          ",
	"  ##  ##  ######          ",
	"  ##              ##  ##  ",
	"  ##       ####   ##  ##  ",
	"  ##  ##   #qo#   ######  ",
	"  ##  ##   #er#   ######  ",
};

sf::String thirdLevelMap[MAP_HIGHT] =
{
	"                          ",
	"                          ",
	"    wwwwwwww        ww    ",
	"    ww              ww    ",
	"    ww          wwwwww    ",
	"    ww            wwww    ",
	"  ww        ww      ww    ",
	"  ww        ww      ww    ",
	"          wwww      wwww  ",
	"          wwww        ww  ",
	"  ww    wwwwww  ww        ",
	"  ww    wwwwww  ww        ",
	"   w  wwww      wwww      ",
	"   w  wwww      wwww      ",
	"w       ww  wwwwww     w  ",
	"w       ww  wwwwww     w  ",
	"   www      wwww      ww  ",
	"   www      wwww      ww  ",
	"  ww        ww      wwww  ",
	"  ww        ww      wwww  ",
	"  wwwwww          ww      ",
	"      ww          ww      ",
	"                  ww    ww",
	"           ####       wwww",
	"           #qo#           ",
	"wwww       #er#           ",
};

sf::String fourthLevelMap[MAP_HIGHT] =
{
	"                          ",
	"                          ",
	"    ################      ",
	"  ##################      ",
	"                  ####    ",
	"                  ####    ",
	"                    ####  ",
	"                    ####  ",
	"    ww    ww              ",
	"    ww    ww              ",
	"    ww    ww              ",
	"    ww    ww              ",
	"                    ##### ",
	"                    ##### ",
	"                  ####### ",
	"                  ####### ",
	"##    ####      ########  ",
	"##    ####      ########  ",
	"  ####################  ww",
	"  ####################  ww",
	"ww  ##ww#############   ww",
	"ww  ##ww#############   ww",
	"  ww####ww      ####wwwwww",
	"  ww##  ww #### ####wwwwww",
	"           #qo#           ",
	"           #er#           ",
};

sf::String fifthLevelMap[MAP_HIGHT] =
{
	"                          ",
	"                          ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ##  ##  ##  ##  ##  ##  ",
	"  ww  ww  ww  ww  ww  ww  ",
	"                          ",
	"        ##      ##        ",
	"##  ##  ##      ##  ##  ##",
	"##  ######  ##  ######  ##",
	"##  ##  ##  ##  ##  ##  ##",
	"ww  ww  ww  ww  ww  ww  ww",
	"        ww      ww        ",
	"        ##      ##        ",
	"        ##      ##        ",
	"        ####  ####        ",
	"        ##      ##        ",
	"                          ",
	"                          ",
	"        ##      ##        ",
	"##  ##  ##      ##  ##  ##",
	"  ##  ##          ##  ##  ",
	"  ##  ##          ##  ##  ",
	"  ##  ##          ##  ##  ",
	"  ##  ##   ####   ##  ##  ",
	"  ##  ##   #qo#   ##  ##  ",
	"           #er#           ",
};

std::vector<sf::String* > mapsArr{ firstLevelMap, secondLevelMap, thirdLevelMap, fourthLevelMap, fifthLevelMap };
