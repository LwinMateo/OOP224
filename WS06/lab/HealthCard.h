#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds
{

    const int MaxNameLength = 55;

    class HealthCard
    {
        // When m_name is null, then the object is in an empty state.
        char* m_name{};
        long long m_number = 0;
        char m_vCode[3]{};
        char m_sNumber[10]{};
    public:

        //Initialized constructor
        HealthCard();
        HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]);

        bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;

        void setEmpty();
        void allocateAndCopy(const char* name);

        void extractChar(std::istream& istr, char) const;
        std::ostream& printIDInfo(std::ostream& ostr)const;


        void set(const char* name, long long number, const char vCode[], const char sNumber[]);

        const char* getName() const;
        long long getNumber() const;
        const char* getVCode() const;
        const char* getSNumber() const;


        //RULES OF THREE
        HealthCard(const HealthCard& hc);
        HealthCard& operator=(const HealthCard& hc);
        ~HealthCard();

        operator bool() const;

        std::ostream& print(std::ostream& ostr, bool toFile = true) const;

        std::istream& read(std::istream& istr);

    };

    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc);

    std::istream& operator>>(std::istream& istr, HealthCard& hc);
}
#endif // !SDDS_HealthCard_H