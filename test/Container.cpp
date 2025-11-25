
#include <iostream>

#include "Miscellaneous/Container/Dynamic.hpp"
//#include "Miscellaneous/Container/Binary.hpp"
//#include "Miscellaneous/Container/Fixed.hpp"
//#include "Miscellaneous/Container/Fit.hpp"

//#include "Miscellaneous/EntryContainer/Dynamic.hpp"



void ContainerData(Container::Dynamic<int> & container)
{
	std::cout << "Limit: " << container.Limit() << " ";
	std::cout << "Count: " << container.Count() << "\n";
	for (unsigned int i = 0; i < container.Limit(); i++)
	{
		if (i != 0) { std::cout << " "; }
		if (i < container.Count())
		{ std::cout << container[i]; }
		else
		{ std::cout << "|"; }
	}
	std::cout << "\n";
}
void ContainerInsert(Container::Dynamic<int> & container, int item)
{
	std::cout << "\n";
	unsigned int idx = container.Insert(item);
	std::cout << "insert " << item << " return " << idx << "\n";
	ContainerData(container);
}
void ContainerRemove(Container::Dynamic<int> & container, unsigned int idx)
{
	std::cout << "\n";
	int item = container.Remove(idx);
	std::cout << "remove " << idx << " return " << item << "\n";
	ContainerData(container);
}

void Test_Container_Fixed()
{
	std::cout << "################################\n";
	std::cout << "Container Fixed\n";
	std::cout << "################################\n";

	Container::Dynamic<int> container(4, Container::IncreaseBehaviour::None, Container::DecreaseBehaviour::None);
	ContainerData(container);

	ContainerInsert(container, 2);
	ContainerInsert(container, 3);
	ContainerInsert(container, 5);
	ContainerInsert(container, 7);
	ContainerInsert(container, 11);

	ContainerRemove(container, 1);
	ContainerRemove(container, 2);

	std::cout << "\n";
}
void Test_Container_Fit()
{
	std::cout << "################################\n";
	std::cout << "Container Fit\n";
	std::cout << "################################\n";
	Container::Dynamic<int> container(Container::IncreaseBehaviour::Fit, Container::DecreaseBehaviour::Fit);
	ContainerData(container);

	ContainerInsert(container, 2);
	ContainerInsert(container, 3);
	ContainerInsert(container, 5);
	ContainerInsert(container, 7);
	ContainerInsert(container, 11);

	ContainerRemove(container, 1);
	ContainerRemove(container, 2);

	std::cout << "\n";
}
void Test_Container_Binary()
{
	std::cout << "################################\n";
	std::cout << "Container Binary\n";
	std::cout << "################################\n";
	Container::Dynamic<int> container(Container::IncreaseBehaviour::Binary, Container::DecreaseBehaviour::Binary);
	ContainerData(container);

	ContainerInsert(container, 2);
	ContainerInsert(container, 3);
	ContainerInsert(container, 5);
	ContainerInsert(container, 7);
	ContainerInsert(container, 11);

	ContainerRemove(container, 1);
	ContainerRemove(container, 2);

	std::cout << "\n";
}



/*
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
*/



int main()
{
	Test_Container_Fixed();
	Test_Container_Fit();
	Test_Container_Binary();

	//Test_EntryContainer_Dynamic();

	std::cout << "\nmain() return\n";
	return 0;
}
