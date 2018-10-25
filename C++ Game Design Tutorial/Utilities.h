#pragma once

template <typename X> void safeDelete(X toDelete)
{
	if (toDelete != NULL)
		delete toDelete;
}