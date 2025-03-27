#include <iostream>
#include <utility>
#include <set>
#include <fstream>

using namespace std;
int main()
{

  string fn = "day3-ip.txt";
  
  int x = 0;
  int y = 0;

  int x2 = 0;
  int y2 = 0;

  set<pair<int,int>> uniqLocation;
  uniqLocation.insert({x,y});
  
  ifstream ifs(fn);
  if(!ifs.is_open())
    {
      cout<<"error opening ip file\n";
      return 0;
    }

  string curline;
  bool flag = true;
  
  while(getline(ifs,curline))
    {
      for(char &ch: curline)
	{
	  if(flag)
	    {
	  if(ch == '^')
	    {
	      y += 1;
	    }
	  else if(ch == 'v')
	    {
	      y -= 1;
	    }
	  else if(ch == '>')
	    {
	      x += 1;
	    }
	  else if(ch == '<')
	    {
	      x -= 1;
	    }
	  flag = false;
	  uniqLocation.insert({x,y});}
	  else
	    {
	        if(ch == '^')
	    {
	      y2 += 1;
	    }
	  else if(ch == 'v')
	    {
	      y2 -= 1;
	    }
	  else if(ch == '>')
	    {
	      x2 += 1;
	    }
	  else if(ch == '<')
	    {
	      x2 -= 1;
	    }
		uniqLocation.insert({x2,y2});
		flag = true;
	    }
	      
	}
    }
  ifs.close();
  cout<<"ans: "<<(int)uniqLocation.size()<<"\n";

  return 0;
}
	
       
         
   
