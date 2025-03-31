#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;

void getCoord(string str, int *res)
{
  int n = str.size();

  int commandType = -1; // turn on = 1, turn off = 2, toggle = 3
  string starting = str.substr(0, 7);
  if (starting == "turn on")
  {
    commandType = 1;
  }
  else if (starting == "turn of")
  {
    commandType = 2;
  }
  else
  {
    commandType = 3;
  }
  int idx = 0;
  string x1 = "";
  string y1 = "";
  string x2 = "";
  string y2 = "";
  for (idx = 0; idx < n; idx++)
  {
    if (isdigit(str[idx]))
    {
      x1 += str[idx];
    }
    if (str[idx] == ',')
    {
      idx++;
      break;
    }
  }
  for (; idx < n; idx++)
  {
    if (isdigit(str[idx]))
    {
      y1 += str[idx];
    }
    if (str[idx] == ' ')
    {
      idx++;
      break;
    }
  }

  for (; idx < n; idx++)
  {
    if (isdigit(str[idx]))
    {
      x2 += str[idx];
    }
    if (str[idx] == ',')
    {
      idx++;
      break;
    }
  }
  for (; idx < n; idx++)
  {
    if (isdigit(str[idx]))
    {
      y2 += str[idx];
    }
    if (str[idx] == ' ')
    {
      break;
    }
  }
  res[0] = commandType;
  res[1] = stoi(x1);
  res[2] = stoi(y1);
  res[3] = stoi(x2);
  res[4] = stoi(y2);
}

int main()
{
  string fn = "day6-ip.txt";
  ifstream ifs(fn);
  if (!ifs.is_open())
  {
    cout << "error opening ip file\n";
    return 0;
  }

  int W = 1000;
  int H = 1000;
  // initialize 2d grid W x H with false
  vector<vector<int>> grid(W, vector<int>(H, 0));
  string curline;
  int commandType, x1, y1, x2, y2;
  int res[5];
  while (getline(ifs, curline))
  {
    getCoord(curline, res);
    commandType = res[0];
    x1 = res[1];
    y1 = res[2];
    x2 = res[3];
    y2 = res[4];
    if (y1 > y2)
    {
      for (int i = x1; i <= x2; i++)
      {
        for (int j = y1; j >= y2; j--)
        {
          if (commandType == 1)
          {
            grid[i][j] += 1;
          }
          else if (commandType == 2)
          {
            if (grid[i][j] > 0)
            {
              grid[i][j] -= 1;
            }
          }
          else
          {
            grid[i][j] += 2;
          }
        }
      }
    }
    else
    {
      for (int i = x1; i <= x2; i++)
      {
        for (int j = y1; j <= y2; j++)
        {
          if (commandType == 1)
          {
            grid[i][j] += 1;
          }
          else if (commandType == 2)
          {
            if (grid[i][j] > 0)
            {
              grid[i][j] -= 1;
            }
          }
          else
          {
            grid[i][j] += 2;
          }
        }
      }
    }
  }
  int totalBright = 0;
  for (int i = 0; i < W; i++)
    for (int j = 0; j < H; j++)
    {
      totalBright += grid[i][j];
    }
  cout << "ans: = " << totalBright << "\n";

  return 0;
}
