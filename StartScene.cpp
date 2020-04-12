#include "GameOutput.h"
#include "StartScene.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "CCommon.h"

using namespace std;
#define STD_OUTPUT_HANDLE   ((DWORD)-11)
void setPosition(int x, int y)
{
	COORD   position;

	position.X = 2 * x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void StartScene::Init() {
	icon = 1;
	gameState = 1;
	view = new GameOutput(35, 15);
	string pixel[23] = { "　","开","始","游","戏","退","出","欢","迎","来","到","贪","吃","蛇","，","准","备","好","挑","战","了","吗","！"};
	view->SetPixel(pixel, 23);
	Bmp* bmp1 = new Bmp(), * bmp2 = new Bmp(), * bmp3 = new Bmp();

	//图片数据
	int bmpData1[4] = { 1,2,3,4 };
	int bmpData2[4] = { 5,6,3,4 };
	int bmpData3[18] = { 7,8,9,10,11,12,13,3,4,14,15,16,17,18,19,20,21,22 };
	bmp1->SetBmpData(4, 1, bmpData1);
	bmp2->SetBmpData(4, 1, bmpData2);
	bmp3->SetBmpData(18, 1, bmpData3);
	
	
	view->LoadBmp("开始", bmp1);
	view->LoadBmp("退出", bmp2);
	view->LoadBmp("欢迎",bmp3);
	gameState = 2;
}
void StartScene::Run() {
	view->Begin(0);
	view->DrawBmp("开始", 14, 9);
	view->DrawBmp("退出", 14, 11);
	view->DrawBmp("欢迎", 7, 5);
	view->End();
	if (icon == 1)
	{
		setPosition(14, 9);
		printf("\033[7m开始游戏\033[0m");
	}
	if (icon == 2) {
		setPosition(14, 11);
		printf("\033[7m退出游戏\033[0m");
	}
	if (_kbhit()) {
		char input = _getch();
		switch (input)
		{
		case 'w':
		{
			if (icon == 2)
				icon = 1;
			break;
		}
		case 's': {
			if (icon == 1)
				icon = 2;
			break;
		}
		case ' ': {
			gameState = 3;
			break;
		}
		default:
			break;
		}

	}
	Sleep(60);
}

void StartScene::End() {
	if (icon == 1)
		CCommon::scene = new RunScene();
	if (icon == 2)
		exit(0);
}