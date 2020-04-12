#include"GameOutput.h"
#include"DataDictionary.h"
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;
#define STD_OUTPUT_HANDLE   ((DWORD)-11)
void SetWPosition(int x, int y)
{
	COORD   position;

	position.X = 2 * x;
	position.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

GameOutput::GameOutput(int w, int h) {
	
	if (w < 1)
		w = 1;
	if (h < 1)
		h = 1;
	m_W = w;
	m_H = h;
	m_S = m_W * m_H;
	m_Map = new int[m_S];
	m_BmpList = new Dictionary();
}

void GameOutput::LoadBmp(string id, Bmp *bmp) {
	
	if (m_BmpList->ContainKey(id))
		return;
	m_BmpList->Add(id, bmp);
	
}

void GameOutput::SetPixel(string* pixel,int n) {
	m_Pixel = new string[n];
	for (int i = 0; i < n; i++)
		m_Pixel[i] = pixel[i];
	m_PixelLen = n;
}

void GameOutput::Begin(int style) {
	if (style == 0) {
		for (int i = 0; i < m_S; i++) {
			m_Map[i] = 0;
		}
	}
	
	if (style == 1) {
		for (int i = 0; i < m_S; i++) {
			m_Map[i] = 0;
			if (i % m_W == 0 || i % m_W == m_W - 1|| i / m_W == 0 || i / m_W == m_H - 1)
				m_Map[i] = 1;
		}
	}
	
}

void GameOutput::DrawBmp(string id, int x, int y) {
	if (x >= m_W || x < 0 || y >= m_H || y < 0)
		return;
	if (!m_BmpList->ContainKey(id))
		return;
	Bmp *bmp = m_BmpList->GetBmp(id);
	
	int pos = x + y * m_W;
	for (int i = 0; i < bmp->GetW() * bmp->GetH(); i++) {
		if (x >= 0 && x < m_W && y >= 0 && y < m_H)
			m_Map[pos] = bmp->GetData()[i];
		pos += 1;
		x += 1;
		if (i % bmp->GetW() == bmp->GetW() - 1) {
			y++;
			x -= bmp->GetW();
			pos = x + y*m_W;
		}
	}
}

void GameOutput::End() {
	//system("cls");
	SetWPosition(0, 0);
	for (int i = 0; i < m_S; i++) {
		cout << m_Pixel[m_Map[i]];
		if (i % m_W == m_W - 1)
			cout << endl;
	}
}

int GameOutput::GetPixelLen() {
	return m_PixelLen;
}

int GameOutput::GetClientW() {
	return m_W;
}

int GameOutput::GetClientH() {
	return m_H;
}