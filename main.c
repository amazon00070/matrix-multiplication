#include<stdio.h>
void print_juzhen(int a[], int hang, int lie);
void juzhenchengfa(int a[], int b[], int c[], int hang, int lie);
void main(void)
{
	int a[2][3] =
	{
		{1,2,3},
		{4,5,6}
	};
	int b[3][2] =
	{
		{1,2},
		{3,4},
		{5,6}
	};
	int c[2][2];
	int d[3][3];
	printf("矩阵a\n");
	print_juzhen(a, 2, 3);
	printf("x乘矩阵b\n");
	print_juzhen(b, 3, 2);
	printf("结果为矩阵c\n");
	juzhenchengfa(a, b, c, 2, 3);
	print_juzhen(c, 2, 2);


	printf("\n/*~~~~~~~~~~~~~*/\n\n");


	printf("矩阵b\n");
	print_juzhen(b, 3, 2);
	printf("x乘矩阵a\n");
	print_juzhen(a, 2, 3);
	printf("结果为矩阵d\n");
	juzhenchengfa(b, a, d, 3, 2);
	print_juzhen(d, 3, 3);
}
//打印矩阵
void print_juzhen(int a[], int hang, int lie)
{
	for (int i = 0; i < hang; i++)
	{
		for (int j = 0; j < lie; j++)
		{
			printf("%d\t", a[j + (i * lie)]);
		}
		printf("\n");
	}
}
//矩阵的点乘
void juzhenchengfa(int a[], int b[], int c[], int hang, int lie)//表示c[hang][hang] = a[hang][lie] x b[lie][hang]
{
	for (int i = 0; i < hang; i++)//行循环
	{
		for (int j = 0; j < hang; j++)//列循环
		{
			int mid = 0;
			for (int k = 0; k < lie; k++)//向量内积循环
			{
				mid = mid + a[k + (i * lie)] * b[j + (k * hang)];
			}
			c[(i * hang) + j] = mid;
		}
	}
}
