#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ����ѧ���ṹ��
struct Student {
	int id;
	std::string name;
	float grade;
};

// ��ӡѧ����Ϣ
void printStudent(const Student& student) {      //const ��ʾ�ú��������޸Ĵ���Ĳ���
	std::cout << "ID: " << student.id
		<< ", Name: " << student.name
		<< ", Grade: " << student.grade << std::endl;
}

// ���ѧ��
void addStudent(std::vector<Student>& students) {
	Student s;
	std::cout << "Enter Student ID: ";
	std::cin >> s.id;
	std::cout << "Enter Student Name: ";
	std::cin.ignore(); // ����֮ǰ����Ļ��з�
	std::getline(std::cin, s.name);
	std::cout << "Enter Student Grade: ";
	std::cin >> s.grade;
	students.push_back(s);
	std::cout << "Student added successfully.\n";
}

// ɾ��ѧ��
void deleteStudent(std::vector<Student>& students) {
	int id;
	std::cout << "Enter Student ID to delete: ";
	std::cin >> id;

	auto it = std::find_if(students.begin(), students.end(), [id](const Student& s) {
		return s.id == id;
		});

	if (it != students.end()) {
		students.erase(it);
		std::cout << "Student deleted successfully.\n";
	}
	else {
		std::cout << "Student with ID " << id << " not found.\n";
	}
}

// ��ʾ����ѧ��
void displayStudents(const std::vector<Student>& students) {
	if (students.empty()) {
		std::cout << "No students available.\n";
		return;
	}
	std::cout << "Student List:\n";
	for (const auto& s : students) {
		printStudent(s);
	}
}

// ����ѧ��
void findStudent(const std::vector<Student>& students) {
	int id;
	std::cout << "Enter Student ID to find: ";
	std::cin >> id;

	auto it = std::find_if(students.begin(), students.end(), [id](const Student& s) {
		return s.id == id;
		});

	if (it != students.end()) {
		std::cout << "Student Found:\n";
		printStudent(*it);
	}
	else {
		std::cout << "Student with ID " << id << " not found.\n";
	}
}

int main() {
	std::vector<Student> students;
	int choice;

	do {
		std::cout << "\n=== Student Management System ===\n";
		std::cout << "1. Add Student\n";
		std::cout << "2. Delete Student\n";
		std::cout << "3. Display All Students\n";
		std::cout << "4. Find Student by ID\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice (1-5): ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			addStudent(students);
			break;
		case 2:
			deleteStudent(students);
			break;
		case 3:
			displayStudents(students);
			break;
		case 4:
			findStudent(students);
			break;
		case 5:
			std::cout << "Exiting the system.\n";
			break;
		default:
			std::cout << "Invalid choice. Please choose between 1-5.\n";
		}

	} while (choice != 5);

	return 0;
}