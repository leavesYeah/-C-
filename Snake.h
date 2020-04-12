#pragma once
#include <string>
#include "GameObjManage.h"
#include "GameObject.h"
using namespace std;
class Snake {
private:
	
	string s_Name;
	int s_Dir;
	int s_BodyLen=0;
	GameObjManage* s_BodyList;
	GameObject* s_enity;
public:
	Snake(string name,int x,int y) {
		s_Name = name;
		s_BodyLen = 0;
		s_Dir = 0;
		
		s_enity = new GameObject(x, y);
		
		s_BodyList = new GameObjManage();
		
	}
	void Move() {
		switch (s_Dir)
		{
		case 1:s_enity->Run(1); break;
		case 2:s_enity->Run(2); break;
		case 3:s_enity->Run(3); break;
		case 4:s_enity->Run(4); break;
		default:
			break;
		}
	}
	int GetBodyX(int id) {
		if (id > s_BodyLen)
			return -1;
		return s_BodyList->S_GetObject(id)->x;
	}
	int GetBodyY(int id) {
		if (id > s_BodyLen)
			return -1;
		return s_BodyList->S_GetObject(id)->y;
	}
	void PushBody(int x, int y) {
		s_BodyList->LoadObj(s_BodyLen, x, y);
		s_BodyLen++;
	}
	void SetBodyX(int id, int x) {
		if (id > s_BodyLen)
			return;
		s_BodyList->SetObj(id, x, GetBodyY(id));
	}
	void SetBodyY(int id, int y) {
		if (id > s_BodyLen)
			return;
		s_BodyList->SetObj(id, GetBodyX(id), y);
	}
	int GetX() {
		return s_enity->GetX();
	}
	int GetY() {
		return s_enity -> GetY();
	}
	int GetDir() {
		return s_Dir;
	}
	void SetDir(int dir) {
		s_Dir = dir;
	}
	int GetBodyLen() {
		return s_BodyLen;
	}


};