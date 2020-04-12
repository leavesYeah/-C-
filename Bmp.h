#pragma once
class Bmp {
private:
	int m_w; //图片宽
	int m_h; //图片高
	int* m_data;  //图片数据
	int m_len;  //数据长度

public:
	void SetBmpData(int w, int h, int* data);
	int GetW();
	int GetH();
	int* GetData();

};