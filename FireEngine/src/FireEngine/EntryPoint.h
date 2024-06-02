#pragma once

#ifdef FIRE_ENGINE_WINDOWS


/*
extern FireEngine::Application FireEngine::CreateApplication(); 
是一个C++语言中的函数声明。
这行代码表示在命名空间 FireEngine 中声明了一个函数 CreateApplication，
该函数返回一个 FireEngine::Application 类型的对象，并且该函数在其它的文件中定义。
这种声明通常用于告诉编译器有一个特定的函数在其它的文件中，
但是不在这个文件中定义。这样的函数通常在库中实现，然后被链接到程序中。
*/
extern FireEngine::Application* FireEngine::CreateApplication();

int main(int argc, char** argv) {
	FireEngine::Log::Init();
	FIRE_CORE_WARN("Initialized Log!");

	int a = 5;
	FIRE_INFO("Hello! Var={0}", a);

	auto app = FireEngine::CreateApplication();
	app->Run();

	delete app;
}





#endif // FIRE_ENGINE_WINDOWS
