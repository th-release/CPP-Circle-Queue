#include<iostream>
#define MAXVALUE 101 //큐 size

using namespace std;

template<class T> class Queue {
public:
	int front;
	int rear;
	int size;
	T *values;

	Queue() { size = MAXVALUE;
		values = new T[size];
		front = 0;
		rear = 0;
	}
	~Queue() {
		delete[] values;
	}

	void push(T value) {
		if(!isFull()) {
			values[rear] = value;
			rear = (rear + 1) % size;
		}
		else cout << "큐에 데이터가 너무 많습니다." << endl;
	}

	void pop() {
		if(!empty()) front = (front + 1) % size;
		else cout << "큐에 데이터가 없습니다." << endl;
	}

	bool empty() {
		if(rear == front) return true;
		else return false;
	}

	bool isFull() {
		if((rear + 1) % size == front)  return true;
		else return false;
	}
};

template<typename T>
ostream& operator <<(ostream &out, Queue<T> &q) {
	T *temp = q.values;
	out << "앞 [ ";
	for(int i=q.front; i<q.rear; i++) {
	    out << temp[i];
	    if(i < q.rear-1) out << " | ";
	}
	out << " ] 뒤" << endl;
    return out;
}
Queue<int> q;

int qpush(int number) {
	q.push(number);
}

void qpop() {
	q.pop();
}

int main() {
	int select = 0;
	int number = 0;
	cout << "Push : 1, Pop: 2" << endl;
	while (1) {
		cin >> select;
		if (select == 1) {
			cin >> number;
			qpush(number);
			cout << q;
		} else if (select == 2) {
			qpop();
			cout << q;
		} else {
			cout << "정확한 선택을 해주세요." << endl;
		}
	}
}
