#include <iostream>
#include<Windows.h>
#include "Scene.h";
#include "RunScene.h"
#include "CCommon.h"
#include<string>
#include<time.h>
#include<fstream>
using namespace std;


using namespace std;

//程序入口
int main() {
	//设置控制台窗口大小
	system("mode con cols=70 lines=25");
	//设置前景色和背景色
	system("color f0");
	system("cls");
	
	
	while (true)
	{
		
		if (CCommon::scene->GetState() == 1) {
			CCommon::scene->Init();
		}
		if (CCommon::scene->GetState() == 2) {
			CCommon::scene->Run();
		}
		if (CCommon::scene->GetState() == 3) {
			CCommon::scene->End();
		}
	}
   
	
	
	
	
	
	

	
}
