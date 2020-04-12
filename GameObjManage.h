#pragma once
#include <iostream>
using namespace std;
typedef struct Body* s_list;
struct Body
{
	int id;
	int x;
	int y;
	s_list next;

};
class GameObjManage {
private:
	s_list L;
public:
	GameObjManage() {
		
		L = new Body();
		L->next = NULL;
		
	}
	void LoadObj(int id, int bx, int by) {
		s_list p = L->next;
		if (p== NULL)
		{
			p = L;
			s_list s = new Body();
			s->id = id;
			s->x = bx;
			s->y = by;
			s->next = p->next;
			p->next = s;
			return;
		}
		while (p) {
			if (p->next == NULL) {
				s_list s = new Body();
				s->id = id;
				s->x = bx;
				s->y = by;
				s->next = p->next;
				p->next = s;
				return;
			}
			p = p->next;
		}
	}
	void SetObj(int id, int x, int y) {
		s_list p = L->next;
		while (p) {
			if (p->id == id) {
				p->x = x;
				p->y = y;
				return;
			}
			p = p->next;
		}
	}
	void EraseObj(int id) {
		s_list p = L->next, prev = L;
		while (p) {
			if (p->id == id) {
				prev->next = p->next;
				delete p;
				return;
			}
			p = p->next;
			prev = prev->next;
		}
	}
	s_list S_GetObject(int id) {
		s_list p = L->next;
		while (p) {
			if (p->id == id) {
				return p;
			}
			p = p->next;
		}
	}

};