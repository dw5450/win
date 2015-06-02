#include "stdafx.h"

										// 100 �κ��� ���ϴ°����� �ٲ۴�. �ҳ��� ũ��. -> ���� ��������� �������� �ʴ� ������ �ϳ��� ���⶧��.
											// ��ǵ��� �ٲܰŸ� ��������� �����ؾ߰���. �ٵ� ������		//�����Ѵ� �ֳĸ� �ϰ�ͱ� �����̴�! ������
Player::Player(const long x, const long y, const SIZE size){			//int -> long�� ����ȯ �Ͼ�⿡ ���ʿ� long������ ����
	p.x = x;			p.y = y;
	ObjectSize = size;
	ObjectRect.left = x - size.cx / 2;
	ObjectRect.top = y - size.cy / 2;
	ObjectRect.right = x + size.cx / 2;
	ObjectRect.bottom = y + size.cy / 2;

};
Player::~Player(){};



void Player::crash(Monster * MonsterPt){	//�浹 üũ (���� ������)		//����� �ڵ�
	RECT rcTemp;							//�ε��� ���� ����				//�߰��� ����
	if (IntersectRect(&rcTemp, &ObjectRect, &(MonsterPt->GetObjectRect())))
	{
		Ellipse(hdc, rcTemp.left, rcTemp.top, rcTemp.right, rcTemp.bottom);
	}

}

void Player::crash(Item * Item){			//�浹 üũ (������ ������)		//����� �ڵ�

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
void Player::draw(){									//���װ� ���� ��ġ��

	//�׸��� �κ�

	Rectangle(hdc, ObjectRect.left, ObjectRect.top,
		ObjectRect.right, ObjectRect.bottom);

	

	/*else if (MoveToYpos < 0)
		MoveToYpos = 0;*/

		// �׽�Ʈ��

};

//-----------��ǥ���� access�ϱ� ���� �Լ���--------------
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
void Player::SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS){				//���װ� ����;					//�߰��� �ڵ�
	resistanceXpos = RESISTANCEXPOS;
	resistanceYpos = RESISTANCEYPOS;
}
void Player::MoveTo(const long x, const long y){			//�̵��� x ���� , y ����			//�߰��� �ڵ�

	
	SpeedXpos += x;
	SpeedYpos += y;

}
void Player::Move(){										//�̵�							//�߰��� �ڵ�

	double ResistanceXpos = 0;								//X�� ����						//�߰��� �ڵ�
	double ResistanceYpos = 0;								//Y�� ����						//�߰��� �ڵ�
	// ���� �߻�
	
	if (SpeedXpos != 0)
		ResistanceXpos = SpeedXpos * (resistanceXpos / MAXRESISTANCE);
	if (SpeedYpos != 0)
		ResistanceYpos = SpeedYpos * (resistanceYpos / MAXRESISTANCE);

		//���װ� = ���ǵ� * ���׻��;
	SpeedXpos -= ResistanceXpos;
	SpeedYpos -= ResistanceYpos;
	//�̵�
	p.x += (long)SpeedXpos;
	p.y += (long)SpeedYpos;

	
	ObjectRect.left = p.x - ObjectSize.cx / 2;
	ObjectRect.top = p.y - ObjectSize.cy / 2;
	ObjectRect.right = p.x + ObjectSize.cx / 2;
	ObjectRect.bottom = p.y + ObjectSize.cy / 2;


}

