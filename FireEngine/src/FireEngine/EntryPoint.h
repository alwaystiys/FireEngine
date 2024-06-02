#pragma once

#ifdef FIRE_ENGINE_WINDOWS


/*
extern FireEngine::Application FireEngine::CreateApplication(); 
��һ��C++�����еĺ���������
���д����ʾ�������ռ� FireEngine ��������һ������ CreateApplication��
�ú�������һ�� FireEngine::Application ���͵Ķ��󣬲��Ҹú������������ļ��ж��塣
��������ͨ�����ڸ��߱�������һ���ض��ĺ������������ļ��У�
���ǲ�������ļ��ж��塣�����ĺ���ͨ���ڿ���ʵ�֣�Ȼ�����ӵ������С�
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
