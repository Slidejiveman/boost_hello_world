// Boost_Test.cpp : Defines the entry point for the console application.
// Reference: https://stackoverflow.com/questions/999120/c-hello-world-boost-tee-example-program

#include "stdafx.h"
#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include <fstream>
#include <iostream>

using std::ostream;
using std::ofstream;
using std::cout;

namespace bio = boost::iostreams;
using bio::tee_device;
using bio::stream;

/* Outputs to standard out and to the console
 * simulatenously. This relies on the tee_filter 
 * and tee device Boost class templates. */
int main()
{
	typedef tee_device<ostream, ofstream> TeeDevice;
	typedef stream<TeeDevice> TeeStream;
	ofstream ofs("sample.txt");
	TeeDevice my_tee(cout, ofs);
	TeeStream my_split(my_tee);
	my_split << "Hello, World!\n";
	my_split.flush();
	my_split.close();
    return 0;
}

