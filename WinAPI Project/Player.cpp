#include "stdafx.h"

										// 100 부분을 원하는값으로 바꾼다. 소녀의 크기. -> 굳이 멤버변수로 저장하지 않는 이유는 하나만 쓰기때문.
											// 모션따라 바꿀거면 멤버변수로 저장해야겠지. 근데 귀찮아		//변경한다 왜냐면 하고싶기 때문이다! ㅋㅋㅋ
Player::Player(const long x, const long y, const SIZE size){			//int -> long형 형변환 일어나기에 애초에 long형으로 받음
	p.x = x;			p.y = y;
	ObjectSize = size;
	ObjectRect.left = x - size.cx / 2;
	ObjectRect.top = y - size.cy / 2;
	ObjectRect.right = x + size.cx / 2;
	ObjectRect.bottom = y + size.cy / 2;

};
Player::~Player(){};



void Player::crash(Monster * MonsterPt){	//충돌 체크 (몬스터 포인터)		//변경된 코드
	RECT rcTemp;							//부딪힌 범위 변수				//추가된 변수
	if (IntersectRect(&rcTemp, &ObjectRect, &(MonsterPt->GetObjectRect())))
	{
		Ellipse(hdc, rcTemp.left, rcTemp.top, rcTemp.right, rcTemp.bottom);
	}

}

void Player::crash(Item * Item){			//충돌 체크 (아이템 포인터)		//변경된 코드

}

void Player::crash(HWND hWnd)
{
	RECT rectView;
	GetClientRect(hWnd, &rectView);



	if (rectView.left > p.x - ObjectSize.cx / 2 && SpeedXpos <= 0)
	{
		SpeedXpos = -SpeedXpos;
		p.x = rectView.left + ObjectSize.cx / 2;
		ObjectRect.left = p.x - ObjectSize.cx / 2;
		ObjectRect.right = p.x + ObjectSize.cx / 2;
	}
	else if (rectView.right < p.x + ObjectSize.cx / 2 && SpeedXpos >= 0)
	{
		SpeedXpos = -SpeedXpos;
		p.x = rectView.right - ObjectSize.cx / 2;
		ObjectRect.left = p.x - ObjectSize.cx / 2;
		ObjectRect.right = p.x + ObjectSize.cx / 2;
	}

	if (rectView.top > p.y - ObjectSize.cy / 2 && SpeedYpos <= 0)
	{
		SpeedYpos = -SpeedYpos;
		p.y = rectView.top + ObjectSize.cy / 2;
		ObjectRect.top = p.y - ObjectSize.cy / 2;
		ObjectRect.bottom = p.y + ObjectSize.cy / 2;
	}

	else if (rectView.bottom < p.y + ObjectSize.cy / 2 && SpeedYpos >= 0)
	{
		SpeedYpos = -SpeedYpos;
		p.y = rectView.bottom - ObjectSize.cy / 2;
		ObjectRect.top = p.y - ObjectSize.cy / 2;
		ObjectRect.bottom = p.y + ObjectSize.cy / 2;
	}

}
void Player::draw(){									//저항값 적용 패치함

	//그리는 부분

	Rectangle(hdc, ObjectRect.left, ObjectRect.top,
		ObjectRect.right, ObjectRect.bottom);

	

	/*else if (MoveToYpos < 0)
		MoveToYpos = 0;*/

		// 테스트용

};

//-----------좌표값에 access하기 위한 함수들--------------
const POINT Player::getPlayer(){
	POINT tp;
	tp.x = p.x;			tp.y = p.y;

	return tp;
};
void Player::putPlayer(const int x, const int y){
	p.x = x;			p.y = y;
};
//----------------------------------------------------------

//----------------------------------------------------------
void Player::SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS){				//저항값 세팅;					//추가된 코드
	resistanceXpos = RESISTANCEXPOS;
	resistanceYpos = RESISTANCEYPOS;
}
void Player::MoveTo(const long x, const long y){			//이동할 x 방향 , y 방향			//추가된 코드

	
	SpeedXpos += x;
	SpeedYpos += y;

}
void Player::Move(){										//이동							//추가된 코드

	double ResistanceXpos = 0;								//X축 저항						//추가된 코드
	double ResistanceYpos = 0;								//Y축 저항						//추가된 코드
	// 저항 발생
	
	if (SpeedXpos != 0)
		ResistanceXpos = SpeedXpos * (resistanceXpos / MAXRESISTANCE);
	if (SpeedYpos != 0)
		ResistanceYpos = SpeedYpos * (resistanceYpos / MAXRESISTANCE);

		//저항값 = 스피드 * 저항상수;
	SpeedXpos -= ResistanceXpos;
	SpeedYpos -= ResistanceYpos;
	//이동
	p.x += (long)SpeedXpos;
	p.y += (long)SpeedYpos;

	
	ObjectRect.left = p.x - ObjectSize.cx / 2;
	ObjectRect.top = p.y - ObjectSize.cy / 2;
	ObjectRect.right = p.x + ObjectSize.cx / 2;
	ObjectRect.bottom = p.y + ObjectSize.cy / 2;


}

