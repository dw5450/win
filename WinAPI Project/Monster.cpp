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

// 좌표값에 access하기 위한 함수들

void Monster::SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS){				//저항값 세팅;					//추가된 코드
	resistanceXpos = RESISTANCEXPOS;
	resistanceYpos = RESISTANCEYPOS;
}
void Monster::MoveTo(const long x, const long y){			//이동할 x 방향 , y 방향			//추가된 코드
	
}
void Monster::Move(){										//이동							//추가된 코드
	
}

