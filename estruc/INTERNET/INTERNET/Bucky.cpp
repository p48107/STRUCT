#include "pch.h"
#include "Bucky.h"

template<class tipo>
Bucky<tipo>::Bucky(tipo f, tipo s)
{
}

template<class tipo>
tipo Bucky<tipo>::bigger()
{
	return (first > second?first:second);
}
