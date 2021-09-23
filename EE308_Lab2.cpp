#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stack>
#include <ctype.h>
#include <cassert>
using namespace std;
stack<int> S;
int ifelse_num=0,if_elseif_else_num=0;
int main()
{
	std::string keywords[32]={"auto","break","case","char","const","continue","default","double",
						"do","else","enum","extern","float","for","goto","if",
						"int","long","register","return","short","signed","sizeof","static",
						"struct","switch","typedef","union","unsigned","void","volatile","while"};
	// change all the keywords to an array
	
	std::ifstream out;
	out.open("c_language_test_file.cpp");
	std::string str;
	int total_num;
	int switch_num=0,case_num=0;
	std::cout<<"case num: ";
	while (!out.eof())
		{	
			getline(out,str); // to read the file
				if(str.find("else if")!=string::npos)
			{
				S.push(2);
			}
			else
			{
				if(str.find("if")!=string::npos)
				{
					S.push(1);
				}
				else
				{
					if(str.find("else")!=string::npos)
					{
						if(S.top()==1)
						{
							ifelse_num++;
							S.pop();
						}
						else	
						{
							if(S.top()==2)
							{
								if_elseif_else_num++;
								S.pop();
							}
						}
					}
				}
			}
			for(int i=0 ; i<=32 ; i++)
			{
				std::string::size_type position;
				position = str.find(keywords[i]);
				
				if(position != str.npos) // to set the initial number "-1"
				{					
					total_num++;
					if(i==25)
					{
						switch_num++;
					}
					if(i==25&&case_num!=0) // to find the keyword "switch"
					{
						std::cout<<case_num<<" & ";
						case_num=0;	
					}
					
					if(i==2) // to find the keyword "case"
					{						
						case_num++;	
					}
					
					if(i==7) // to decrease the number of the 'double' and 'do' repeat
					{
						total_num--;
					}
					
				}
		    }	
		     
		}
	std::cout<<case_num<<"\n";
	std::cout<<"total num: "<<total_num<<"\n";
	std::cout<<"switch num: "<<switch_num<<"\n";
	std::cout<<"ifelse num: "<<ifelse_num<<"\n";
	std::cout<<"if_elseif_else_num: "<<if_elseif_else_num<<"\n";
}



