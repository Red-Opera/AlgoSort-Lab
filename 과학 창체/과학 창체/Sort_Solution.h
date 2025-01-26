#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#pragma comment (lib, "winmm.lib")

#define QuickSort quick(Arr,zero,NUMBER-1); //�� ���� ���� ���� (�迭,����, ������ �ε���)
#define BubbleSort Bubble(Arr, &NUMBER); //���� ���� ���� ���� (�迭, ����)
#define RadixSort Radix(Arr, &NUMBER); //��� ���� ���� ���� (�迭, ����)
#define SelectSort Select_Sort(Arr, &NUMBER); //���� ���� ���� ���� (�迭, ����)
#define InsertionSort Insertion_Sort(Arr, &NUMBER); //���� ���� ���� ���� (�迭, ����)
#define ShellSort Shell(Arr, &NUMBER); //�� ���� ���� ���� (�迭, ����)
#define MergeSort merge(Arr, &NUMBER); //���� ���� ���� ���� (�迭, ����)
#define Randomfunction Random(Arr, &NUMBER);
#define OneSortStart OneSort(Arr, &NUMBER);
#define ReverseSortStart reverse(Arr, &NUMBER);
#define swap(type,x,y) do{ type t=x;x=y;y=t;} while(0)

#define Stop system("pause"); // ���� ����

static int *buff; //���� ���� ���� �ʼ��� int�� ���� �迭 ����

clock_t end; //����: ���۽ð��� �����ð�
int NUMBER; //�迭 ����

static void __mergesort(int arr[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		int p = 0, j = 0, i, k = left;

		__mergesort(arr, left, center);
		__mergesort(arr, center + 1, right);
		for (i = left; i <= center; i++)
		{
			buff[p++] = arr[i];
		}
		while (i <= right &&j < p)
			arr[k++] = (buff[j] <= arr[i]) ? buff[j++] : arr[i++];
		while (j < p)
			arr[k++] = buff[j++];


	}
}

void quick(int arr[], int left,int right) 
{
	int pl = left, pr = right,pivot = arr[(pl+pr)/2];

	do
	{
		while (arr[pl] < pivot) pl++;
		while (arr[pr] > pivot) pr--;

		if (pl <= pr)
		{
			swap(int, arr[pl], arr[pr]);
			pl++;
			pr--;
		}
	} while (pl <= pr);
	
	if(left< pr) quick(arr, left, pr);
	if (pr < right - 1) quick(arr, pl, right);
}

void Select_Sort(int arr[], int *NUMBER) //���� ���� �Լ�
{
	int Sort_Start = 0; //���� ����

	while (Sort_Start < *NUMBER)  //�Է� ������ ���� �ϴ� �κк��� ���� ���
	{
		int Small_Vaule = Sort_Start;
		int Recent_Vaule = Sort_Start + 1;

		while (Recent_Vaule < *NUMBER)
		{
			if (arr[Recent_Vaule] < arr[Small_Vaule])
			{
				Small_Vaule = Recent_Vaule;
			}
			Recent_Vaule++;
		}

		if (Small_Vaule != Sort_Start) //��ġ �ٲٱ�
		{
			int Change_Vaule = arr[Sort_Start];
			arr[Sort_Start] = arr[Small_Vaule];
			arr[Small_Vaule] = Change_Vaule;
		}
		Sort_Start++;
	}
	
} 

void Bubble(int arr[], int *NUMBER) //���� ���� �Լ�
{
	int Last_Sort = *NUMBER - 1; //������ ����

	while (Last_Sort >= 0)
	{
		int Recent_Vaule = 0;

		while (Recent_Vaule != Last_Sort)
		{
			if (arr[Recent_Vaule] > arr[Recent_Vaule + 1]) //��ġ �ٲٱ�
			{
				int Change_Vaule = arr[Recent_Vaule];
				arr[Recent_Vaule] = arr[Recent_Vaule + 1];
				arr[Recent_Vaule + 1] = Change_Vaule;
			}
			Recent_Vaule++;
		}
		Last_Sort--;

	}
}

