#include "Range.h"
#include <SSTest.h>

namespace
{
	
void basicUsage()
{
	//! [getIntersection]
	RangeF a(-0.4f, 0.7f);
	RangeF result = a.getIntersection(0.0f, 1.0f);
	// Result == (0.0f, 0.7f)
	//! [getIntersection]
	SST_M_ASSERT_START;
	SST_M_ASSERT(result.Start == 0.0f);
	SST_M_ASSERT(result.End   == 0.7f);
	SST_M_ASSERT_END;
}

	
SST::SimpleTest a("Math/Range", &basicUsage,  SST::Required);
}