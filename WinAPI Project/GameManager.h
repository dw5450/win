#pragma once

#include "stdafx.h"
class GameManager{
private:
	Object** objectArray;
	Item itemStock[3];					// ������ ������ ��������
	int objectCount = 0;

public:
	GameManager();
	~GameManager();
	void startGame();			// �����Ҷ� ��� ������ �ʱ�ȭ�մϴ�.
	void draw();				// GameManager�� ��ϵ� ��� �׸��� �׸��ϴ�!
	
	void deleteObject();
	void putObject(Object* a);		// GameManager�� ������Ʈ�� �߰��մϴ�. �ִ� 255��

	// ���Ӿȿ� ���� ��ɱ��� �־�����ô�. ��������(�����Ȳ �ƴ�!!)�� ���̺�/�ε�
	void save();
	void load();
};