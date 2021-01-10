#include "QueType.h"

int main() {
	// ���� �ʱ�ȭ
	char input[INPUT_MAX_SIZE];
	bool isPalindromes = true;
	

	// To-Do 1: INPUT_MAX_SIZE�� �����Ͽ� QueType ���� queue, reverseQueue�ʱ�ȭ 
	QueType queue(INPUT_MAX_SIZE);
	QueType reverseQueue(INPUT_MAX_SIZE);


	// To-Do 3: input������ �Է¹ޱ� 
	cout << "���ڿ� �Է�: ";
	cin.getline(input, INPUT_MAX_SIZE);
	

	// To-Do 4: queue, reverseQueue�� enqueue
	for (int i = 0; i < strlen(input); i++) {
		if (48 <= input[i] && input[i] <= 57) //�ƶ��� ����
			queue.Enqueue(input[i]);

		else if (65 <= input[i] && input[i] <= 90) //�빮��
			queue.Enqueue(input[i]);

		else if (97 <= input[i] && input[i] <= 122) //�ҹ���
			queue.Enqueue(input[i]);
		// ����, �����ȣ�� ȸ���˻�� �ʿ�X
	}

	for (int i = strlen(input) - 1; i > -1; i--) {
		if (48 <= input[i] && input[i] <= 57) //�ƶ��� ����
			reverseQueue.Enqueue(input[i]);

		else if (65 <= input[i] && input[i] <= 90) //�빮��
			reverseQueue.Enqueue(input[i]);

		else if (97 <= input[i] && input[i] <= 122) //�ҹ���
			reverseQueue.Enqueue(input[i]);
		// ����, �����ȣ�� ȸ���˻�� �ʿ�X
	}

	// To-Do 5: Palindromes check 
	ItemType item, reverseItem;
	while (true) { 
		queue.Dequeue(item);
		reverseQueue.Dequeue(reverseItem);
		if (item != reverseItem) {
			if (abs(item - reverseItem) == 32) //��ҹ��ڸ� �ٸ� ���
				isPalindromes = true;
			else {
				isPalindromes = false;
				break;
			}
		}
		if (queue.IsEmpty())
			break;
		// ���������� ������ queue�� length == 0�̰ų�
		// dequeue�� ItemType�� ���� �ٸ� ���
	}
	
	// ���
	if (isPalindromes) cout << "O" << endl;
	else cout << "X" << endl;

	return 0;
}