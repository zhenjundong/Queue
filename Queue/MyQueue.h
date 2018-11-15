#pragma once
class MyQueue
{
public:
	MyQueue(int capacity);
	~MyQueue();
	void clcQueue();//��ն���
	bool emptyQueue();//�пն���
	bool fullQueue();//��������
	int lengthQueue();
	bool inQueue(int element);//����
	bool outQueue(int &element);//����
	void traverseQueue();//����

private:
	int m_iHead;//ͷ
	int m_iTail;//β
	int m_iQueueCapacity;
	int m_iQueueLength;
	int *m_pQueue;//����ָ��
};

