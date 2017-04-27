#pragma once
#include "Matterbot.h"
#include "md5Utilities.h"
#include <map>
#include <string>

namespace lospi
{
	std::map<Md5Digest, std::string> lookup;
	auto password = "s5nuq1";
	auto level = 4;
	auto salt_length = level+10;

	void build_table(int salt_length, std::string password)
	{
		for (int i = 0; i < salt_length; i++)
		{
			Combinator c("hsoj", i);

			while (c.has_next())
			{
				auto combo = c.next();
				copy(password.begin(), password.end(), back_inserter(combo));
				Md5Digest newhash = compute_md5(combo.data(), combo.size());
				lookup.emplace(newhash, std::string{ combo.begin(),combo.end() });
			}
		}
	}
}