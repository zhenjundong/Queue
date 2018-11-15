#pragma once
class MyQueue
{
public:
	MyQueue(int capacity);
	~MyQueue();
	void clcQueue();//清空队列
	bool emptyQueue();//判空队列
	bool fullQueue();//判满队列
	int lengthQueue();
	bool inQueue(int element);//进队
	bool outQueue(int &element);//出队
	void traverseQueue();//遍历

private:
	int m_iHead;//头
	int m_iTail;//尾
	int m_iQueueCapacity;
	int m_iQueueLength;
	int *m_pQueue;//队列指针
};

