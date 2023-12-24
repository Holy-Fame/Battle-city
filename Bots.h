#pragma once
#include <vector>
#include <string>

std::vector<std::string> botsFirstLevel =
{
	"Enemy2", "Enemy2", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1"
};

std::vector<std::string> botsSecondLevel =
{
	"Enemy2", "Enemy2", "Enemy2", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1", "Enemy1"
};

std::vector<std::string> botsThirdLevel =
{
	"Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy1", "Enemy1", "Enemy1", "Enemy1"
};

std::vector<std::string> botsFourthLevel =
{
	"Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy1", "Enemy1"
};

std::vector<std::string> botsFifthLevel =
{
	"Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2", "Enemy2"
};

std::vector<std::vector<std::string>> bots { botsFirstLevel, botsSecondLevel, botsThirdLevel, botsFourthLevel, botsFifthLevel };