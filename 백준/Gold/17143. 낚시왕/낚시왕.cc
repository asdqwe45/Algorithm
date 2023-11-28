#include <iostream>
#include <cstring>
using namespace std;

struct Info { int speed, dirNum, size; };

int height, width, sharkCnt;
Info originShark[101][101];
Info newShark[101][101];

int fishing(int point)
{
	int result = 0;

	for (int deep = 0; deep < height; deep++)
	{
		if (originShark[deep][point].size == 0) continue;

		result = originShark[deep][point].size;
		originShark[deep][point] = { 0, 0, 0 };
		break;
	}

	return result;
}

void moveShark()
{
	int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
	memset(newShark, 0, sizeof(newShark));

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (originShark[y][x].size == 0) continue;

			int speed = originShark[y][x].speed;
			int dirNum = originShark[y][x].dirNum;
			int size = originShark[y][x].size;
			int ny = y + (dir[dirNum][0] * speed);
			int nx = x + (dir[dirNum][1] * speed);

			if (!(ny < 0 || ny >= height || nx < 0 || nx >= width))
			{
				if (newShark[ny][nx].size > size) continue;
				newShark[ny][nx] = { speed, dirNum, size };
				continue;
			}
            
            if (dirNum == 0)
            {
                ny = -ny;
                dirNum = 1;
                if (ny >= height)
                {
                    ny = (height-1) - (ny - (height -1));
                    dirNum = 0;
                }
                if (newShark[ny][nx].size > size) continue;
    			newShark[ny][nx] = { speed, dirNum, size };
                continue;
                
            }
            if (dirNum == 1)
            {
                ny = (height-1) - (ny - (height -1));
                dirNum = 0;
                if (ny < 0)
                {
                    ny = -ny;
                    dirNum = 1;
                }
                if (newShark[ny][nx].size > size) continue;
    			newShark[ny][nx] = { speed, dirNum, size };
                continue;
                
            }
            if (dirNum == 3)
            {
                nx = -nx;
                dirNum = 2;
                if (nx >= width)
                {
                    nx = (width-1) - (nx - (width -1));
                    dirNum = 3;
                }
                if (newShark[ny][nx].size > size) continue;
    			newShark[ny][nx] = { speed, dirNum, size };
                continue;
                
            }
            if (dirNum == 2)
            {
                nx = (width-1) - (nx - (width -1));
                dirNum = 3;
                if (nx < 0)
                {
                    nx = -nx;
                    dirNum = 2;
                }
                if (newShark[ny][nx].size > size) continue;
    			newShark[ny][nx] = { speed, dirNum, size };
                continue;
                
            }
		}
	}

	memcpy(originShark, newShark, sizeof(newShark));
}

int main()
{
    cin.tie(NULL);
	ios::sync_with_stdio(false);
	// input
	cin >> height >> width >> sharkCnt;
	int h = (height - 1) * 2;
	int w = (width - 1) * 2;
	for (int i = 0; i < sharkCnt; i++)
	{
		int y, x, speed, dirNum, size;
		cin >> y >> x >> speed >> dirNum >> size;
		if (dirNum == 1 || dirNum == 2) speed %= h;
		if (dirNum == 3 || dirNum == 4) speed %= w;
		originShark[y - 1][x - 1] = { speed, dirNum - 1, size };
	}

	// solve
	int answer = 0;
	for (int time = 0; time < width; time++)
	{
		answer += fishing(time);
		if (time == width - 1) break; 
        moveShark();
	}

	// output
	cout << answer << '\n';

	return 0;
}