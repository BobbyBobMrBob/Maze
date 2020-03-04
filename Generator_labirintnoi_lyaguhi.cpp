// ����� �� �������� ���������� ���������
#include <iostream>  // ������ �����������
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std; // ���������� ���������� ���� ����, ���� ����� ���� ������ ������ cout � cin

const int SIZE=47; // ������ ������ ��������� � ������� ���������, ��� ��� ��� ��� ���������� ���, �� ��������

bool deadend(int height, int width, const int SIZE, int (&Maze)[47][47]) //������� �������� �� �����
	{
		int nogo = 0;
		if(width != 1)
		{
			if(Maze[height][width-2] == 1)
				nogo+=1;
		}
		else nogo+=1;
		if(width != (SIZE-2))
		{
			if(Maze[height][width+2] == 1)
				nogo+=1;
		}
		else nogo+=1;
		if(height != 1)
		{
			if(Maze[height-2][width] == 1)
				nogo+=1;
		}
		else nogo+=1;
		if(height != (SIZE-2))
		{
			if(Maze[height+2][width] == 1)
				nogo+=1;
		}
		else nogo+=1;
		
		if (nogo == 4)
			return 1;
		else
			return 0;
	}
int main() // �������� �������, � �� ���� ������ ��� ������� ���� MakeMaze, ��� ����, ���� � � ��������������
{
	srand(static_cast<unsigned int>(time(0))); // ��� ������� ��������� ��� ������� ����� ������� ������� ������������ ������� �������, � ��� ��� ��� ������ ��� ������, �� � ����������� ����� �������
	
	int height = 2*(rand()%(SIZE/2))+1, width = 2*(rand()%(SIZE/2))+1, full = 0; // ������ ��������� ������ � ������, ���� �� ���� ������� ������������ ����� �������
	int Maze[SIZE][SIZE]; // ������������� �������
	for (int i=0;i<SIZE;i++) // ���������� ������� ������
	{
		for (int j=0;j<SIZE;j++)
		{
			Maze[i][j] = 0; //" ";
		}
	} 
	while (true) // ������� ����, ������� ����� ������� ����� �������� ������
	{
		Maze[height][width] = 1; // ��� ������������ ������, ��� ������
		while (true)// � ��� � ���� ����� ������� �������� ������ � ��������� ������� �� ��������� � �����
		{
			int c = rand()%4;
			switch(c) // ������� ����� � ������� ��������� ���������� �� 4 ����������� ��������
			{  
				case 0: 
				if(height != 1)
				{
					if(Maze[height-2][width] == 0)
						{
            	     	    Maze[height-1][width] = 1;
							Maze[height-2][width] = 1;
							height-=2;
						}
				}
				break;
				case 1: 
				if(height != (SIZE-2))
				{		
					if(Maze[height+2][width] == 0)
						{
                	 	    Maze[height+1][width] = 1;
							Maze[height+2][width] = 1;
							height+=2;
						}
				}
				break;
				case 2: 
				if(width != 1)
				{
					if(Maze[height][width-2] == 0)
						{
                	 	    Maze[height][width-1] = 1;
							Maze[height][width-2] = 1;
							width-=2;
						}
				}
				break;
				case 3: 
				if(width != (SIZE-2))
				{
					if(Maze[height][width+2] == 0)
						{
                	 	    Maze[height][width+1] = 1;
							Maze[height][width+2] = 1;
							width+=2;
						}
				}
				break;
			}
			if (deadend(height,width,SIZE,Maze)) // ������ ���� �� ����� ����� ������� ���� ������, � ���� �����, �� ������� �� ������ ����� �����
				break;
		}
		
	if (Maze[height][width] == 1) // ��� ���������� ��� ������ ���� �� ������� �������, �� ������ �� ����, ������ ��� ���, �� ��� ��������, ������ ����� ����� ���, �� ������
	{
		full += 1;
	}
	if (full == pow(((SIZE-1)/2),2))
		break;
	if (deadend(height,width,SIZE,Maze)) // ��� ���� ������ ����, �� ��� ������ ���������� ������ � ����� ��������� �����, ������� ��� �� ���������
	do
	{
		height = 2*(rand()%(SIZE/2))+1;
		width = 2*(rand()%(SIZE/2))+1;
	}
	while(Maze[height][width] == 0);
	}
	// ������ ���� ����� ��� ��� �� �������� ������ � �������
	bool boolb = 1; // ��� �� �������� ��������� ��������� �� ������������ �������� ��� �����(�� ���������, ���� �� ���� ������� � ����� ��� ��������� � �����, ��� �� � �� ���� ���������� ������ ������, ���� ��� ��
	int c = rand()%2; // ���������� �� ����������� ������� ���� �� �����������, ���� �� ���������
	switch(c) // ��� ���� ����� �� ��� �� ������. �� �������
	{
		case 0:
			while (boolb) // ���� ��� ������ �� ����� ���� ��� �� ������������ ������� �������� � ��� "������" �� ������ � �� ������ �� �������, ����� ���� ������ �������� �� ������ �����
			{
			height = 0;
			width = rand()%SIZE;
			if ((Maze[height+1][width] == 1)&&(width != 0)&&(width != SIZE-1))
				{
					Maze[height][width] = 1;
					boolb = 0;
				}	
			}
			boolb = 1;	
			while (boolb)
			{
			height = SIZE-1;
			width = rand()%SIZE;
			if ((Maze[height-1][width] == 1)&&(width != 0)&&(width != SIZE-1))
				{
					Maze[height][width] = 1;
					boolb = 0;
				}	
			}
			break;
		case 1:
			while (boolb)
			{
			width = 0;
			height = rand()%SIZE;
			if ((Maze[height][width+1] == 1)&&(height != 0)&&(height != SIZE-1))
				{
					Maze[height][width] = 1;
					boolb = 0;
				}	
			}
			boolb = 1;
			while (boolb)
			{
			width = SIZE-1;
			height = rand()%SIZE;
			if ((Maze[height][width-1] == 1)&&(height != 0)&&(height != SIZE-1))
				{
					Maze[height][width] = 1;
					boolb = 0;
				}	
			}
			break;
	}
	for (int i=0;i<SIZE;i++) // ����� ������� � �������������� �������� � ������� ASCII 
	{
		for (int j=0;j<SIZE;j++)
		{
			if (Maze[i][j] == 1)
			cout << "  ";
			else
			cout << (char) 178 << (char) 178; // �� ��� ������� � ��� ������� ������ ��� ������� ����� ����������� 2/1 � ����� ������� �� ������ �������� �� ���������.
		}
		cout << endl;
	}
system("pause"); // ��� ������� ��� ������������ ����� exe, ���� ������� �� �����������, � ����� ���� �������� �� ��������
}
