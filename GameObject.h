#pragma once
#include <iostream>
using namespace std;
class GameObject {
private:
	int s_x;
	int s_y;
	int* s_dir;
public:
	GameObject(int x, int y) {
		s_x = x;
		s_y = y;
		
		s_dir = new int[2]{ 0,0 };
	}
	void Run(int dir) {
		if (dir > 4 || dir < 0)
			return;
		switch (dir)
		{
		case 1:s_dir = new int[2]{ 0,-1 }; break;
		case 2:s_dir = new int[2]{ 0,1 }; break;
		case 3:s_dir = new int[2]{ -1,0 }; break;
		case 4:s_dir = new int[2]{ 1,0 }; break;
		default:
			break;
		}
		s_x += s_dir[0];
		s_y += s_dir[1];
	}
	int GetX() {
		return s_x;
	}
	int GetY() {
		return s_y;
	}
};