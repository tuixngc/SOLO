#pragma once
#include "core.h"

namespace SOLO {

	class SOLO_API Application
	{
	public:
		Application();

		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


