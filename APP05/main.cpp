#include "QueType.h"

int main() {
	// 변수 초기화
	char input[INPUT_MAX_SIZE];
	bool isPalindromes = true;
	

	// To-Do 1: INPUT_MAX_SIZE를 전달하여 QueType 변수 queue, reverseQueue초기화 
	QueType queue(INPUT_MAX_SIZE);
	QueType reverseQueue(INPUT_MAX_SIZE);


	// To-Do 3: input변수에 입력받기 
	cout << "문자열 입력: ";
	cin.getline(input, INPUT_MAX_SIZE);
	

	// To-Do 4: queue, reverseQueue에 enqueue
	for (int i = 0; i < strlen(input); i++) {
		if (48 <= input[i] && input[i] <= 57) //아라비아 숫자
			queue.Enqueue(input[i]);

		else if (65 <= input[i] && input[i] <= 90) //대문자
			queue.Enqueue(input[i]);

		else if (97 <= input[i] && input[i] <= 122) //소문자
			queue.Enqueue(input[i]);
		// 공백, 문장기호는 회문검사시 필요X
	}

	for (int i = strlen(input) - 1; i > -1; i--) {
		if (48 <= input[i] && input[i] <= 57) //아라비아 숫자
			reverseQueue.Enqueue(input[i]);

		else if (65 <= input[i] && input[i] <= 90) //대문자
			reverseQueue.Enqueue(input[i]);

		else if (97 <= input[i] && input[i] <= 122) //소문자
			reverseQueue.Enqueue(input[i]);
		// 공백, 문장기호는 회문검사시 필요X
	}

	// To-Do 5: Palindromes check 
	ItemType item, reverseItem;
	while (true) { 
		queue.Dequeue(item);
		reverseQueue.Dequeue(reverseItem);
		if (item != reverseItem) {
			if (abs(item - reverseItem) == 32) //대소문자만 다른 경우
				isPalindromes = true;
			else {
				isPalindromes = false;
				break;
			}
		}
		if (queue.IsEmpty())
			break;
		// 빠져나오는 조건은 queue의 length == 0이거나
		// dequeue한 ItemType의 값이 다른 경우
	}
	
	// 출력
	if (isPalindromes) cout << "O" << endl;
	else cout << "X" << endl;

	return 0;
}