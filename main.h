void print_table_header();
struct Student
{
	bool Type;
	string Name;
	string Surname;
	float Average_mark;
	int Attended_lessons;
};
struct Comma
{
	short quantity;
	short first_pos;
	short second_pos;
	short third_pos;

};
void comma_processing(Comma &comma, const string *row);
void print_result(Student &student, Comma &comma);
