#include <iostream>
#include<Windows.h>
#include "Scene.h"
#include <string>
#include "RunScene.h"
#include"GameOutput.h"
#include"CCommon.h"
#include <time.h>
#include <conio.h>
#include "OverScene.h"
using namespace std;
#define STD_OUTPUT_HANDLE   ((DWORD)-11)
void SetPosition(int x, int y)
{
	COORD   position;

	position.X = 2 * x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void RunScene::Init() {
	
	
	speed = 180;
	CCommon::score = 0;
	
	snake = new Snake("snake", 2, 3);
	
	foodx = 8;
	foody = 8;
	food_b = false;
	view = new GameOutput(35, 15);
	
	string pixel[8] = { "　","◆","¤","●","★","○","▼","▲" };
	view->SetPixel(pixel, 8);
	
	Bmp* bmp1=new Bmp(), * bmp2=new Bmp(), * bmp3=new Bmp(), * bmp4=new Bmp();
	
	//图片数据
	int bmpData1[1] = { 2 };
	int bmpData2[1] = { 3 }; 
	int bmpData3[1] = { 4 };
	int bmpData4[1] = { 5 };
	bmp1->SetBmpData(1, 1, bmpData1);
	bmp2->SetBmpData(1, 1, bmpData2);
	bmp3->SetBmpData(1, 1, bmpData3);
	bmp4->SetBmpData(1, 1, bmpData4);
	
	view->LoadBmp("头", bmp1);
	view->LoadBmp("bodyA", bmp2);
	view->LoadBmp("星", bmp3);
	view->LoadBmp("bodyB", bmp4);
	
	
	gameState = 2;
	system("cls");
   


}
void RunScene::Run() {
	srand((unsigned)time(0));
	view->Begin(1);
	if (food_b) {
		
		foodx =rand() % (view->GetClientW() - 2) + 1;
		foody =rand()% (view->GetClientH()- 2) + 1;
		
	}
	if (snake->GetX() == foodx && snake->GetY() == foody) {
		food_b = true;
		snake->PushBody(snake->GetX(), snake->GetY());
		
		CCommon::score++;
	}
	else
		food_b = false;

	view->DrawBmp("星", foodx, foody);
	SetPosition(foodx, foody);
	cout << "☆";
	view->DrawBmp("头", snake->GetX(), snake->GetY());
	
	for (int i = 0; i < snake->GetBodyLen(); i++) {
		if (i % 2 == 0) {
			view->DrawBmp("bodyA", snake->GetBodyX(i), snake->GetBodyY(i));
			
		}
		else if (i % 2 == 1)
			view->DrawBmp("bodyB", snake->GetBodyX(i), snake->GetBodyY(i));

	}
	
	view->End();
	for (int i = snake->GetBodyLen() - 1; i > 0; i--) {
		snake->SetBodyX(i, snake->GetBodyX(i-1));
		snake->SetBodyY(i, snake->GetBodyY(i-1));
	}
	if (snake->GetBodyLen() != 0) {
		
		snake->SetBodyX(0, snake->GetX());
		snake->SetBodyY(0, snake->GetY());
	}
	switch (CCommon::score)
	{
	case 3: speed = 150; break;
	case 5: speed = 120; break;
	case 7: speed = 90; break;
	case 9: speed = 75; break;
	case 12: speed = 60; break;
	case 20: speed = 30; break;
	case 30: speed = 15; break;
	}
	if (_kbhit()) {
		char input = _getch();
		switch (input)
		{
		case 'w': {
			if (snake->GetDir() != 2 || snake->GetBodyLen() == 0)
				snake->SetDir(1);
			break;
		}
		case 's':{
			if (snake->GetDir() != 1 || snake->GetBodyLen() == 0)
				snake->SetDir(2);
			break;
		}
		case 'a': {
			if (snake->GetDir() != 4 || snake->GetBodyLen() == 0)
				snake->SetDir(3);
			break;
		}
		case 'd': {
			if (snake->GetDir() != 3 || snake->GetBodyLen() == 0)
				snake->SetDir(4);
			break;
		}
		default:
			break;
		}
	}
	snake->Move();
	if (snake->GetX() > view->GetClientW() - 2 || snake->GetY() > view->GetClientH() - 2 || snake->GetX() < 1 || snake->GetY() < 1)
		gameState = 3;
	for (int i = 0; i < snake->GetBodyLen(); i++) {
		if (snake->GetX() == snake->GetBodyX(i) && snake->GetY() == snake->GetBodyY(i))
			gameState = 3;
	}
	Sleep(speed);
}
void RunScene::End() {
	CCommon::scene = new OverScene();
}