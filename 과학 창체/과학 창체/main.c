#include "Sort_Solution.h"

int main()
{
	int* Arr;
	int zero = 0;
	time_t started,ended;

	printf("������ �迭�� ������ �Է��ϼ��� : ");
	scanf("%d",&NUMBER); // �Է�
	Arr = (int*)malloc(sizeof(int) * NUMBER); //�迭 �����Ҵ�

	Randomfunction

	//OneSortStart

	//ReverseSortStart

	/*
	FILE *ArrFile; //arr_set.Sc�������� ���� �����ν�

	ArrFile = fopen("arr_set.Sc", "r");


	for (int i = 0; i < NUMBER; i++) {
		fscanf(ArrFile, "%d", &Arr[i]);
	}
	*/
	srand((unsigned int)time(NULL)); // �ð� �ʱ�ȭ
	started = clock();



	QuickSort //�� ���� ����
	
	//BubbleSort //���� ���� ����

	//InsertionSort //���� ���� ����

	//SelectSort //���� ���� ����

	//RadixSort //��� ���� ����

	//ShellSort //�� ���� ����

	//MergeSort //�պ� ���� ����
	

	ended = clock();

	int sum = ended - started;

	printf("�ɸ� �ð� : %d ms \n", sum);

	Stop

}