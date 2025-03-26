#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
  string fn = "day2-ip.txt";
  ifstream ifn(fn);
  if(!ifn.is_open())
    {
      cout<<" error opening ip  file\n";
	return 0;
    }

  string curline;
  long long totArea = 0;
  long long totRibbon = 0;

  while(getline(ifn, curline))
    {
      int pos1 = -1;
      int pos2 = -1;
      for(int i=0;i<(int)curline.size();i++)
	{
	  if(curline[i] == 'x')
	    {
	      if(pos1 == -1)
		{pos1 = i+1;}
	      else
		{
		  pos2 = i+1;}
	    }
	}
      long long l = stoi(curline.substr(0, pos1));
      long long w = stoi(curline.substr(pos1, pos2-pos1));
      long long h = stoi(curline.substr(pos2));
      totArea += 2*l*w + 2*w*h + 2*h*l;
      totArea += min(min(l*w, l*h), w*h);
      totRibbon += (l*w*h);
      totRibbon += min(min(2*(l+w), 2*(l+h)), 2*(h+w));
    }
  cout<<"ans: "<<totArea<<"\n";
  cout<<"tot ribbon: "<<totRibbon<<"\n";
  return 0;
}
      
