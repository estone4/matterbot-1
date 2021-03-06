#pragma once
#include "Matterbot.h"
#include "Globals.h"
#include <string>
#include <locale>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>

namespace lospi
{
	struct ChallengesCommand : ICommand {
		explicit ChallengesCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			return L"`challenges [MESSAGE]`: `challenges` will respond with the md5 hash key of the [MESSAGE].";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			std::string comb_input = "hsoj";
			//auto salt_length = 11;
			//std::string password = "7aksm7";
			//std::map<Md5Digest, std::string> lookup;
			std::wstring md5_str;
			//auto result=lookup.find;
			//Md5Digest hashinput;
			std::vector <Md5Digest> challenge_list;
			std::vector<std::string> answer_list;
			std::wstringstream ss(command_text);
			std::wstring str;

			//ss = command_text;

			if (lookup.empty())
			{

				build_table(salt_length, password);

			}

			while (std::getline(ss, str, L' '))
			{
				challenge_list.push_back(get_md5_from_str(str));
			}

			// do the hash collisions here
			for (const auto& cli : challenge_list)
			{
				auto it = lookup.find(cli);
				if (it != lookup.end())
				{
					std::string answer = it->second;
					answer_list.push_back(answer);
				}
			}

			// put the answers into a string for theTry
			str = L"";
			do
			{
				std::wstring answer;
				answer = string_to_wstring(answer_list.back());
				//copy(answer_list.back().begin(), answer_list.back().end(), back_inserter(answer));
				//answer.append(string_to_wstring(passwd));
				str += L" " + answer;
				answer_list.pop_back();
			} while (!answer_list.empty());

			// convert theAnswers to wstring and try the password list
			std::wstring theTry = L"rivestment try" + str;
			bot->post_message(theTry);
			_sleep(5000);
			std::wstring challenge = L"rivestment challenge";
			return challenge;

		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}