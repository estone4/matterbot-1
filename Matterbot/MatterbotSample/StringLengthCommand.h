#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct StringLengthCommand : ICommand {
		explicit StringLengthCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"length";
		}

		std::wstring get_help() override {
			return L"`length [MESSAGE]`: `length` will respond with the original message and its length.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			bot->post_message(command_text);
			auto len = command_text.length();
			return L"Your string was " + std::to_wstring(len) + L" characters long";
			
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}
