#include "OverScene.h"
#include"CCommon.h"
#include <Windows.h>
#include <conio.h>
using namespace std;
#define STD_OUTPUT_HANDLE   ((DWORD)-11)
void setposition(int x, int y)
{
	COORD   position;

	position.X = 2 * x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
void OverScene::Init() {
	icon = 1;
	gameState = 1;
	go= new GameOutput(35, 15);
	string pixel[12] = { "　","再","来","一","局","游","戏","退","出","得","分",to_string(CCommon::score) };
	go->SetPixel(pixel, 12);
	Bmp* bmp1 = new Bmp(), * bmp2 = new Bmp(), * bmp3 = new Bmp();

	//图片数据
	int bmpData1[4] = { 1,2,3,4 };
	int bmpData2[4] = { 7,8,5,6 };
	int bmpData3[4] = { 9,10,11,0 };
	bmp1->SetBmpData(4, 1, bmpData1);
	bmp2->SetBmpData(4, 1, bmpData2);
	bmp3->SetBmpData(4, 1, bmpData3);

	go->LoadBmp("重新开始", bmp1);
	go->LoadBmp("退出", bmp2);
	go->LoadBmp("分数", bmp3);
	gameState = 2;
}
void OverScene::Run() {
	go->Begin(0);
	go->DrawBmp("分数", 14, 6);
	go->DrawBmp("重新开始", 14, 9);
	go->DrawBmp("退出", 14, 11);
	go->End();
	if (icon == 1)
	{
		setposition(14, 9);
		printf("\033[7m再来一局\033[0m");
	}
	if (icon == 2) {
		setposition(14, 11);
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

void OverScene::End() {
	if (icon == 1)
		CCommon::scene = new RunScene();
	if (icon == 2)
		exit(0);
}