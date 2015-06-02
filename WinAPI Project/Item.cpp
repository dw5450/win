#include "stdafx.h"

#define SIZE 100								// 아이템 오브젝트의 맵상에서의 사이즈. 적당히 조절할것.

Item::Item(){};

Item::Item(const int x, const int y, const int type){
	p.x = x;	p.y = y;
	itemType = type;
};
Item::~Item(){};

void Item::draw(){
	// 테스트용
	MoveToEx(hdc, p.x, p.y, NULL);
	LineTo(hdc, p.x + SIZE, p.y + SIZE);
};
void Item::crash(){
	//if (itemStockCounter < 3){		
	//	MoveToEx(hdc, p.x, p.y,NULL);				// 테스트용->스톡에 추가할 부분
	//	LineTo(hdc, p.x + SIZE, p.y + SIZE);
	//}

	Item::~Item();									// 삭제하든가 좌표를 멀리 날리든가.
}

const POINT Item::getItem(){
	POINT tp;
	tp.x = p.x;		tp.y = p.y;

	return tp;
}

void Item::putItem(int x,int y,int type){
	p.x = x;	p.y = y;
	itemType = type;
}

// 이 아래로는 아이템 별 기능 구현

void Item::SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS){				//저항값 세팅;					//추가된 코드

}
void Item::MoveTo(const long x, const long y){			//이동할 x 방향 , y 방향			//추가된 코드

}
void Item::Move(){										//이동							//추가된 코드


}
