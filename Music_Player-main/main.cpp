#include<iostream>
#include<cstdio>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#include<conio.h>
#include<fstream>
#include <iomanip>

using namespace std;

struct node{
	struct node *prev;
	char name[20];
	int time;
	struct node *next;
};

class Songs{
	char name[20];
	int time;
public:
	void get()
	{
		cout<<"\nEnter the name:";
		cin>>name;
		cout<<"\nEnter the run time:";
		cin>>time;
	}
	
	void put()
	{
		if(time!=0)
		{
		cout<<"Name:";
		cout<<name;
		}
	}
	
	void rname(struct node *t)
	{
		strcpy(t->name,name);
	}
	
	int compare(char *s)
	{
		if(strcmp(name,s)==0)
		return 1;
		else
		return 0;
	}
	
	void null()
	{
		time=0;
	}
	int rtime()
	{
		return time;
	}
};

struct node *head=NULL;
struct node *last=NULL;
void admin();
void remove_song();
void insert(Songs x)
{
	if(head==NULL)
	{
	struct node *n=new(struct node);
	x.rname(n);
	//cout<<n->name;
	n->time=x.rtime();
	n->prev=NULL;n->next=head;
	head=n;last=n;
	}
	else
	{
	struct node *t=head;
	struct node *l=last;
    struct node *n=new(struct node);
    x.rname(n);
    //cout<< n->name;
	n->time=x.rtime();
        n->next=head;
        n->prev=last;
        t->prev=n;
        head=n;
        l->next=n;
    }
}


void list_update()
{
	int n;
	cout<<"\nEnter the no.of songs to add:";
	cin>>n;
	
	Songs a[n];
	int i;
	for(i=0;i<n;i++)
    {
        a[i].get();
    }

    ofstream sfile;
    sfile.open("list.dat",ios::app|ios::binary);
    i=0;
    while(i<n)
    {
        sfile.write((char*)&a[i],sizeof(a[i]));
        i++;
    }
    sfile.close();
	
}
int scount=0;

void display_list()
{
	Songs s;int i=0;
	ifstream ifile;
    ifile.open("list.dat",ios::out|ios::binary);
    ifile.read((char*) &s,sizeof(Songs));
            while(!ifile.eof())
            {
            	i++;
                cout<<"\n"<<i<<".";
                s.put();
                ifile.read((char*) &s,sizeof(Songs));
            }
            scount=i;
            ifile.close();
}

void create()
{
	cout<<"\nDisplaying the songs list\n";
	display_list();
	
	Songs s[scount];int i=0,n;
	
	ifstream ifile;
    ifile.open("list.dat",ios::out|ios::binary);
    ifile.read((char*) &s[i],sizeof(Songs));
            while(!ifile.eof())
            {
            i++;
            ifile.read((char*) &s[i],sizeof(Songs));
            }
            ifile.close();
    cout<<"\nEnter the no.of Songs in the playlist:";
    cin>>n;
    int a[n];
    cout<<"\nEnter the Songs serieal number:\n";
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	
	for(i=0;i<n;i++)
    {
    	if(a[i]<1||a[i]>scount)
    	{
    		cout<<"\n\aWrong Input try again\n";
    		return;
		}
	}
	
	for(i=n-1;i>=0;i--)
	{
		insert(s[a[i]-1]);
		//s[a[i]-1].put();
	}
	
	cout<<"\nPlaylist created successfully";
	
}

void playlist()
{
	 struct node *d=head;
    do
    {
    	cout<<"\n";
        cout<<d->name;
    	d=d->next;
    }while(d!=head);
}

int adver()
{
	static int t=0;
	cout<<"\n";
	cout<<setw(75);
	cout<<"**********************************\n";
	cout<<setw(75);
	cout<<"*Subscribe to avoid advertisement*\n";
	cout<<setw(75);
	cout<<"**********************************\n";
	t++;
	if(t==1)
	{
	PlaySound(TEXT("advertisement.wav"),NULL,SND_ASYNC);
	int waitSecond=17;
	while(1)
    {
     Sleep(1000);
     --waitSecond;

     if(waitSecond==0)   // wait complete.
     {
     break; 
	}
    }
	}
	else if(t==2)
	{
	PlaySound(TEXT("aachi.wav"),NULL,SND_ASYNC);
	int waitSecond=30;
	while(1)
    {
     Sleep(1000);
     --waitSecond;

     if(waitSecond==0)   // wait complete.
     {
     break; 
	}
    }
	}
	else if(t==3)
	{
	PlaySound(TEXT("phonepe.wav"),NULL,SND_ASYNC);
	int waitSecond=7;
	while(1)
    {
     Sleep(1000);
     --waitSecond;

     if(waitSecond==0)   // wait complete.
     {
     break; 
	}
    }
    t=0;
	}
    return 1;
}


void display(char *s)
{
	system("CLS");
	int sml=1;char ch=sml;
	cout<<"\t\t\t\t\t\t\t"<<ch<<" MUSIC PLAYER "<<ch;
	cout<<"\n\n\n\n\n\n";
	cout << setw (60);
	cout<<"Now Playing:"<<s<<"\n\n";
	cout << setw (70);
	cout<<"ENTER YOUR CHOICE"<<endl<<endl;
	cout << setw (65);
	cout<<"1.Play\t2.Pause"<<endl;
	cout << setw (65);
	cout<<"3.Next\t4.Prev"<<endl;
	cout << setw (65);
	cout<<"5.Exit"<<endl;	
	
}

