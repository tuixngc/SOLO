#pragma once
#ifdef SOLO_PLATFORM_WINDOWS

extern SOLO::Application* SOLO::CreateApplication();

int main(int argc, char** argv)
{
	SOLO::Log::init();
	SOLO_CORE_INFO("SOLO Initialized Log!");
	auto app = SOLO::CreateApplication();
	int num = 5;
	SOLO_WARN("SOLO Application created! {0}", num);
	app->Run();
	delete app;
}

#endif