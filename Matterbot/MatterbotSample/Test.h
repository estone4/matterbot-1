#pragma once
#include "Matterbot.h"
#include <string>
#include <locale>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>

std::wstring explosions(std::wstring hashes);

//std::wstring explosions(std::wstring hashes)
//{
//	std::vector<Md5Digest> challenge_list;
//	std::vector<std::string> answer_list;
//	std::wstringstream ss(hashes);
//	std::wstring str;
//	//split text into challenge list
//	while (std::getline(ss, str, L' '))
//	{
//		challenge_list.push_back(get_md5_from_str(str));
//	}
//	return challenge_list;
//}

namespace lospi
{
	struct testCommand : ICommand {
		explicit testCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			return L"`challenges [MESSAGE]`: `challenges` will respond with the md5 hash key of the [MESSAGE].";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			//bot->post_message(command_text);

			std::string comb_input = "hsoj";
			auto salt_length = 10;
			std::string password = "9gicdd";
			std::map<Md5Digest, std::string> lookup;
			std::wstring md5_str;
			//auto result=lookup.find;
			//Md5Digest hashinput;
			std::vector <Md5Digest> challenge_list;
			std::vector<std::string> answer_list;
			std::wstringstream ss(command_text);
			std::wstring str;

			ss = command_text.data;

			if (lookup.empty())
			{
				for (int i = 0; i <= salt_length; i++)
				{
					Combinator c("hsoj", i);

					while (c.has_next())
					{
						auto combo = c.next();
						copy(password.begin(), password.end(), back_inserter(combo));
						Md5Digest newhash = compute_md5(combo.data(), combo.size());
						std::wstring md5_str = get_str_from_md5(newhash);
						lookup.emplace(newhash, std::string{ combo.begin(),combo.end() });
					}
				}
			}

		/*std::wstring collisons(std::wstring hashes)
		{
			std::vector<Md5Digest> challenge_list;
			std::vector<std::string> answer_list;
			std::wstringstream ss(hashes);
			std::wstring str;
		}*/


			while (std::getline(ss, str, L' '))
			{
				challenge_list.push_back(get_md5_from_str(str));
			}
			
			auto result = lookup.find(challenge_list());
			if (result == lookup.end())
			{
				std::cout<<"ERROR!";
			}
			auto key = result->first;
			auto value = result->second;

			auto tryText = "rivestment try " + value;

			bot->post_message(string_to_wstring(tryText));

			return 0; //string_to_wstring(value);
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}