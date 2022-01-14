#include "SOLO.h"

class Sandbox :public SOLO::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

int main()
{
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}