#include "Matterbot.h"
#include <string>
#include <locale>
#include <algorithm>
#include <iostream>
#include <map>

namespace lospi
{
	struct PointsCommand : ICommand {
		explicit PointsCommand(std::shared_ptr<Matterbot> bot) : bot{ bot } { }
		std::wstring get_name() override {
			return L"points";
		}

		std::wstring get_help() override {
			return L"`points [MESSAGE]`: `points` will send the lookup to rivestment.";
		}

		std::wstring handle_command(const std::wstring &team, const std::wstring &channel,
			const std::wstring &user, const std::wstring &command_text) override {

			bot->post_message(command_text);
			
			return 0;
			
		}
	private:
		std::shared_ptr<Matterbot> bot;
	};
}