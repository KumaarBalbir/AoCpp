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
  int idx = -1;
  for(int i=0;i<len;i++)
    {
      if( ip[i]=='(')
	{
	  floor++;
	}else
	{
	  floor--;
	}
      if(idx == -1)
	{
	  if(floor == -1)
	    {
	      idx = i+1;
	    }
	}
    }
    cout<<"ans: "<<floor<<"\n";
    cout<<"index: "<<idx<<"\n";
    
    
  return 0;
}
