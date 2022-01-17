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

SOLO::Application* SOLO::CreateApplication()
{
	return new Sandbox();
}