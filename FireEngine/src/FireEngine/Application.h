#pragma once

#include "Core.h"

namespace FireEngine {

	class FIRE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// to be defined in CLIENT
	Application* CreateApplication();
}


