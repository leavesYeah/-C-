#pragma once
#include <string>
#include <windows.h>
#include "DataDictionary.h"
using namespace std;


class GameOutput {
private:
	string* m_Pixel;
	int m_PixelLen;
	Dictionary *m_BmpList;

	//绘图区域
	int* m_Map;
	int m_W;
	int m_H;
	int m_S;  //画布面积
public:
	
	
	GameOutput(int w, int h);
	void LoadBmp(string id, Bmp *bmp);
	void SetPixel(string* pixel,int n);
	void Begin(int style);
	void DrawBmp(string id, int x, int y);
	void End();
	int GetPixelLen();
	int GetClientW();
	int GetClientH();
};