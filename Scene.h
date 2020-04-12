#pragma once
class Scene {
public:
	int gameState = 1;
	virtual void Init() {

	}
	virtual void Run() {

	}
	virtual void End() {

	}
	virtual int GetState() {
		return gameState;
	}
};