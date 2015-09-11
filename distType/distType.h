//Last Modified Wei Shi 5/14/2015

#ifndef DIST_TYPE_H
#define DIST_TYPE_H

#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;


class DistType
{
	private:
		double distance;

		bool infinity;

	public:

		DistType();
		DistType(const DistType & d);
		DistType(DistType && d);
		DistType(double const & n);
		DistType(double && n);


		DistType & operator=(const string & rhs);
		DistType & operator=(string && rhs);

		DistType & operator=(double && rhs);
		DistType & operator=(const double & rhs);

		DistType & operator=(const DistType & rhs);
		DistType & operator=(DistType && rhs);

		bool operator!=(const DistType & d) const;
		bool operator!=(DistType && d) const;


		bool operator<(const DistType & d);
		bool operator<(DistType && d);

		//overwrites infinity if left operand has distance of infinity.
		DistType operator+(const DistType & d) const;
		DistType operator+(DistType && d) const;

		//DistType & operator+(const double & rhs);
		//DistType & operator+(double && rhs);


		const double & getDistance() const;

		bool isInfinity();

		void print(ostream & out) const;


		template<typename friendtype>
		friend class vertex;

		//left param = output 
		//right param = object to be outputed
		//out << dt
		friend ostream& operator<<(ostream & out, const DistType dt);
};




#include "distType.cpp"





#endif