void player()
{
	struct node *d=head;
	int c,ad=0;char g;
	int waitSecond =10;
	do{
		ad++;
		display(d->name);
		cout<<setw(45);
		cout<<"0."<<d->time<<"s:";
    while(1)
    {

     if(kbhit()) 
      {
       g=getch();
       cout<<"\n";
       cin>>c;
       break;
      }

     Sleep(1000);
     --waitSecond;
     cout<<"_";

     if(waitSecond==0)   // wait complete.
     {
     	c=4;
     break; 
	}
    }
		if(c==1)
		{
	     PlaySound(TEXT(d->name),NULL,SND_FILENAME|SND_ASYNC);
	     //playsong(d->name);
		}
	
		if(c==2||c==5)
	{
		PlaySound(0,0,0);
	}	
	
	if(c==3){
	d=d->next;
	PlaySound(TEXT(d->name),NULL,SND_FILENAME|SND_ASYNC);
	}
	
	if(c==4){
	d=d->prev;
	PlaySound(TEXT(d->name),NULL,SND_FILENAME|SND_ASYNC);
	}
	
	if(ad==3)
	{
		c=adver();
		ad=0;
		PlaySound(TEXT(d->name),NULL,SND_FILENAME|SND_ASYNC);
	}
	waitSecond=d->time;
	}while(c!=5);
	system("CLS");
}

void delete_song(char *s)
{
	 struct node *d=head;
	 struct node *t;
    do
    {
    	if(strcmp(s,d->name)==0)
    	{
    		t->next=d->next;
    		t=d->prev;
    		t->prev=d->prev;
		}
		t=d;
    	d=d->next;
    }while(d!=head);
}

void playlist_upd()
{
	cout<<"\nPlaylist Updation\n\n";
	
	int c;
	do
	{
		cout<<"\nEnter your choice:\n1.Display Playlist\n2.Add song\n3.Delete Song\n4.Exit\n";
		cin>>c;
		
		if(c==1)
		{
			playlist();
		}
		else if(c==2)
		{
			cout<<"\nDisplaying the songs list\n";
			display_list();
	
	Songs s[scount];int i=0,n;
	
	ifstream ifile;
    ifile.open("list.dat",ios::out|ios::binary);
    ifile.read((char*) &s[i],sizeof(Songs));
            while(!ifile.eof())
            {
            i++;
            ifile.read((char*) &s[i],sizeof(Songs));
            }
            ifile.close();
    cout<<"\nEnter the no.of Songs to add in the playlist:";
    cin>>n;
    int a[n];
    cout<<"\nEnter the Songs serieal number:\n";
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	
	for(i=0;i<n;i++)
    {
    	if(a[i]<1||a[i]>scount)
    	{
    		cout<<"\n\aWrong Input try again\n";
    		return;
		}
	}
	
	for(i=n-1;i>=0;i--)
	{
		insert(s[a[i]-1]);
	}
	
	cout<<"\nPlaylist created successfully";
	
		}
	else if(c==3)
	{
		char s[20];
		cout<<"\nEnter the song name to delete:";
		cin>>s;
		delete_song(s);
		cout<<"\nSong removed\n";
	}
	}while(c!=4);
	}

int main()
{
	int c;
	do{
	cout<<"\nEnter your option\n\n1.Create Playlist\n2.Play songs\n3.Update Playlist\n4.All songs\n5.Terminate\n";
	cin>>c;
	
	if(c==1)
	{
		create();
	}
	else if(c==2)
	{
		if(head!=NULL)
		{
		PlaySound(TEXT(head->name),NULL,SND_FILENAME|SND_ASYNC);
		player();
		system("CLS");
		}
		else
		cout<<"\n\aCreate an Plalist first!!";
	}
	else if(c==3)
	{
		if(head!=NULL)
		playlist_upd();
		else
		cout<<"\n\aCreate an Plalist first!!";
	}
	
	else if(c==6)
	{
		admin();
		system("CLS");
	}
	else if(c==5)
	{
		cout<<"\nMusic Player Closed!";
	}
	else if(c==4)
	{
		display_list();
	}
	else
	cout<<"Please enter a valid input";
	
	}while(c!=5);
	
	return 0;
}

void admin()
{
	int c;
	cout<<"\nEnter the password:";
	char s[5] = { 0 };
    int i;
    for (i=0;i<5;i++) {
        s[i] = _getch();
            _putch('*');
    }
	if(strcmp(s,"hello")==0)
	{
		do{
			cout<<"\nEnter your option:\n1.Update the list\n2.Delete a song\n3.Exit\n";
			cin>>c;
			if(c==1)
			{
				list_update();
			}
			else if(c==2)
			{
				remove_song();
			}
		}while(c!=3);
	}
	else
	{
		cout<<"\nWrong password!";
	}
}

void remove_song()
{
	display_list();
	char n[20];
	cout<<"\nEnter the song to delete:";
	cin>>n;
	
	Songs s;int i=0;
	ifstream ifile;
    ifile.open("list.dat",ios::out|ios::binary);
    ofstream sfile;
    sfile.open("new.dat",ios::app|ios::binary);
    ifile.read((char*) &s,sizeof(Songs));
            while(!ifile.eof())
            {
            	if(s.compare(n)==0)
				{
					s.put();
        			sfile.write((char*)&s,sizeof(s));
    			}
                ifile.read((char*) &s,sizeof(Songs));  
            }
            ifile.close();
	
	
    sfile.close();
    
    cout<<remove("list.dat");
    cout<<"\n"<<rename("new.dat","list.dat");
    cout<<"hi";
            
}
