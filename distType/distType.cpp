//Last Modified Wei Shi 5/14/2015


DistType::DistType(): infinity{true}
{

}


DistType::DistType(const DistType & d): distance{d.distance}, infinity{d.infinity}
{

}

DistType::DistType(DistType && d): distance{std::move(d.distance)}, infinity{std::move(d.infinity)}
{

}

DistType::DistType(double const & n): distance{n}, infinity{false}
{

}

DistType::DistType(double && n): distance{std::move(n)}, infinity{false}
{

}

bool DistType::isInfinity()
{
	return infinity;

}
DistType & DistType::operator=(const string & rhs)
{
	if(rhs == "infinity")
		infinity = true;

}

DistType & DistType::operator=(string && rhs)
{
	if(rhs == "infinity")
		infinity = true;

}

DistType & DistType::operator=(double && rhs)
{

	distance = std::move(rhs);

	infinity = false;

}

DistType & DistType::operator=(const double & rhs) 
{

	distance = rhs;

	infinity = false;

}


DistType & DistType::operator=(const DistType & rhs) 
{
	distance = rhs.distance;
	infinity = rhs.infinity;

	return *this;

}



DistType & DistType::operator=(DistType && rhs)
{
	distance = std::move(rhs.distance);
	infinity = std::move(rhs.infinity);

	return *this;


}


bool DistType::operator!=(const DistType & d) const
{

	

	return ((distance != d.distance) && (infinity != d.infinity));

}

bool DistType::operator!=(DistType && d) const
{

	return ((distance != std::move(d.distance)) && (infinity != std::move(d.infinity)));

}


DistType DistType::operator+(const DistType & d) const
{

	if(!infinity && !d.infinity)
	{

		DistType toReturn;

		toReturn.distance = distance + d.distance;

		toReturn.infinity = false;

		return toReturn;


	}


	DistType toReturn;

	toReturn.distance = distance + d.distance;

	toReturn.infinity = true;

	return toReturn;







}


DistType DistType::operator+(DistType && d) const
{

	if(!infinity && !d.infinity)
	{

		DistType toReturn;

		toReturn.distance = distance + d.distance;

		toReturn.infinity = false;

		return toReturn;


	}


	DistType toReturn;

	toReturn.distance = distance + d.distance;

	toReturn.infinity = true;

	return toReturn;





}

/*
DistType & DistType::operator+(const double & rhs)
{
	if(!infinity)
		distance = distance + rhs;

	else
		distance = rhs;

	infinity = false;

	return *this;
}

DistType & DistType::operator+(double && rhs)
{
	if(!infinity)
		distance = distance + std::move(rhs);

	else
		distance = rhs;

	infinity = false;

	return *this;

}
*/

bool DistType::operator<(const DistType & d)
{
/*
	cout << "\ndistance: " << distance << endl;

	cout << "d.distance: " << d.distance << endl;

	cout << "infinity: " << infinity << endl;

	cout << "d.infinity: " << d.infinity << endl;
*/
	if(!infinity && d.infinity)
		return true;

	else if(infinity && !d.infinity)
		return false;

	else if(!infinity && !d.infinity)
		return (distance < d.distance);

	return false;

}


bool DistType::operator<(DistType && d)
{
/*
	cout << "\ndistance: " << distance << endl;

	cout << "d.distance: " << d.distance << endl;

	cout << "infinity: " << infinity << endl;

	cout << "d.infinity: " << d.infinity << endl;
*/
	if(!infinity && d.infinity)
		return true;

	else if(infinity && !d.infinity)
		return false;

	else if(!infinity && !d.infinity)
		return (distance < d.distance);

	return false;

}

const double & DistType::getDistance() const
{

	if(infinity)
		throw runtime_error{"Error: Distance is infinity!"};

	return distance;


}

void DistType::print(ostream & out) const
{

	if(!infinity)
		out << distance;

	else
		out << "infinity";

}


//////////////////////////////////
//
//					operator<<
//
//////////////////////////////////
ostream & operator<<(ostream & out, const DistType dt) 
{
	dt.print(out);

  return out; //returns outstream so you can concatenate outputs.


}

