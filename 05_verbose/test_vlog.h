#pragma once

#include <glog/logging.h>

void foo_vlog()
{
	VLOG(1) << " test_vlog: I'm printed when you run the program with --v=1 or higher";
}