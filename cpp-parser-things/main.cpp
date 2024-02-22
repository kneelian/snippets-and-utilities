#include <string>
#include <iostream>
#include <vector>

static bool running = true;

enum command_t
{
	QUIT = 0,
	GO,
	LOOK,
	EXAMINE,
	UNKNOWN = -1
};

struct loc_t // location
{
	std::string desc;
	std::string tag;
	loc_t* west;
	loc_t* east;
};

command_t parse(std::string& a)
{
	if(a == "quit") { return QUIT; } else
	if(a == "go")   { return GO; } else
	if(a == "look") { return LOOK; } else
	if
	( 
		(a == "x")||
		(a == "examine")
	) { return EXAMINE; } else
	{ return UNKNOWN; }
}

void execute(command_t a)
{
	switch(a)
	{
		case QUIT:
			running = false;
			break;
		case GO:
			std::cout << "nowhere to go" << std::endl;
			break;
		case LOOK:
		case EXAMINE:
			std::cout << "you're blind" << std::endl;
			break;
		case UNKNOWN:
			std::cout << "huh?" << std::endl;
			break;
		default:;
	}
	return;
}

bool get_input(std::string& a)
{
	a.clear();
	std::cout << "\n==> ";
	std::getline(std::cin, a);
	return !(a.empty());
}

int main()
{
	std::string input;
	std::cout << "Entry" << std::endl;

	loc_t evil_place = { "an evil place", "evil", 0, 0 };
	loc_t good_place = { "a good place" , "good", 0, 0 };
	evil_place.west = &good_place;
	good_place.east = &evil_place;

	while(running)
	{
		if(!get_input(input)) { continue; } // if it's an empty input, re-prompt
		execute(parse(input));
	}

	std::cout << "Exit" << std::endl;

	return 0;
}