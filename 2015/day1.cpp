#include<iostream>
#include<fstream>
using namespace std;

int main()
{
  string ip = "";
  string fn = "day1-ip.txt";
  ifstream fl(fn);
  if(!fl.is_open())
    {
      cout<<"error opening ip file\n";
      return 0;
    }
  string curline;
  while(getline(fl, curline))
    {
      ip+=curline;
    }
    fl.close();
  
  int floor = 0;

  int len = ip.size();
  for(int i=0;i<len;i++)
    {
      if( ip[i]=='(')
	{
	  floor++;
	}else
	{
	  floor--;
	}
    }
    cout<<"ans: "<<floor<<"\n";
  return 0;
}
