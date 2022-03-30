#ifndef NAME_H
#define NAME_H

namespace sdds
{
	const int Maximum = 45;

	class Name
	{
	private:
		char* First_Name{};
		char* Middle_Name{};
		char* Last_Name{};

	public:
		Name();
		Name(const char* firstName);
		Name(const char* firstName, const char* middleName);
		Name(const char* firstName, const char* middleName, const char* lastName);


		//RULES OF THREE
		Name(const Name& name);
		Name& operator=(const Name& name);
		~Name();

		void setShort(bool pass);

		// adding a cString
		Name& operator+=(const char* addString);


		operator bool() const;

		//const char* theFirstName() const;

		//const char* theMiddleName() const;

		//const char* theLastName() const;

		// functions for iostream
		std::istream& read(std::istream& istr);

		std::ostream& display(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& istr, Name& name);

	std::ostream& operator<<(std::ostream& ostr, const Name& name);

}


#endif // !NAME_H
