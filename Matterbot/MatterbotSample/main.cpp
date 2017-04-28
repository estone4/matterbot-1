#include "Matterbot.h"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <ostream>
#include "ConsoleLogger.h"
#include "EchoCommand.h"
#include "WeatherCommand.h"
#include "UpperCommand.h"
#include "StringLengthCommand.h"
#include "ReverseCommand.h"
#include "LowerCommand.h"
#include "Points.h"
#include "Scraps.h"
#include "Globals.h"
#include "Challenges.h"
#include "md5Utilities.h"
//#include "Rivestment.h"

#define ERROR_SUCCESS 0
#define ERROR_FAILURE -1

using namespace std;
using namespace lospi;

int main() {
  wstring mattermost_url = L"https://hooks.slack.com",
    incoming_hook_route = L"services/T4Z1QAKSS/B504GJ98D/rv1SYO7QUhl6Z7oOf7p4IqQM",
    outgoing_hook_route = L"http://127.0.0.1:9000/",
    outgoing_hook_token = L"yPo0ctvtdgulUMHFFmwRgmQO",
    welcome_message = L"bot is running.";

  try {
    auto bot = make_shared<Matterbot>(mattermost_url, incoming_hook_route, outgoing_hook_route, outgoing_hook_token);
    bot->set_logger(make_unique<ConsoleLogger>());
    bot->register_command(make_shared<EchoCommand>());
    bot->register_command(make_shared<ReverseCommand>(bot));
	  bot->register_command(make_shared<WeatherCommand>());
	  bot->register_command(make_shared<StringLengthCommand>(bot));
	  bot->register_command(make_shared<UpperCommand>(bot));
	  bot->register_command(make_shared<LowerCommand>(bot));
	  //bot->register_command(make_shared<md5Command>(bot));
	  bot->register_command(make_shared<ChallengesCommand>(bot));
	  bot->register_command(make_shared<PointsCommand>(bot));
	  bot->register_command(make_shared<scrapsCommand>(bot));
    bot->post_message(welcome_message);

    wstring console;
    wclog << ">> Type \'quit\' to quit. Any other input will be sent to the bot." << endl;
    while (getline(wcin, console)) {
      if (L"quit" == console) {
        wclog << ">> Quitting." << endl;
        return ERROR_SUCCESS;
      }
      if (L"" != console) { bot->post_message(console); }
    }
  }
  catch (exception e) {
    wcerr << "[-] Unhandled exception:" << e.what() << endl;
    return ERROR_FAILURE;
  }
}
