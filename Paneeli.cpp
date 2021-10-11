#include "Paneeli.h"

using namespace std;

Paneeli::Paneeli()
{}

void Paneeli::valo(bool b)
{	
	if (b) cout << "---- GREEN ----\n";
	else cout << "---- RED ----\n";
}
