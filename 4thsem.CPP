/*Coded by Manab Saha*/
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main(){
	
	int i=0,vowcnt=0,speccnt=0,openbrak=0,closebrak=0;
	char str[100];
	cout<<"Enter a string:";
	gets(str);
	while(str[i]!='\0'){
		
		int c = (int) str[i];
		
		if( c==65 || c==69 || c==73 || c==79 || c==85 || c==97 || c==101 || c==105 || c==111 || c==117 ){
					cout<<str[i]<<" is a vowel\n";
					vowcnt++;
		}
		else if( (c>=33 && c<=47) || (c>=58 && c<=64) || (c>=91 && c<=96)  || (c>=123 && c<=126) ){
					speccnt++;
					if(c==40){
						cout<<str[i]<<" is a special symbol (opening bracket) \n";
						openbrak++;
					}
					else if(c==41){
						cout<<str[i]<<" is a special symbol (closing bracket) \n";
						closebrak++;
					}
					else{
						cout<<str[i]<<" is a special symbol \n";
					}
		}
		i++;
	}
	cout<<"\nRESULT:\n"<<"Number of vowels: "<<vowcnt<<"\nNumber of opening bracket '(' : "<<openbrak
			<<"\nNumber of closing bracket ')' : "<<closebrak<<"\nNumber of special symbols: "<<speccnt;	
	getch();
	
}


