#pragma once
#include<iostream>
#include <string>
#include "Bmp.h"
using namespace std;
typedef struct ListNode* list;
struct ListNode {
	string name;
	Bmp *bmp;
	list next;
};
class Dictionary {
private:
	list L,p;
public:
	Dictionary() {
		L = new ListNode();
		L->next = NULL;
		p = L;
	}
	void Add(string id, Bmp *bmp) {
		list s = new ListNode();
		s->name = id;
		s->bmp = bmp;
		s->next = p->next;
		p->next = s;
		p = s;
	}
	bool ContainKey(string id) {
		
		list k = L->next;
		
		while (k)
		{
			if (k->name == id)
				return true;
			k = k->next;
		}
		return false;
	}
	Bmp* GetBmp(string id) {
		list k = L->next;
		Bmp* tBmp = new Bmp();
		while (k)
		{
			if (k->name == id)
				tBmp = k->bmp;
			k = k->next;
		}
		return tBmp;
	}
};
