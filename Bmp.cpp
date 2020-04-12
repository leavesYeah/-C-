#include "Bmp.h"

void Bmp::SetBmpData(int w, int h, int* data) {
	if (w < 0 || h < 0) {
		return;
	}
	m_w = w;
	m_h = h;
	m_len = m_w * m_h;
	m_data = new int[m_len];
	for (int i = 0; i < m_len; i++) {
		m_data[i] = data[i];
	}
}

int Bmp::GetW() {
	return m_w;
}

int Bmp::GetH() {
	return m_h;
}

int* Bmp::GetData() {
	return m_data;
}