#pragma once
#include "Matterbot.h"



namespace lospi
{
	struct UpperCommand : ICommand {
		explicit UpperCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"upper";
		}

		std::wstring get_help() override {
			return L"`upper [MESSAGE]`: `upper` will respond with the original message and the uppercase string.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			bot->post_message(command_text);
			std::locale loc;
			std::wstring Upper;
			for (std::wstring::size_type i = 0; i < command_text.length(); i++)
			{
				Upper.append(1, towupper(command_text[i]));
			}
			return Upper;
			
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}
