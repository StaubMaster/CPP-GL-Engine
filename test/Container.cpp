
#include <iostream>

#include "Miscellaneous/Container/Binary.hpp"
#include "Miscellaneous/EntryContainer/Dynamic.hpp"

void Test_Container_Binary()
{
	Container::Binary container;

	
}

void Test_EntryContainer_Dynamic()
{
	EntryContainer::Dynamic<int> container;
	container.ShowData();
	EntryContainer::Entry<int> * ent0 = container.Alloc(4);
	container.ShowData();
	EntryContainer::Entry<int> * ent1 = container.Alloc(3);
	container.ShowData();
	EntryContainer::Entry<int> * ent2 = container.Alloc(2);
	container.ShowData();
	for (unsigned int i = 0; i < ent0 -> Length; i++) { (*ent0)[i] = 1; }
	container.ShowData();
	for (unsigned int i = 0; i < ent1 -> Length; i++) { (*ent1)[i] = 2; }
	container.ShowData();
	for (unsigned int i = 0; i < ent2 -> Length; i++) { (*ent2)[i] = 3; }
	container.ShowData();
	ent1 -> Dispose();
	container.ShowData();
}

int main()
{
	Test_Container_Binary();
	//Test_EntryContainer_Dynamic();
	std::cout << "\nmain() return\n";
	return 0;
}
