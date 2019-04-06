#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#define PI   3.1415926
#define a    0.025
#define step 1
double velo(double v1, double v2, double v3, double v4, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x, int y,double c[10]);
double ray_tracing_recieve(int x0, double angle, double z, double l[100], double c[10], double(*v)[1000]);
double ray_tracing_time(double x0, double tan, double z, double x);
void main()
{
	int i, j, k, i1, j1, i2, j2, i3, j3, i4, j4,x,y; 
	double d_x, d_angle;
	//定义真实模型和初始模型数组
	double V_real[550][1000], V_init[550][1000];
	//int size = 1000;
	//int(*p)[50] = new int[size][50];
	double c_init[10], c_real[10], L[100];
	//构建真实速度模型
	for (i = 0; i <= 1000; i++)
	{
		for (j = 0; j <= 1000; j++)
		{
			if (i == 0 && j == 0)
			{
				V_real[i][j] = 2000;
				i1 = i, j1 = j;
			}
			if (i == 500 && j == 0)
			{
				V_real[i][j] = 2800;
				i2 = i, j2 = j;
			}
			if (i == 0 && j == 400)
			{
				V_real[i][j] = 2600;
				i3 = i, j3 = j;
			}
			if (i == 500 && j == 400)
			{
				V_real[i][j] = 2100;
				i4 = i, j4 = j;
			}
		}
	}
	printf("real velocity-model area %d,%d,%d,%d\n\n", i1, j1, i4, j4);
	for (j = j1; j <= j4; j++)
		for (i = i1; i <= i4; i++)
	{
		V_real[i][j] = velo(V_real[i1][j1], V_real[i2][j2], V_real[i3][j3], V_real[i4][j4], i1, j1, i2, j2, i3, j3, i4, j4,i,j,c_real);
		printf(" %d ,%d    %-10f    ",i,j,V_real[i][j]);
		//if (i % 100 == 0 && i!=0 )
			//printf("\n");
	}
	FILE *fp;
	if ((fp = fopen("real_vel.dat", "w")) != NULL)
	{
		for (i = 0; i < i4; i++)
		{
			for (j = 0; j < j4; j++)+
				fprintf(fp, "%f\n", V_real[i][j]);
		}
		fclose(fp);
	}
	//观测系统定义
	int x1 = 10, x2 = 15, x3 = 20, x4 = 25, x5 = 30;
	double angle = 30.0;
	double X1, X2, X3, X4, X5, t1, t2, t3, t4, t5,t0[100];
	//真实模型射线追踪
	printf("the 1st ray\n");
	X1=ray_tracing_recieve(x1, angle, j4, L, c_real, V_real);
	//t0[0] = ray_tracing_time(x1,angle,j4,x1);
	//printf("the 2nd ray\n");
	//X2 = ray_tracing_recieve(x2, angle, j4);
	//t0[1] = ray_tracing_time(x2, angle, j4, x1);
	//printf("the 3rd ray\n");
	//X3 = ray_tracing_recieve(x3, angle, j4);
	//t0[2] = ray_tracing_time(x3, angle, j4, x1);
	//printf("the 4th ray\n");
	//X4 = ray_tracing_recieve(x4, angle, j4);
	//t0[3] = ray_tracing_time(x4, angle, j4, x1);
	//printf("the 5th ray\n");
	//X5 = ray_tracing_recieve(x5, angle, j4);
	//t0[4] = ray_tracing_time(x5, angle, j4, x1);
	
	//初始模型定义
	double v1, v2, v3, v4;
	v1 = 2000;
	v2 = 2300;
	v3 = 2500;
	v4 = 2700;
	for (x = 0; x <= 1000; x++)
	{
		for (y = 0; y <= 1000; y++)
		{
			if (x == 0 && y == 0)
			{
				V_init[x][y] = v1;
				i1 = x, j1 = y;
			}
			if (x == 300 && y == 0)
			{
				V_init[x][y] = v2;
				i2 = x, j2 = y;
			}
			if (x == 0 && y == 500)
			{
				V_init[x][y] = v3;
				i3 = x, j3 = y;
			}
			if (x == 300 && y == 500)
			{
				V_init[x][y] = v4;
				i4 = x, j4 = y;
			}
		}
	}
	printf("\n initial velocity-model area %d,%d,%d,%d\n\n", i1, j1, i4, j4);
	for (j = j1; j <= j4; j++)
		for (i = i1; i <= i4; i++)
		{
			V_init[i][j] = velo(V_init[i1][j1], V_init[i2][j2], V_init[i3][j3], V_init[i4][j4], i1, j1, i2, j2, i3, j3, i4, j4, i, j,c_init);
			//printf("     %-10f    ",V_real[i][j]);
		}
	if ((fp = fopen("init_vel.dat", "w")) != NULL)
	{	
		for (i = 0; i < i4; i++)
		{
			for (j = 0; j < j4; j++)
				fprintf(fp, "%f\n", V_init[i][j]);
		}
		fclose(fp);
	}
	/*
	//求残差
	double C, C_t[100], T_z[100], C_z[100],z[1000];
	for (i = 0; i <= 100; i++)
	{
		C_z[i] = 1.0;
	}
	//梯度下降，最优化迭代
	for (k = 0; C_z[i] != 0.0; k++)
	{
		//初始模型射线追踪
		double X11, X22, X33, X44, X55, t[100],Delta=0.0;
		printf("the 1st ray\n");
		//X11 = ray_tracing_recieve(x1, tan_angle, j4);
		t[0] = ray_tracing_time(x1, angle, j4, x1);
		printf("the 2nd ray\n");
		///X22 = ray_tracing_recieve(x2, tan_angle, j4);
		t[1] = ray_tracing_time(x2, angle, j4, x1);
		printf("the 3rd ray\n");
		//X33 = ray_tracing_recieve(x3, tan_angle, j4);
		t[2] = ray_tracing_time(x3, angle, j4, x1);
		printf("the 4th ray\n");
		//X44 = ray_tracing_recieve(x4, tan_angle, j4);
		t[3] = ray_tracing_time(x4, angle, j4, x1);
		printf("the 5th ray\n");
		//X55 = ray_tracing_recieve(x5, tan_angle, j4);
		t[4] = ray_tracing_time(x5, angle, j4, x1);
		//深度残差
		for (i = 0; i <= 4;i++)
		{
			C_t[i] = t[i] - t0[i]; printf("偏C/偏T = %f\n", C_t[i]);
			T_z[i] = 2 * (1 / (sqrt(tan(angle)*tan(angle) + 1))) / 2000.0; printf("偏T/偏Z = %f\n", T_z[i]);
			C_z[i] = C_t[i] * T_z[i]; printf("偏C/偏Z = %f\n\n", C_z[i]);
			if (C_z[i] > 0)
			{
				Delta -= step*C_z[i];
			}
			if (C_z[i] < 0)
			{
				Delta += step*(0-C_z[i]);
			}
		}
		j4 = j4 + (Delta/ 5);
		z[k] = j4;
		//速度残差
		//(时间对速度积分，四个点速度迭代次序？
		//					1、单点迭代出准确速度值再决定下一个？
		//					2、四点速度均修正为一次迭代
		//左上角速度

		printf("第%d次迭代", k+1);
		printf("this time j4=%d\n", j4);
		for (x = 0; x <= 1000; x++)
		{
			for (y = 0; y <= 1000; y++)
			{
				if (x == 0 && y == 0)
				{
					V_init[x][y] = v1;
					i1 = x, j1 = y;
				}
				if (x == 500 && y == 0)
				{
					V_init[x][y] = v2;
					i2 = x, j2 = y;
				}
				if (x == 0 && y == j4)
				{
					V_init[x][y] = v3;
					i3 = x, j3 = y;
				}
				if (x == 500 && y == j4)
				{
					V_init[x][y] = v4;
					i4 = x, j4 = y;
				}
			}
		}
		if ((fp = fopen("vel.dat", "w")) != NULL)
		{
			for (i = 0; i < i4; i++)
			{
				for (j = 0; j < j4; j++)
					fprintf(fp, "%f\n", V_initl[i][j]);
			}
			fclose(fp);
		}
		//getchar();
			if (abs(z[k-1] - z[k]) < 0.001)
				break;
	}*/
	getchar();
}
static double velo(double v1,double v2,double v3,double v4,int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x,int y,double c[10])
{
	double c1, c2, c3, c4, c5, c6, c7;
	double s1, s2, b1, b2;
	double V;
	s1 = (y1 - y2) / (x1 - x2);
	s2 = (y3 - y4) / (x3 - x4);
	b1 = y1 - s1*x1;
	b2 = y3 - s2*x3;
	c1 = s2*(x2*v1 - x1*v2) + b2*(v2 - v1) - s1*(x2*v3 - x1*v4) - b1*(v4 - v3);		c[0] = c1;
	c2 = s2*(v2 - v1) - s1*(v4 - v3);												c[1] = c2;
	c3 = x1*v2 - x2*v1 + x2*v3 - x1*v4;												c[2] = c3;
	c4 = v1 - v2 + v4 - v3;															c[3] = c4;
	c5 = b2*(x2*v1 - x1*v2) - b1*(x2*v3 - x1*v4);									c[4] = c5;
	c6 = (s2 - s1)*(x2 - x1);														c[5] = c6;
	c7 = (b2 - b1)*(x2 - x1);														c[6] = c7;
	V = (c1*x + c2 * pow(double(x), 2) + c3*y + c4*x*y+c5) / (c6*x + c7);
	return V;
}
double ray_tracing_recieve(int x0, double angle, double z, double T[100], double c[10],double (*v)[1000])
{
	int i;
	double d_x=0.0,d_z,d_angle=0.1;	
	double x = x0;
	double y = 0.0, H[1200];
	double l=0,t=0,t_sum=0;
	H[0] = 0.0;
	
	for (i = 0; i <= 6; i++)
	{
		printf("C%d=%f\n", i,c[i]);
	}

	//射线追踪(求接收点）
	for (i = 0; i<=((z / step) * 2)+2; i++)
	{
		/*if (y==400)
		{
			H[i] = y;
			H[i] -= 1; printf("123131331221313\n");
		}
		else
		{ */
			H[i] = y;
			//printf("z=%f", H[i]);			//在外面赋值才能判断
		if (tan(angle*PI / 180) < 1 )
		{
			d_x = step*tan(angle*PI / 180);
			//printf("\n%f\n", d_x);
			if (H[i] == 0 && i == 0)
			{
				y += step;
				x += d_x;
				//H[i] = y;
				printf("init angle=%f\n", d_angle);
				//angle += d_angle;
			}
			else
			{
				if (H[i] - H[i - 1] > 0)
				{
					//increment
					y += step;
					x += d_x;
					//time
					l = sqrt(step*step + d_x*d_x); 
					t = l / v[int(x)][int(i*step)]; 
					printf("\n go \n");
					printf("\nl=%f\nt=%f\n", l, t);
					t_sum += t;
					//H[i] = y;
					//printf("\n V=%f \n x=%d, z=%d \n", v[int(x)][int(i*step)],int(x),int(step*i));
					d_angle = 
						step*((((c[2] + c[3] * x) / (c[5] * x + c[6]))*tan(angle) -
						(c[3] * c[6] * y + c[1] * c[6] * x + c[0 ] * c[6] + 2 * c[0] * c[5] * x + 2 * c[1] * c[5] * x*x + c[3] * c[5] * x*y + c[2] * c[5] * y + c[3] * c[5] * y + c[4] * c[5]) /
						((c[5] * x + c[6])*(c[5] * x + c[6]))) / v[int(x)][int(i*step)]);
					//printf("front%f\n", d_angle);
					angle += d_angle;
				}
				if (H[i]==z || H[i] - H[i - 1] < 0)
				{
					y -= step;
					x += d_x;
					l = sqrt(step*step + d_x*d_x);
					t = l / v[int(x)][int(2 * z - i*step)]; 
					printf("\n back \n");
					printf("\nl=%f\nt=%f\n", l, t);
					t_sum += t;
					//H[i] = y;
					d_angle = 
						step*((((c[2] + c[3] * x) / (c[5] * x + c[6]))*tan(angle) -
						(c[3] * c[6] * y + c[1] * c[6] * x + c[0] * c[6] + 2 * c[0] * c[5] * x + 2 * c[1] * c[5] * x*x + c[3] * c[5] * x*y + c[2] * c[5] * y + c[3] * c[5] * y + c[4] * c[5]) /
						((c[5] * x + c[6])*(c[5] * x + c[6]))) / v[int(x)][int(2 * z - i*step)]);
					//printf("\n V=%f \n x=%d, z=%d \n", v[int(x)][int(2 * z - i*step)], int(x), int(2 * z - i*step));
					//printf("forward%f\n", d_angle);
					angle += d_angle;
					if (y == 0)
						break;
				}
			}
		}
	}
	printf("\n last location: x = %f  y = %f  \nlast time: t=%f", x, y,t_sum);
	T[0] = t_sum;
	return x;
}
/*double ray_tracing_time(double x0, double angle, double z,double x)
{	//射线追踪（求时间）
	int i;
	double t;
	
	printf("real time = %f\n\n", t);
	return t;
}*/