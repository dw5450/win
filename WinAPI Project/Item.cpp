#include "stdafx.h"

#define SIZE 100								// ������ ������Ʈ�� �ʻ󿡼��� ������. ������ �����Ұ�.

Item::Item(){};

Item::Item(const int x, const int y, const int type){
	p.x = x;	p.y = y;
	itemType = type;
};
Item::~Item(){};

void Item::draw(){
	// �׽�Ʈ��
	MoveToEx(hdc, p.x, p.y, NULL);
	LineTo(hdc, p.x + SIZE, p.y + SIZE);
};
void Item::crash(){
	//if (itemStockCounter < 3){		
	//	MoveToEx(hdc, p.x, p.y,NULL);				// �׽�Ʈ��->���忡 �߰��� �κ�
	//	LineTo(hdc, p.x + SIZE, p.y + SIZE);
	//}

	Item::~Item();									// �����ϵ簡 ��ǥ�� �ָ� �����簡.
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

// �� �Ʒ��δ� ������ �� ��� ����

void Item::SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS){				//���װ� ����;					//�߰��� �ڵ�

}
void Item::MoveTo(const long x, const long y){			//�̵��� x ���� , y ����			//�߰��� �ڵ�

}
void Item::Move(){										//�̵�							//�߰��� �ڵ�


}