void Insertion_Sort(int arr[], int *NUMBER) //���� ���� �Լ�
{
	int Last_Sort = 0;

	while (Last_Sort < *NUMBER)
	{
		int Recent_Vaule = Last_Sort;
		while (Recent_Vaule >= 1)
		{
			if (arr[Recent_Vaule - 1] > arr[Recent_Vaule]) //��ġ �ٲٱ�
			{
				int Change_Vaule = arr[Recent_Vaule-1];
				arr[Recent_Vaule-1] = arr[Recent_Vaule];
				arr[Recent_Vaule] = Change_Vaule;
			}
			else {
				Recent_Vaule = 1;
			}
			Recent_Vaule--;
		}
		Last_Sort++;
	}
}

void Radix(int arr[], int *NUMBER) //��� ���� �Լ�
{
	int store = 1, count = 1, next = 0, Temporarily[100000];

	for (int i = 0; (next == 0) && (store == 1); i++)
	{
		store--;

		for (int j = 0; ((((arr[j] / count) % 10) >= 1) || (double)(arr[j] / count) >= 1) && (arr[j] >= 0); j++)
		{
			next++;
			if (next == 1)
			{
				break;
			}

		}

		if (next != 0)
		{
			while (next > 0)
			{
				int bucket[10] = { 0 };

				for (i = 0; i < *NUMBER; i++)
					bucket[arr[i] / count % 10]++;

				for (i = 1; i < 10; i++)
					bucket[i] += bucket[i - 1];

				for (i = *NUMBER - 1; i >= 0; i--)
					Temporarily[--bucket[arr[i] / count % 10]] = arr[i];

				for (i = 0; i < *NUMBER; i++)
					arr[i] = Temporarily[i];

				count *= 10;


				for (int i = 0; i < *NUMBER; i++)
				{
					if (arr[i] > arr[i + 1])
					{
						store = 1;
						break;
					}
				}
				if (store = 1)
				{
					store = 1;
					break;
				}
			}
			next--;
		
		}

		
	}
}

void Shell(int arr[], int *NUMBER) //�� ���� �Լ�
{
	int i, j, k; //for���� ����� ���� ����

	for (k = *NUMBER / 2; k > 0; k /= 2)
	{
		for (j = k; j < *NUMBER; j++)
		{
			int tmp = arr[j];
			for (i = j - k; i >= 0 && arr[i] > tmp; i -= k)
			{
				arr[i + k] = arr[i];
			}

			arr[i + k] = tmp;
		}
	}
}

int merge(int arr[], int *NUMBER)
{
	if ((buff = calloc(*NUMBER, sizeof(int))) == NULL)
		return -1;
	__mergesort(arr, 0, *NUMBER - 1);
	free(buff);
	return 0;
}


int *OneSort(int arr[], int *NUMBER)
{

	int Ran;

	for (int i = 0; i < *NUMBER; i++) 
	{
		arr[i] = 1;
	}

	Ran = (rand() % *NUMBER) + 1; //1���� ������ ���� ��ŭ �������� ������

	arr[Ran] = 2;

	return arr; //���� �迭 ��ȯ
}


int *Random(int arr[], int *NUMBER)
{
	for (int i = 0; i < *NUMBER; i++) //���� �Է�
	{
		arr[i] = (rand() % *NUMBER) + 1; //1���� ������ ���� ��ŭ �������� ������
		
	}
	return arr; //���� �迭 ��ȯ
}

int reverse(int arr[], int *NUMBER)
{
	for (int i = 0; i < *NUMBER; i++) //���� �Է�
	{
		arr[i] = *NUMBER - i;
	}

	return arr;

}


/*for (int i = 0; i < *NUMBER; i++) //������ ��� ���
{
	printf("%d ", arr[i]);
	if (i == (*NUMBER - 1))
	{
		printf("\n");
	}
}
*/