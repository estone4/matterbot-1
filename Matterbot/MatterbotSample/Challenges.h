#pragma once
#include "Matterbot.h"
#include "md5Utilities.h"
#include <sstream>
#include <map>

std::wstring explosions(std::wstring hashes)
{
	std::vector<Md5Digest> challenge_list;
	std::vector<std::string> answer_list;
	std::wstringstream ss(hashes);
	std::wstring str;
	//split text into challenge list
	while (std::getline(ss, str, L' '))
	{
		challenge_list.push_back(get_md5_from_str(str));
	}
}