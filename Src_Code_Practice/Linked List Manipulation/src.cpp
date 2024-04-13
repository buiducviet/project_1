#include <bits/stdc++.h>
using namespace std;
vector <int> a;
int convert(string str)
{
   int tmp = 0;
   for (int i = 0; i < str.length(); i++)
      tmp = tmp * 10 + (str[i] - '0');
   return tmp;
}
int find(int x)
{
   for(int i=0;i<a.size();i++)if(a[i]==x)return i;
   return -1;
}
int main()
{
   int n, i;
   cin>>n;
   for (i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      a.push_back(x);
   }
   string s;
  while (s != "#")
   {
      getline(cin, s);
      if (s.substr(0, 7) == "addlast")
      {
         int tmp = convert(s.substr(8, s.length()));
            if(find(tmp)==-1)a.push_back(tmp);
      }
      if (s.substr(0, 8 ) == "addfirst")
      {
         int tmp = convert(s.substr(9, s.length()));
            if(find(tmp)==-1)a.insert(a.begin(),tmp);
         }
   if (s.substr(0, 8 ) == "addafter")
   {
      string str = "";
      int i = 9;
      while (s[i] != ' ')
      {
         str = str + s[i];
         i++;
      }
      int x = convert(str);
      i++;
      int y = convert(s.substr(i, s.length()));
      {
         if(find(y)!=-1&&find(x)==-1)
         {
            if(find(y)==a.size()-1)a.push_back(x);
               else a.insert(a.begin()+find(y)+1,x);
         }
      }
   }
   if (s.substr(0, 9) == "addbefore")
   {
      string str = "";
      int i = 10;
      while (s[i] != ' ')
      {
         str = str + s[i];
         i++;
      }
      int x = convert(str);
      i++;
      int y = convert(s.substr(i, s.length()));
      {
            if(find(y)!=-1&&find(x)==-1)a.insert(a.begin()+find(y),x);
      }
   }
   if (s.substr(0, 6) == "remove")
   {
      int tmp = convert(s.substr(7, s.length()));  
      if(find(tmp)!=-1)a.erase(a.begin()+find(tmp));
   }
   if (s.substr(0, 7) == "reverse")
      reverse(a.begin(), a.end());
}
for(auto x:a)cout<<x<<" ";
}
