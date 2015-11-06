#include<iostream>
#include<string>
#include <fstream>
using namespace std;
class node{
	public:
	node()
	{
		v=0;
		lc=NULL;
		rc=NULL;
		data=0;
	
	}

int v;
string code;
node* lc;
node* rc;
char data;
}q[1000];




ofstream fout("rarfile.txt");
ofstream fh("header.txt");
node table[300];
int t,kkk;
int qptr;



int print(string x)
{
	static string tmp;
	tmp=tmp+x;
	if(tmp.length()>=8)
	{
		unsigned char k=0;
		for(int i=0;i<8;i++)
		{
			k=k<<1;
			if(tmp[i]=='1')k=k+1;
		}
		fout<<k;
		kkk++;
		tmp.erase(0,8);
	}
	return tmp.length();
}

void add(node tmp)
{	
	if(tmp.lc!=NULL)
	{
		tmp.lc->code=tmp.code+'0';
		add(*(tmp.lc));	
	}
	if(tmp.rc!=NULL)
	{
		tmp.rc->code=tmp.code+'1';
		add(*(tmp.rc));
	} 
	if(tmp.lc==NULL && tmp.rc==NULL && tmp.data!=0)
	{
		table[t]=tmp;
		t++;
	}
}



string find(char x)
{
	int i=0;
	while(table[i].data != x && i<t)
	{
		i++;	
	}
	return table[i].code;
}

int comp (const void * a, const void * b)
{
	node atmp=*(node*)a;
	node btmp=*(node*)b;
  return (  btmp.v-atmp.v );
}
void adjust()
{
	qsort(q,qptr,sizeof(node),comp);	
	
}
void quin(node tmp)
{
	/*int i=qptr-1;
	while(i>=0&&q[i].v<tmp.v)i--;
	for(int j=qptr-1;j>i;j++)
	{
			q[j+1]=q[j];
	}
	q[i+1]=tmp;	
	qptr++;*/
	q[qptr]=tmp;
	qptr++;
	adjust();
}








node qu()
{
	
	qptr--;
	return q[qptr]; 
}



void putin(char x)
{
	int ok;
	ok=0;
	for(int i=0;i<qptr;i++)
	{
		if(q[i].data==x)
		{
			q[i].v++;
			ok=1;
		}	
	}
	if(ok==0)
	{
		q[qptr].data=x;
		q[qptr].v=1;
		qptr++;	
	}
}


int main ()
{
	t=0;
	char x;
	FILE *fin,*fread;
	fin=fopen("123.txt","r");
	fread=fopen("123.txt","r");
	
	while(fscanf(fin,"%c",&x)!=EOF)
	{
		putin(x);
	}

	
	adjust();

	while(qptr>1)
	{
		node *t1=new node;
		node *t2=new node;
		*t1=qu();
		*t2=qu();
		node tmp;
		tmp.v=t1->v+t2->v;
	
			tmp.lc=t1;
			tmp.rc=t2;	
		//printf("f=%d,L=%d,R=%d\n",tmp.v,tmp.lc->v,tmp.rc->v);
		
		quin(tmp);
		
	}
	
	add(q[0]);
		
	int count=0;
	for(int i=0;i<t;i++)
	{
		count+=table[i].v ;
	}
	
	fh<<count<<" "<<t<<endl;
	
	int i=0;
	while(i<t)
	{
		fh<<table[i].data<<table[i].code<<endl;
		i++;
	}
	int test;
	while(x=fgetc(fread),x!=EOF)
	{
		string tmp;
		tmp=find(x);
		//fout<<tmp;
		test=print(tmp);
	}
	while(test!=0)
	{
		test=print("0");	
	}
	printf("~%d~",kkk);
		system("pause");
	
	
}
