#pragma once
#include "Matterbot.h"

namespace lospi
{
	struct LowerCommand : ICommand {
		explicit LowerCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"lower";
		}

		std::wstring get_help() override {
			return L"`lower [MESSAGE]`: `lower` will respond with the original message and the lowercase string.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			bot->post_message(command_text);
			std::locale loc;
			std::wstring Lower;
			for (std::wstring::size_type i = 0; i < command_text.length(); i++)
			{
				Lower.append(1, towlower(command_text[i]));
			}
			return Lower;

		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}
