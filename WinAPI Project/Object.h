#pragma once

#include <Windows.h>
#include "Math.h"									//�߰��� ���� 
#define MAXRESISTANCE (long)100.0								// ���� �ִ밪						//�߰��� ������
// �߻� Ŭ����(�������̽�)
class Object{
public:
	POINT p;
	SIZE ObjectSize;
	RECT ObjectRect;

	double resistanceXpos = 0;							//���װ�								//�߰��� �ڵ�
	double resistanceYpos = 0;							//���װ�								//�߰��� �ڵ�
	double SpeedXpos = 0;								//���� X�� ���� ���ǵ�				//�߰��� �ڵ�			
	double SpeedYpos = 0;								//���� Y�� ���� ���ǵ�				//�߰��� �ڵ�	

	Object(){};
	//POINT GetObjectPoint(){ return p};					//������Ʈ�� ��ǥ�� ���ؿɴϴ�.

	virtual void SetResistance(long RESISTANCEXPOS, long RESISTANCEYPOS) = 0;		//���װ� ����;					//�߰��� �ڵ�
	virtual void MoveTo(const long x, const long y) = 0;	//�̵��� x ���� , y ����		//�߰��� �ڵ�
	virtual void Move() = 0;								//�̵�							//�߰��� �ڵ�
	virtual	double GetResistanceXpos() = 0;					//resistanceXpos ��������		//�߰��� �ڵ�
	virtual	double GetResistanceYpos() = 0;					//resistanceXpos ��������		//�߰��� �ڵ�
	virtual RECT GetObjectRect() = 0;

	virtual ~Object(){};

	//ũ������ ĳ���Ͱ� ��� ó���ϰ� �ٲ�
	//virtual void crash() = 0;	// ������Ʈ�� �浹������ �÷��̾�� �Ⱦ�������, �ٸ��� ������->���� �ٸ� crash�� ���� -> ������ ������ ���� �����Լ�
	virtual void draw() = 0;			// ��ü�� �׸��ϴ�.
};