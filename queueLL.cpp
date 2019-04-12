//Coded on 02/03/18.
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct node
{
	struct node *next;
	int data_int,type;
	float data_float;
	char data_char,data_string[50];
}*start,*rear;
int datatype(char s[50])     //function: returns the data-type
{
	int i=0,num=0,dec_num=0,str=0;
	//char signflag = s[0];
	if(s[0] == '-')  i=1;
	while(s[i]!='\0')
	{
		if((s[i]>47 && s[i]<58))
		num=1;
		if(s[i]=='.'){
			dec_num++;
		}
		if(((s[i]>0&&s[i]<=47)||(s[i]>58&&s[i]<128))&&(s[i]!='.')){
			str=1;
		}
		i++;
	}
	if((dec_num==1&&num==1&&str==0))
	return 3;
	else if((num==1&&str==0&&dec_num==0))
	return 4;
	else if(i==1)
	return 1;
	else
	return 2;
}

float stof(char *s)      //function: converts string to float.
{
	float n=0;
	int decimal=0,count=0,i;
	if(s[0]=='-'){
		i=1;
	}
	else i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='.')
		{
			decimal=1;
			count=0;
		}
		else if(decimal)
		{
			n+=((float)s[i]-48)/pow(10,count);
		}
		else
		{
			n=(float)s[i]-48+10*n;
		}
		i++;
		count++;
	}
	if(s[0]=='-') return (-n);
	else return n;
	
}
void push(char s[50])
{
	node *ptr=new node;
	ptr->type=datatype(s);
	switch(ptr->type)
	{
		case 1:ptr->data_char=s[0];cout<<"Character";
		break;
		case 2:strcpy(ptr->data_string,s);cout<<"String";
		break;
		case 3:ptr->data_float=stof(s);cout<<"Float";
		break;
		case 4:ptr->data_int=atoi(s);cout<<"Integer";
	}
	ptr->next=NULL;
	if(start==NULL)
	{
		start=rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
void pop()
{
	node *ptr=new node;
	ptr=start;
	if(start!=NULL)
	{
		cout<<"Popped ";
		switch(ptr->type)
		{
			case 1:cout<<"Character : \'"<<ptr->data_char<<"\'"<<endl;break;
			case 2:cout<<"String : \""<<ptr->data_string<<"\""<<endl;break;
			case 3:cout<<"Float : "<<ptr->data_float<<endl;break;
			case 4:cout<<"Integer : "<<ptr->data_int<<endl;break;
		}
		start=ptr->next;
	}
	else
	cout<<"Error! queue is empty.";
	
}
void display()				//function to display all the elements
{	cout<<endl;
	node *ptr=new node;
	ptr=start;
	while(ptr!='\0')
	{	
		switch(ptr->type)
			{
				case 1:cout<<"Character: "<<ptr->data_char<<endl;
				break;
				case 2:cout<<"String: "<<ptr->data_string<<endl;
				break;
				case 3:cout<<"Float: "<<ptr->data_float<<endl;
				break;
				case 4:cout<<"Integer: "<<ptr->data_int<<endl;
				break;
			}
			ptr=ptr->next;
			
	}
}
int main()
{	
	cout<<"Programs that detects your datatype and store in Queue of Linked List\n\n";
	cout<<"Type help for commands";
	while(1){
		int i,j;
		char cmd[50];
		char val[50];
		cout<<"\n>>";
		cin>>cmd;
		int len = strlen(cmd);
		if(cmd[0]=='p'&&cmd[1]=='u'&&cmd[2]=='s'&&cmd[3]=='h'&&cmd[4]=='('&&cmd[len-1]==')'){
			i=0;
			for(j=5;j<=len-2;j++){
				//strcat(val,cmd[j]);
				val[i]=cmd[j];
				i++;
			}
			val[i]='\0';
			push(val);
			strcpy(cmd,"");
			strcpy(val,"");
		}
		else if(strcmp(cmd,"display")==0){
			display();
		}
		else if(strcmp(cmd,"pop")==0){
			pop();	
		}
		else if(strcmp(cmd,"exit")==0){
			exit(0);
		}
		else if(strcmp(cmd,"help")==0){
			cout<<"POP: pop \nPUSH: push(value) \nDISPLAY: display \nEXIT: exit \nHELP: help\n";
		}
		else{
			cout<<"Ergh! Error. Type help for commands";
			strcpy(cmd,"");
		}
	}
}

