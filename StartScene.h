#pragma once
#include "Scene.h"
#include"GameOutput.h"

class StartScene:public Scene {
private:
	int icon;
	GameOutput *view;
public:
	void Init();
	void Run();
	void End();
};