#pragma once
class Bmp {
private:
	int m_w; //ͼƬ��
	int m_h; //ͼƬ��
	int* m_data;  //ͼƬ����
	int m_len;  //���ݳ���

public:
	void SetBmpData(int w, int h, int* data);
	int GetW();
	int GetH();
	int* GetData();

};