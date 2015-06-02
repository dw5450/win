#pragma once

#include "Object.h"

class Monster :public Object{
private:

	int size;
	int monsterType;				// ���͵鵵 ���� �������� Ŭ������ ����°� �����Ͱ����� ���� ������ ����͵� �ƴϰŴϿ� ���� �������� �ٸ� �ൿ�� ���� �ʴ´�(�Ƹ���).
									// ����, ���͸��� �ѹ��� �ٿ��� �����ϴ°� �� ����.
public:
	Monster();
	Monster(const long x, const long y, const SIZE size, const int type);
	~Monster();

	virtual void draw();

	virtual void SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS);
	virtual void MoveTo(const long x, const long y);				//�̵��� x ���� , y ����			//�߰��� �ڵ�
	virtual void Move();											//�̵�							//�߰��� �ڵ�
	virtual	double GetResistanceXpos(){ return resistanceXpos; }	//resistanceXpos ��������		//�߰��� �ڵ�
	virtual	double GetResistanceYpos(){ return resistanceYpos; }	//resistanceXpos ��������		//�߰��� �ڵ�
	virtual RECT GetObjectRect() { return ObjectRect; }				//ObjectRect ��������			//�߰��� �ڵ�

	// ��ǥ���� access�ϱ� ���� �Լ���
	const POINT getMonster();
	void putMonster(const int x, const int y);

	void move();				// ���� �̵������� ����°͵� ����������. ~ ������� �����δٰų�.
};