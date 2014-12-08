
#include "Command.h"
#include <iostream>

class JumpCommand : public Command
{
public:
	virtual void execute()
	{
		std::cout << "Jump!\n";
	}
};