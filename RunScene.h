#pragma once
#include "GameOutput.h"
#include "Snake.h"
class RunScene :public Scene {
private:
	Snake* snake;
	int foodx;
	int foody;
	bool food_b;
	int speed;
	GameOutput *view;
public:
	/*RunScene(GameOutput p) :view(p) {

	}*/
	void Init();
	void Run();
	void End();
};