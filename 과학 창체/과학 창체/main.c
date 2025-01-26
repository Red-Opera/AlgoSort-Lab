#include "Sort_Solution.h"

int main()
{
	int* Arr;
	int zero = 0;
	time_t started,ended;

	printf("정렬할 배열의 갯수를 입력하세요 : ");
	scanf("%d",&NUMBER); // 입력
	Arr = (int*)malloc(sizeof(int) * NUMBER); //배열 동적할당

	Randomfunction

	//OneSortStart

	//ReverseSortStart

	/*
	FILE *ArrFile; //arr_set.Sc파일으로 부터 파일인식

	ArrFile = fopen("arr_set.Sc", "r");


	for (int i = 0; i < NUMBER; i++) {
		fscanf(ArrFile, "%d", &Arr[i]);
	}
	*/
	srand((unsigned int)time(NULL)); // 시간 초기화
	started = clock();



	QuickSort //퀵 정렬 시작
	
	//BubbleSort //버블 정렬 시작

	//InsertionSort //삽입 정렬 시작

	//SelectSort //선택 정렬 시작

	//RadixSort //기수 정렬 시작

	//ShellSort //셀 정렬 시작

	//MergeSort //합병 정렬 시작
	

	ended = clock();

	int sum = ended - started;

	printf("걸린 시간 : %d ms \n", sum);

	Stop

}