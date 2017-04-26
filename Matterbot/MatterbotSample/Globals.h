#pragma once
#include "Matterbot.h"
#include "md5Utilities.h"
#include <map>
#include <string>

namespace lospi
{
	std::map<Md5Digest, std::string> lookup;
	std::string password = "7aksm7";
	//auto level = 1;
	auto salt_length = 13;

}