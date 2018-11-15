#include "pch.h"
#include "MyQueue.h"
#include <iostream>
using namespace std;

MyQueue::MyQueue(int capacity)
{
	m_iQueueCapacity = capacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLength = 0;
	m_pQueue = new int[m_iQueueCapacity];
}


MyQueue::~MyQueue()
{
	delete []m_pQueue;
	m_pQueue = NULL;
}

void MyQueue::clcQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLength = 0;
}

bool MyQueue::emptyQueue()//�п�
{
	return m_iQueueLength == 0 ? true : false;
}

int MyQueue::lengthQueue()
{
	return m_iQueueLength;
}

bool MyQueue::fullQueue()//���Ⱥ�������ͬ
{
	return m_iQueueCapacity == m_iQueueLength ? true : false;
}

bool MyQueue::inQueue(int element)//����
{
	//��һ��������
	if(fullQueue())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity;///����һ��ѭ�����У�������������Ҫ
		m_iQueueLength++;//���г�����Ҫ����������������
		return true;
	}
}

bool MyQueue::outQueue(int &element)//���ӣ����ú���Ҫ
{
	//��һ���ж϶����ǹ�Ϊ��
	if (fullQueue())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity;//����һ��ѭ�����У�������������Ҫ
		m_iQueueLength--;//���г�����Ҫ����������������
		return true;
	}
}

void MyQueue::traverseQueue()//������
{
	for (int i = m_iHead;i < m_iQueueLength + m_iHead;i++)//��ͷ��ʼ����
	{
		i = i % m_iQueueCapacity;//ѭ������Ҫȡ�డ��������
		cout << m_pQueue[i] << endl;
	}
	cout << endl;
}