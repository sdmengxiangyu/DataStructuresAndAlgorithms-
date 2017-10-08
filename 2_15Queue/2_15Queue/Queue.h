//˳��Queue
//���ζ��У���tag��ʾ���п��벻�գ���ʱ����front==rear��Ϊ������־

#include<iostream>
using namespace std;

#ifndef QUEUE
#define QUEUE

template<class T>class Queue{
private:
	int maxSize;	//�������ֵ
	int front;	//��ͷλ���±�
	int rear;	//��βλ���±�
	int tag;	//������п��벻��
	T *queue;	//���T�������ݵ�����
public:
	Queue(int size = 5){
		maxSize = size ;	
		queue = new T[maxSize];
		front = rear = 0;
		tag = 0;	//��ʾ���п�
	}
	~Queue(){
		delete[] queue;
	}
	void Clear(){
		front = rear;	//��ն��У�����������
	}
	bool EnQueue(T item);	//��ӣ���β������Ԫ��
	bool DeQueue(T& item);	//���ӣ�ȡ����һ��Ԫ�أ���ɾ����������ɾ����
	bool GetFront(T& item);	//��ȡ��ͷ����ɾ��
};

#endif

template<class T>bool Queue<T>::EnQueue(T item){
	if (front == rear&&tag==1){
		cout << "��������\n";	return false;
	}
	tag = 1;
	queue[rear] = item;
	rear = (rear + 1) % maxSize;
	return true;
	//if ((rear + 1) % maxSize == front){
	//	//����Ҳ������Զ��������ѹջ����
	//	/*T *newQueue = new T[maxSize * 2];
	//	for (int i = 0; i < maxSize - 1; i++){
	//	newQueue[i] = queue[i];
	//	}
	//	maxSize *= 2;
	//	delete[] queue;
	//	queue = newQueue;*/

	//	cout << "��������" << endl;
	//	return false;
	//}
	//queue[rear] = item;		//˵��rear�ȴ�������û��Ԫ�ص�
	//rear = (rear + 1) % maxSize;
	//return true;
}

//���Ӻ�������Ƿ�Ϊ��,���ı��tag
template<class T>bool Queue<T>::DeQueue(T& item){
	if (tag==0){
		cout << "����Ϊ��\n";	return false;
	}
	item = queue[front];
	front = (front + 1) % maxSize;
	if (front == rear)
		tag = 0;	//���Ӻ�front������rear,˵�������ѿ�
	return true;
}
template<class T>bool Queue<T>::GetFront(T& item){
	if (tag==0){
		cout << "����Ϊ��\n";	return false;
	}
	item = queue[front];	return true;
}