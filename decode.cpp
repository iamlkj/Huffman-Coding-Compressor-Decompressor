#include<iostream>
#include<fstream>
#include <string>
#include <iomanip>
#define max 200000
using namespace std;

class node{
	public:
	node()
	{
		data=0;
	
	}

string code;
char data;
}table[300];

ifstream fin("header.txt");
ofstream fout("decodefile.txt");
FILE*ff,*out;
int cnt,t;
char codetmp[max];

int find(string tmp,int a,int b)
{
	int t;
	//cout<<tmp<<"  "<<a<<" "<<b<<endl;
	//system("pause");
	if(a>=b)return -1;
	else if(tmp.compare(table[(a+b)/2].code)==0)
	{
		t=(a+b)/2;	
	}
	else if(tmp.compare(table[(a+b)/2].code)>0)
	{
		t=find(tmp,(a+b)/2+1,b);	
	}
	else if(tmp.compare(table[(a+b)/2].code)<0)
	{
		t=find(tmp,a,(a+b)/2);
	}
	return t;
}

int putin(const char x)
{
	static string tmp="";
	tmp=tmp+x;
	int k;
	
	if(k=find(tmp,0,t),k!=-1)
	{
		//cout<<"find!!"<<endl;
		fout<<table[k].data;	
		tmp.clear();
		return 1;
	}	
	return 0;
}

void process(unsigned char x)
{
		unsigned char mask=128;
		//printf("~%d~\n",x);
		//printf("%d\n",mask);
		int i=8;
		while(i>0&&cnt>0)
		{
			i--;
			if(((mask&x)>>i)==1)
			{
				//printf("%d",1);
				if(putin('1'))cnt--;	
			}
			else
			{
				//printf("%d",0);
				if(putin('0'))cnt--;
			}
			mask=mask>>1;
		}
}

int main()
{
	long maxsize;
	out=fopen ( "tttt.txt" , "w" );
	fin>>cnt>>t;
	int i=0,stupid;
	stupid=0;
	string tmp;
	getline(fin,tmp);
	while(i<t)
	{
		string tmp;
		if(getline(fin,tmp),tmp[0]==0)
		{
				table[i].data='\n';
				string tt;
				getline(fin,tt);
				table[i].code=tt;
				stupid++;
		}
		else
		{
			table[i].data=tmp[0];
			tmp.erase(0,1);
			table[i].code=tmp;
		}
		cout<<table[i].data<<" = "<<table[i].code<<endl;
		i++;
	}
//	getline(fin,codetmp);
/*char ttt[1000];
	for(int i=0;i<=t+stupid;i++)
	{
		fgets(ttt,1000,ff);
	}*/
	
	
	
	FILE * pFile;
  long lSize;
  unsigned char * buffer;
  size_t result;

  pFile = fopen ( "rarfile.txt" , "rb" );
  if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (unsigned char*) malloc (sizeof(unsigned char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
	//for(int i=0;i<lSize;i++)printf("%c",buffer[i]);
	int k=0;
	while(cnt!=0)
	{
		//fin.get(x);
		//x=fgetc(ff);
		
		fprintf(out,"%c",buffer[k]);
			//x=codetmp[k];
			//codetmp.erase(0,1);
			process(buffer[k]);
			k++;
				
	}
	system("pause");
	//fread(codetmp,1,max,ff);
	
	
	
	
	
	
}
