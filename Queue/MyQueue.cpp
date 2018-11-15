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

bool MyQueue::emptyQueue()//判空
{
	return m_iQueueLength == 0 ? true : false;
}

int MyQueue::lengthQueue()
{
	return m_iQueueLength;
}

bool MyQueue::fullQueue()//长度和容量相同
{
	return m_iQueueCapacity == m_iQueueLength ? true : false;
}

bool MyQueue::inQueue(int element)//进队
{
	//第一步是判满
	if(fullQueue())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity;///这是一个循环队列！！！！！很重要
		m_iQueueLength++;//队列长度需要操作！！！！！！
		return true;
	}
}

bool MyQueue::outQueue(int &element)//出队！引用很重要
{
	//第一步判断队列是够为空
	if (fullQueue())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity;//这是一个循环队列！！！！！很重要
		m_iQueueLength--;//队列长度需要操作！！！！！！
		return true;
	}
}

void MyQueue::traverseQueue()//遍历！
{
	for (int i = m_iHead;i < m_iQueueLength + m_iHead;i++)//从头开始遍历
	{
		i = i % m_iQueueCapacity;//循环队列要取余啊！！！！
		cout << m_pQueue[i] << endl;
	}
	cout << endl;
}