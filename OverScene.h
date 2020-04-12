#pragma once
#include "Scene.h"
#include <string>
#include<iostream>
#include "GameOutput.h"
using namespace std;
class OverScene :public Scene {
private:
	int icon;
	GameOutput* go;
	
public:
	void Init();
	void Run();
	void End();
};