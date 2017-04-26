#pragma once
#include "Matterbot.h"
#include <string>
#include <locale>
#include <algorithm>
#include <iostream>



namespace lospi
{
	struct md5Command : ICommand {
		explicit md5Command(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"challenges";
		}

		std::wstring get_help() override {
			return L"`challenges [MESSAGE]`: `challenges` will respond with the md5 hash of the [MESSAGE].";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			bot->post_message(command_text);

			// Step 1
			std::wstring original = command_text;

			//step 2
			std::string origin2 = wstring_to_string(original);
			
			// Step 3
			const char *origin3 = origin2.c_str();
			
			// Step 4
			Md5Digest md5 = compute_md5(origin3, command_text.length());

			// Step 5			
			std::wstring md5_str = get_str_from_md5(md5);

			return md5_str;

		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}