#include<bits/stdc++.h>
using namespace std;
int t[100007];
int b;
double czy_dobrze(double x)
{
	//cout<<x<<" ";
	double pom = t[0]+ x+x;
	//cout<<pom<<" akt zasieg dokod "<<t[1]<<" gdzie ";
	int sum =1;
	//cout<<" sum "<<sum<<" ";
	for(int i=1;i<b;i++)
	{
		if(t[i]>pom)
		{
			pom = t[i]+x+x;
			//cout<<pom<<" akt zasieg dokod "<<t[1]<<" gdzie ";
			sum++;
			//cout<<" sum "<<sum<<" ";
		}
	}
	//cout<<sum<<endl;
	return sum;
}
int main()
{
	int a;
	cin>>a>>b;
	for(int i=0;i<b;i++)
	{
		cin>>t[i];
	}
	sort(t,t+b);
	double pocz=0,kon=t[b-1]+1;
	while(kon - pocz>=0.01)
	{
		double sro=(pocz+kon)/2;
		if(czy_dobrze(sro)<= a)
		{
			kon=sro;
		}else{
			pocz=sro;
		}
	}
	cout<<fixed<<setprecision(1)<<kon;
}