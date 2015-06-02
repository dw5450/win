#pragma once

#include "Object.h"
#include "Item.h"
#include "Monster.h"

class Player :public Object{
private:

public:
	Player();
	Player(const long x, const long y, const SIZE size);
	~Player();
	
	void crash(Monster * MonsterPt);							//�浹 üũ (���� ������)		//����� �ڵ�
	void crash(Item * MonsterPt);								//�浹 üũ (���� ������)		//����� �ڵ�
	void crash(HWND hWnd);
	// �浹�ϸ� y������ �ϰ�? �ٶ�ũ�� ����?->�ٸ� ��ü��(������,����)�� �浹�� ���� 
	// �ٶ��� ũ�Ⱑ �����Ϸ��� private����� ���� �����ϰ��־���ҵ�. �׷��� ���� �ٲ����
	virtual void draw();

	virtual void SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS);							//�߰��� �ڵ�
	virtual void MoveTo(const long x, const long y);				//�̵��� x ���� , y ����		//�߰��� �ڵ�
	virtual void Move();											//�̵�							//�߰��� �ڵ�
	double GetSpeedXpos(){ return SpeedXpos; }						//MoveToXpos��������,����׿�	//�߰��� �ڵ�
	double GetSpeedYpos(){ return SpeedYpos; }						//MoveToYpos��������,����׿�	//�߰��� �ڵ�
	virtual	double GetResistanceXpos(){ return resistanceXpos; }	//resistanceXpos ��������		//�߰��� �ڵ�
	virtual	double GetResistanceYpos(){ return resistanceYpos; }	//resistanceXpos ��������		//�߰��� �ڵ�
	virtual RECT GetObjectRect() { return ObjectRect; }				//ObjectRect ��������			//�߰��� �ڵ�
	
	// ��ǥ���� access�ϱ� ���� �Լ���
	const POINT getPlayer();
	void putPlayer(const int x, const int y);
	
};