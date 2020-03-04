// Кодик на создание случайного лабиринта
#include <iostream>  // Нужные библиотечки
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std; // Подключаем нормальное поле имен, чтоб можно было просто писать cout и cin

const int SIZE=47; // Размер нашего лабиринта в формате константы, ибо вот так вот захотелось мне, че смотришь

bool deadend(int height, int width, const int SIZE, int (&Maze)[47][47]) //Функция проверки на тупик
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
int main() // Основная функция, я не стал писать доп функцию типа MakeMaze, ибо лень, хоть я и функциональщик
{
	srand(static_cast<unsigned int>(time(0))); // При запуске программы эта строчка садит семечко рандома относительно времени запуска, а так как оно каждый раз разное, то и лабиринтики будут разными
	
	int height = 2*(rand()%(SIZE/2))+1, width = 2*(rand()%(SIZE/2))+1, full = 0; // Задаем случайную высоту и ширину, лишь бы были четными относительно нашей матрицы
	int Maze[SIZE][SIZE]; // Инициализация матрицы
	for (int i=0;i<SIZE;i++) // Заполнение матрицы нулями
	{
		for (int j=0;j<SIZE;j++)
		{
			Maze[i][j] = 0; //" ";
		}
	} 
	while (true) // Внешний цикл, который будет началом ветки движения лягухи
	{
		Maze[height][width] = 1; // Это инциализация лягухи, так скажем
		while (true)// А уже в этом цикле описано движение лягухи в случайном порядке до попадания в тупик
		{
			int c = rand()%4;
			switch(c) // Обычный свитч с обычной случайной переменной на 4 направления движения
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
			if (deadend(height,width,SIZE,Maze)) // Провер очка на тупик после каждого шага лягухи, и если тупик, то выходим на начало новой ветки
				break;
		}
		
	if (Maze[height][width] == 1) // Тут начинается моя провер очка на полноту матрицы, но вообще не знаю, почему она тут, но так работает, значит пусть лежит тут, не трогай
	{
		full += 1;
	}
	if (full == pow(((SIZE-1)/2),2))
		break;
	if (deadend(height,width,SIZE,Maze)) // Ещё одна провер очка, но эта просто перемещает лягуху в новое случайное место, которое ещё не заполнено
	do
	{
		height = 2*(rand()%(SIZE/2))+1;
		width = 2*(rand()%(SIZE/2))+1;
	}
	while(Maze[height][width] == 0);
	}
	// Дальше идет чисто мой код на создание входов и выходов
	bool boolb = 1; // Это на проверку случайных координат на допустимость создания там дырок(Ну понимаешь, чтоб не было выходов в углах или смотрящих в стену, тут же я не беру координаты только четные, хотя мог бы
	int c = rand()%2; // Переменная на определение выходов либо по горизонтали, либо по вертикали
	switch(c) // Ещё один свитч но уже на выходы. Он простой
	{
		case 0:
			while (boolb) // Типа вот массив на дырки пока они не удовлетворят условию проверки и наш "флажок" не упадет и мы выйдем из массива, после чего заново поднимем на второй выход
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
	for (int i=0;i<SIZE;i++) // Вывод матрицы с использованием символов с таблицы ASCII 
	{
		for (int j=0;j<SIZE;j++)
		{
			if (Maze[i][j] == 1)
			cout << "  ";
			else
			cout << (char) 178 << (char) 178; // По два символа и два пробела потому что символы имеют размерность 2/1 и таким образом мы делаем картинку не вытянутой.
		}
		cout << endl;
	}
system("pause"); // Эта строчка для исполняемого файла exe, чтоб консоль не закрывалась, а можно было пялиться на лабиринт
}
