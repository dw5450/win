#include "stdafx.h"

Monster::Monster(){};
Monster::Monster(const long x, const long y, const SIZE size, const int type){
	p.x = x;			p.y = y;
	ObjectSize = size;
	monsterType = type;

	ObjectRect.left = x - size.cx / 2;
	ObjectRect.top = y - size.cy / 2;
	ObjectRect.right = x + size.cx / 2;
	ObjectRect.bottom = y + size.cy / 2;
};
Monster::~Monster(){};

//void Monster::crash(){
//
//};
void Monster::draw(){
	Ellipse(hdc, ObjectRect.left, ObjectRect.top, ObjectRect.right, ObjectRect.bottom);
};

// ��ǥ���� access�ϱ� ���� �Լ���

void Monster::SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS){				//���װ� ����;					//�߰��� �ڵ�
	resistanceXpos = RESISTANCEXPOS;
	resistanceYpos = RESISTANCEYPOS;
}
void Monster::MoveTo(const long x, const long y){			//�̵��� x ���� , y ����			//�߰��� �ڵ�
	
}
void Monster::Move(){										//�̵�							//�߰��� �ڵ�
	
}

