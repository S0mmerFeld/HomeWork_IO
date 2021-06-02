#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <iomanip>
#include "main.h"

enum SETTINGS
{
	NUMCOMMA = 3,
	LINE_WIDTH = 12
};

void print_table_header()
{
	cout.width(LINE_WIDTH); cout<<left<<"  Succeded" <<'\t';
	cout.width(LINE_WIDTH); cout<<left<<"Name"<<'\t';
	cout.width(LINE_WIDTH); cout<<left<<"Surname"<<'\t';
	cout.width(LINE_WIDTH); cout<<right<<"Avr mark"<<'\t';
	cout.width(LINE_WIDTH); cout<<right<<"Attended" <<endl;

}

void comma_processing (Comma &comma, string row)
{	
	for (int i=0; i<row.size(); ++i)
	{
		if(row[i] == ',')
		{
			comma.quantity++;
			switch(comma.quantity)
			{
				case 1: comma.first_pos = i; break;
				case 2: comma.second_pos = i; break;
				case 3: comma.third_pos = i; break;
			}
		}
	}
}


void print_result(Student &student, Comma &comma, string row)
{
	student.Name = row.substr(0,comma.first_pos);
	student.Surname = row.substr(comma.first_pos + 1, comma.second_pos - comma.first_pos -1);
	student.Average_mark = stof(row.substr(comma.second_pos + 1, comma.third_pos - comma.second_pos -1));
	student.Attended_lessons = stoi(row.substr(comma.third_pos + 1, row.size() - comma.third_pos - 1));

	student.Average_mark >4 && student.Attended_lessons >5 ?
		cout<<string(LINE_WIDTH/2 - 1,' ')<<"+"<<string(LINE_WIDTH/2,' ')<<'\t' : cout <<string(LINE_WIDTH, ' ')<<'\t';
	cout.width(LINE_WIDTH); cout <<left <<student.Name<<'\t';
	cout.width(LINE_WIDTH); cout <<left <<student.Surname<<'\t';
	cout.width(LINE_WIDTH); cout <<right <<setprecision(3)<<student.Average_mark<<'\t';
	cout<<string(LINE_WIDTH/2 + 1,' ')<<student.Attended_lessons <<endl;
}

int main()
{
	string row;
	ifstream file ("source.txt");
	Student student;
	Comma comma;
	print_table_header();

	if(file)
	{
	
		while (getline(file,row))
		{
			comma.quantity = 0;
			comma.first_pos = 0;
			comma.second_pos = 0;
			comma.third_pos = 0;
	
			comma_processing(comma, row);

			if(comma.quantity == NUMCOMMA)
			{
				print_result(student, comma, row);
			}
			else
			{
				cout<<"Bad source data"<<endl;
			}
		}
	}
	else
	{
		cout<<"File doesn't exist"<<endl;
	}
	return 0;
}


