#include "File.hpp"
#include "EmployeeAVLTree.hpp"
#include "Employee.hpp"
#include "CompanyAVLTree.hpp"
#include "Company.hpp"

File::File()
{
}

EmployeeAVLTree *employeeAVLTree = new EmployeeAVLTree();
CompanyAVLTree *companyAVLTree = new CompanyAVLTree();
Employee *employee = new Employee();
Company *company = new Company();

void File::Read(string &filePath) const
{
	ifstream file(filePath);
	string row;
	string companyName = "";

	int j = 0;
	if (file.is_open())
	{
		while (getline(file, row))
		{
			int rowLenght = row.length()+1;

			char rowArray[rowLenght];
			strcpy(rowArray, row.c_str());

			char *token = strtok(rowArray, "#");
			string info[3];
			int i = 0;

			while (token != NULL)
			{
				info[i] = token;
				token = strtok(NULL, "#");
				i++;
			}

			employee->setCompanyName(info[0]);
			employee->setNameSurname(info[1]);
			int yearsOfWork = stoi(info[2]);
			employee->setYearsOfWork(yearsOfWork);

			int deneme = 1;
			company->SetName(info[0]);
			company->SetEmployeeCount(deneme);

			deneme++;

			//companyAVLTree->Add(company, employee);

			employeeAVLTree->Add(employee->getCompanyName(), employee->getNameSurname(), employee->getYearsOfWork());
		}

		cout << endl;
		employeeAVLTree->PostOrder();
		//companyAVLTree->PostOrder();
		cout << endl;
		employeeAVLTree->Clear();
		companyAVLTree->Clear();
	}
}

File::~File()
{
}