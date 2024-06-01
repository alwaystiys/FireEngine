
//namespace FireEngine {
//
//	__declspec(dllimport) void Print();
//}

#include<FireEngine.h>

class Sandbox : public FireEngine::Application {
public:
	Sandbox() {

	}
	~Sandbox() {
		 
	}
};

FireEngine::Application* FireEngine::CreateApplication() {
	return new Sandbox();
}
