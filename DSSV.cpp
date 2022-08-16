#include <bits/stdc++.h>
#include <chrono>
#include <unistd.h>
#include <fstream>
using namespace std;
struct student
{
	string position;
	string id;
	string name;
	int age;
	char gender;
	float math_score;
	float chem_score;
	float phys_score;
	float avg;
	string overall;
};
void swap(double a, double b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
}
void input(student students[], int &size, bool &input_check);
void search_by_id(student students[], int size, bool input_check);
void update_by_ID(student students[], int size, bool input_check);
void output_all_student(student students[], int size, bool input_check);
void sort_students(student students[], int size, bool input_check);
void best(student students[], int size, bool input_check);
void add_students(student students[], int &size, bool input_check);
void sync_data(student students[], int size, bool input_check){
	
}
void countdown()
{
	cout << "Thank you for using my software! Please comeback soon UwU" << endl;
	for (int i = 5; i >= 1; i--)
	{
		cout << i << endl;
		sleep(1);
	}
}
void docx(student students[], int size, bool input_check);
int main()
{	
	start:
	cout << "Press enter to continue!" << endl;
	if ( cin.get() != '\n'){
		cout << "Invalid, please try again!";
		goto start;
	}
	int mode;
	int size;
	student students[size];
	bool input_check = false;
repeat_choosing:
	cout << "Choose your service!" << endl
		 << "1.Input students' info." << endl
		 << "2.Input additional students." << endl
		 << "3.Search student by ID" << endl
		 << "4.Update student's info by ID" << endl
		 << "5.Output all students' info" << endl
		 << "6.Sort and output students' info" << endl
		 << "7.Ouput best student" << endl
		 << "8.Write into txt file" << endl
		 << "9.Exit" << endl;
	cin >> mode;
	switch (mode)
	{
	case 1:
		input(students, size, input_check);
		goto repeat_choosing;
		break;
	case 2:
		add_students(students, size, input_check);
		goto repeat_choosing;
		break;
	case 3:
		if (input_check == false)
		{
			cout << "No infomation in database! Please try again!" << endl;
			goto repeat_choosing;
		}
		else
		{
			search_by_id(students, size, input_check);
			goto repeat_choosing;
		}
		break;
	case 4:
		if (input_check == false)
		{
			cout << "No infomation in database! Please try again!" << endl;
			goto repeat_choosing;
		}
		else
		{
			update_by_ID(students, size, input_check);
			goto repeat_choosing;
		}
		break;
	case 5:
		if (input_check == false)
		{
			cout << "No infomation in database! Please try again!" << endl;
			goto repeat_choosing;
		}
		else
		{
			output_all_student(students, size, input_check);
			goto repeat_choosing;
		}
		break;
	case 6:
		if (input_check == false)
		{
			cout << "No infomation in database! Please try again!" << endl;
			goto repeat_choosing;
		}
		else
		{
			sort_students(students, size, input_check);
			goto repeat_choosing;
		}
		break;
	case 8:
		if (input_check == false)
		{
			cout << "No infomation in database! Please try again!" << endl;
			goto repeat_choosing;
		}
		else
		{
			docx(students, size, input_check);
			cout << "Your file is ready!" << endl;
			goto repeat_choosing;
		}
		break;
	case 7:
		if (input_check == false)
		{
			cout << "No infomation in database! Please try again!" << endl;
			goto repeat_choosing;
		}
		else
		{
			best(students, size, input_check);
			goto repeat_choosing;
		}
		break;
	case 9:
		countdown();
		break;
	default:
		cout << "Invalid choice! Please try again!" << endl;
		goto repeat_choosing;
		break;
	}
	return 0;
}
void input(student students[], int &size, bool &input_check)
{
repeat_input:
	cout << "Input the quantity of students: " << endl;
	cin >> size;
	if (size <= 0)
	{
		cout << "Invalid number!, please try again" << endl;
		goto repeat_input;
	}
	else
	{
		input_check = true;
	}
	for (int i = 0; i < size; i++)
	{
		cout << "Input student #" << i + 1 << "'s name:" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, students[i].name);
		cout << "Input student #" << i + 1 << "'s identification numbers:" << endl;
		cin >> students[i].id;
		cout << "Input student #" << i + 1 << "'s age:" << endl;
		cin >> students[i].age;
	repeat_gender:
		cout << "Input student #" << i + 1 << "'s gender: (M|F)" << endl;
		cin >> students[i].gender;
		if (students[i].gender != 'M' && students[i].gender != 'F')
		{
			cout << "Syntax error! Please try again." << endl;
			goto repeat_gender;
		}
	repeat_math:
		cout << "Input student #" << i + 1 << "'s Mathematics score:" << endl;
		cin >> students[i].math_score;
		if (students[i].math_score > 10 || students[i].math_score < 0)
		{
			cout << "Syntax error! Please try again." << endl;
			goto repeat_math;
		}
	repeat_chem:
		cout << "Input student #" << i + 1 << "'s Chemistry score:" << endl;
		cin >> students[i].chem_score;
		if (students[i].chem_score > 10 || students[i].chem_score < 0)
		{
			cout << "Syntax error! Please try again." << endl;
			goto repeat_chem;
		}
	repeat_phys:
		cout << "Input student #" << i + 1 << "'s Physics score:" << endl;
		cin >> students[i].phys_score;
		if (students[i].phys_score > 10 || students[i].phys_score < 0)
		{
			cout << "Syntax error! Please try again." << endl;
			goto repeat_phys;
		}
	}
}
void add_students(student students[], int &size, bool input_check)
{
	if (input_check == false)
	{
		cout << "Database is null.Please input students' infomation." << endl;
	}
	else
	{
		cout << "Enter the quantity of students: " << endl;
		int add_size;
		cin >> add_size;
		int old_size = size;
		size += add_size;
		for (int i = old_size; i < size; i++)
		{
			cout << "Input student #" << i + 1 << "'s name:" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			getline(cin, students[i].name);
			cout << "Input student #" << i + 1 << "'s identification numbers:" << endl;
			cin >> students[i].id;
			cout << "Input student #" << i + 1 << "'s age:" << endl;
			cin >> students[i].age;
		repeat_gender:
			cout << "Input student #" << i + 1 << "'s gender: (M|F)" << endl;
			cin >> students[i].gender;
			if (students[i].gender != 'M' && students[i].gender != 'F')
			{
				cout << "Syntax error! Please try again." << endl;
				goto repeat_gender;
			}
		repeat_math:
			cout << "Input student #" << i + 1 << "'s Mathematics score:" << endl;
			cin >> students[i].math_score;
			if (students[i].math_score > 10 || students[i].math_score < 0)
			{
				cout << "Syntax error! Please try again." << endl;
				goto repeat_math;
			}
		repeat_chem:
			cout << "Input student #" << i + 1 << "'s Chemistry score:" << endl;
			cin >> students[i].chem_score;
			if (students[i].chem_score > 10 || students[i].chem_score < 0)
			{
				cout << "Syntax error! Please try again." << endl;
				goto repeat_chem;
			}
		repeat_phys:
			cout << "Input student #" << i + 1 << "'s Physics score:" << endl;
			cin >> students[i].phys_score;
			if (students[i].phys_score > 10 || students[i].phys_score < 0)
			{
				cout << "Syntax error! Please try again." << endl;
				goto repeat_phys;
			}
		}
	}
}
void search_by_id(student students[], int size, bool input_check)
{
	if (input_check == false)
	{
		cout << "Database is null.Please input students' infomation." << endl;
	}
	else
	{
		cout << "Which students would you like to view? (Input ID)" << endl;
		string search_id;
		cin >> search_id;
		for (int i = 0; i < size; i++)
		{
			if (students[i].id == search_id)
			{
				cout << "Name: " << students[i].name << endl;
				cout << "Age: " << students[i].age << endl;
				cout << "Gender: ";
				if (students[i].gender == 'M')
				{
					cout << "Male" << endl;
				}
				else if (students[i].gender == 'F')
				{
					cout << "Female" << endl;
				}
				cout << "Maths score: " << students[i].math_score << endl;
				cout << "Chemistry score: " << students[i].chem_score << endl;
				cout << "Physics score: " << students[i].phys_score << endl;
				students[i].avg = (students[i].math_score + students[i].chem_score + students[i].phys_score) / 3.0;
				cout << "Grade point average: " << students[i].avg << endl;
				if (students[i].avg >= 9.0)
				{
					students[i].overall = "Excellent";
				}
				else if (students[i].avg >= 8.0)
				{
					students[i].overall = "Great";
				}
				else if (students[i].avg >= 6.5)
				{
					students[i].overall = "Good";
				}
				else if (students[i].avg >= 5.0)
				{
					students[i].overall = "Average";
				}
				else if (students[i].avg >= 3.0)
				{
					students[i].overall = "Bad";
				}
				else if (students[i].avg < 1.0)
				{
					students[i].overall = "Unqualified";
				}
				cout << "Overall assessment: " << students[i].overall << endl;
				break;
			}
		}
	}
}
void update_by_ID(student students[], int size, bool input_check)
{
	if (input_check == false)
	{
		cout << "Database is empty. Please input students' infomation." << endl;
	}
	else
	{
	repeat_id_search:
		cout << "Which student you would like to update info? (Input ID)" << endl;
		string update_by_ID;
		cin >> update_by_ID;
		bool found = false;
		for (int i = 0; i < size; i++)
		{
			if (students[i].id == update_by_ID)
			{
				found = true;
			another_option:
				cout << "Choose which element to update:" << endl
					 << "1.Name" << endl
					 << "2.Age" << endl
					 << "3.Gender" << endl;
				cout << "4.Mathematics score" << endl
					 << "5.Chemistry score" << endl
					 << "6.Physics score" << endl
					 << "7.Exit" << endl;
				int update_mode;
				cin >> update_mode;
				switch (update_mode)
				{
				case 1:
					cout << "Student #" << students[i].id << " name would be: " << endl;
					cin.clear();
					cin.ignore(1000, '\n');
					getline(cin, students[i].name);
					goto another_option;
					break;
				case 2:
					cout << "Student #" << students[i].id << " age would be: " << endl;
					cin >> students[i].age;
					goto another_option;
					break;
				case 3:
					cout << "Student #" << students[i].id << " gender would be(M|F): " << endl;
					cin >> students[i].gender;
					goto another_option;
					break;
				case 4:
					cout << "Student #" << students[i].id << " Mathematics score would be: " << endl;
					cin >> students[i].math_score;
					goto another_option;
					break;
				case 5:
					cout << "Student #" << students[i].id << " Chemistry score would be: " << endl;
					cin >> students[i].chem_score;
					goto another_option;
				case 6:
					cout << "Student #" << students[i].id << " Physics score would be: " << endl;
					cin >> students[i].phys_score;
					goto another_option;
					break;
				case 7:
					break;
				default:
					cout << "Option does not exist! Please try again!";
					goto repeat_id_search;
					break;
				}
			}
			break;
		}
		if (found == false)
		{
			cout << "ID does not exist in database. Please try again!" << endl;
			goto repeat_id_search;
		}
	}
}
void output_all_student(student students[], int size, bool input_check)
{
	if (input_check == false)
	{
		cout << "Database is null.Please input students' infomation." << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << "." << endl;
			cout << "Name: " << students[i].name << endl;
			cout << "Age: " << students[i].age << endl;
			cout << "Gender: ";
			if (students[i].gender == 'M')
			{
				cout << "Male" << endl;
			}
			else if (students[i].gender == 'F')
			{
				cout << "Female" << endl;
			}
			cout << "Maths score: " << students[i].math_score << endl;
			cout << "Chemistry score: " << students[i].chem_score << endl;
			cout << "Physics score: " << students[i].phys_score << endl;
			students[i].avg = (students[i].math_score + students[i].chem_score + students[i].phys_score) / 3.0;
			cout << "Grade point average: " << students[i].avg << endl;
			if (students[i].avg >= 9.0)
			{
				students[i].overall = "Excellent";
			}
			else if (students[i].avg >= 8.0)
			{
				students[i].overall = "Great";
			}
			else if (students[i].avg >= 6.5)
			{
				students[i].overall = "Good";
			}
			else if (students[i].avg >= 5.0)
			{
				students[i].overall = "Average";
			}
			else if (students[i].avg >= 3.0)
			{
				students[i].overall = "Bad";
			}
			else if (students[i].avg < 1.0)
			{
				students[i].overall = "Unqualified";
			}
			cout << "Overall assessment: " << students[i].overall << endl;
		}
	}
}
void sort_students(student students[], int size, bool input_check)
{
	if (input_check == false)
	{
		cout << "Database is null.Please input students' infomation." << endl;
	}
	else
	{
		student temp;
		for (int i = 0; i < size; i++)
		{
			students[i].avg = (students[i].math_score + students[i].chem_score + students[i].phys_score) / 3.0;
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (students[i].avg < students[j].avg)
				{
					temp = students[i];
					students[i] = students[j];
					students[j] = temp;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			cout << students[i].name << " ";
			cout << students[i].id << endl;
		}
	}
}
void best(student students[], int size, bool input_check)
{
	if (input_check == false)
	{
		cout << "Database is null.Please input students' infomation." << endl;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			students[i].avg = (students[i].math_score + students[i].chem_score + students[i].phys_score) / 3.0;
		}
		int best = students[0].avg;
		for (int i = 0; i < size; i++)
		{
			if (best < students[i].avg)
			{
				best = students[i].avg;
			}
		}
		int c = 1;
		for (int i = 0; i < size; i++)
		{
			if (best == students[i].avg)
			{
				cout << "Best student(s) " << c << " is " << students[i].name << " #" << students[i].id << endl;
				cout << "Grade point average: " << students[i].avg << endl;
				c++;
			}
		}
	}
}
void docx(student students[], int size, bool input_check){
	ofstream students_list("Students list.docx");
	for (int i = 0; i < size; i++)
	{
		students_list << i + 1 << "." << endl;
		students_list << "Name: " << students[i].name << endl;
		students_list << "Age: " << students[i].age << endl;
		students_list << "Gender: ";
		if (students[i].gender == 'M')
		{
			students_list << "Male" << endl;
		}
		else if (students[i].gender == 'F')
		{
			students_list << "Female" << endl;
		}
		students_list << "Maths score: " << students[i].math_score << endl;
		students_list << "Chemistry score: " << students[i].chem_score << endl;
		students_list << "Physics score: " << students[i].phys_score << endl;
		students[i].avg = (students[i].math_score + students[i].chem_score + students[i].phys_score) / 3.0;
		students_list << "Grade point average: " << students[i].avg << endl;
		if (students[i].avg >= 9.0)
		{
			students[i].overall = "Excellent";
		}
		else if (students[i].avg >= 8.0)
		{
			students[i].overall = "Great";
		}
		else if (students[i].avg >= 6.5)
		{
			students[i].overall = "Good";
		}
		else if (students[i].avg >= 5.0)
		{
			students[i].overall = "Average";
		}
		else if (students[i].avg >= 3.0)
		{
			students[i].overall = "Bad";
		}
		else if (students[i].avg < 1.0)
		{
			students[i].overall = "Unqualified";
		}
		students_list << "Overall assessment: " << students[i].overall << endl;
	}
	students_list.close();
}