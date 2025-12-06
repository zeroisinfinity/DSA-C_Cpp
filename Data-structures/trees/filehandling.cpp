#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

class Student{//b2
	

		
		
	public:
	
		string stud_name;
		int roll_no;
		char div;
		string address;
		
		void get_details(){//b3
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout << "Enter the Student's Name :- " ;
			getline(cin,stud_name);
			cout << "Enter Roll no. :- ";
			cin >> roll_no;
			cin.ignore();
			cout << "Enter div :- ";
			cin >> div;
			cout << "Enter address :- ";
			cin.ignore();
			getline(cin , address);		
			cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			
		}//b3
		
};//b2

/*ios_base::openmode get_modebits( &modemap , no_of_modes ){//b4
		
		ios_base::openmode*/ 
//b4
void initializer( fstream& fobj ){//b5
		fobj << "+-------------------------------------------------------------------+\n"
		 	 << "|   " << "Roll No." << "   |   " << "Student Name" << "   |   " << "Div" << "   |        " << "Address" << "        |\n"
		 	 << "+-------------------------------------------------------------------+\n";
}//b5
void append_details( fstream& fobj , Student&  student ){//b4
		fobj << "|   " << student.roll_no << "   |   " << student.stud_name << "   |   " << student.div << "   |        " << student.address << "        |\n"
			<< "+-------------------------------------------------------------------+\n";
			
}//b4
int main(){//b1
	Student s1;
	s1.get_details();
	fstream f;
	f.open("example.txt" , ios::out);
	initializer(f);
	append_details(f,s1);
	f.close();
	
return 0;
}//b1
