
#include <iostream>

#include "Miscellaneous/Container/Dynamic.hpp"

#include "Miscellaneous/EntryContainer/Dynamic.hpp"



void ContainerData(Container::Base<int> & container)
{
	std::cout << "Limit: " << container.Limit() << "\n";
	for (unsigned int i = 0; i < container.Limit(); i++)
	{
		if (i != 0) { std::cout << " "; }
		std::cout << container[i];
	}
	if (container.Limit() != 0) { std::cout << "\n"; }
}

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

void Test_Container_Base()
{
	std::cout << "Construct" << "\n";
	Container::Base<int> cont0(5);
	std::cout << "cont0: "; ContainerData(cont0);
	std::cout << "\n";
	
	std::cout << "Change" << "\n";
	for (unsigned int i = 0; i < cont0.Limit(); i++) { cont0[i] = i; }
	std::cout << "cont0: "; ContainerData(cont0);
	std::cout << "\n";

	std::cout << "Release" << " " << "Constructor" << "\n";
	Container::Base<int> cont1(cont0.Release());
	std::cout << "cont0: "; ContainerData(cont0);
	std::cout << "cont1: "; ContainerData(cont1);
	std::cout << "\n";

	std::cout << "Release" << " " << "operator=" << "\n";
	Container::Base<int> cont2;
	cont2 = cont1.Release();
	std::cout << "cont1: "; ContainerData(cont1);
	std::cout << "cont2: "; ContainerData(cont2);
	std::cout << "\n";

	std::cout << "Release" << " " << "other" << "\n";
	Container::Base<int> cont3;
	cont2.ReleaseTo(cont3);
	std::cout << "cont2: "; ContainerData(cont2);
	std::cout << "cont3: "; ContainerData(cont3);
	std::cout << "\n";
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



void Test_EntryContainer_Dynamic()
{
	EntryContainer::Dynamic<int> container;
	//container.ShowData();
	container.ShowEntrys();

	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent0(container, 4);
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent1(container, 3);
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent2(container, 2);
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent3(container, 5);
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent4(container, 5);
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent0.Length(); i++) { ent0[i] = 1; }
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent1.Length(); i++) { ent1[i] = 2; }
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent2.Length(); i++) { ent2[i] = 3; }
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent3.Length(); i++) { ent3[i] = 4; }
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent4.Length(); i++) { ent4[i] = 5; }
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Dispose\n";
	ent1.Dispose();
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Dispose\n";
	ent3.Dispose();
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent0.Length(); i++) { ent0[i] = 10; }
	for (unsigned int i = 0; i < ent2.Length(); i++) { ent2[i] = 20; }
	for (unsigned int i = 0; i < ent4.Length(); i++) { ent4[i] = 30; }
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Is Compact " << container.IsCompact() << "\n";
	std::cout << "\n";

	std::cout << "Compact Here\n";
	//container.MakeCompact();
	container.CompactHere();
	//container.ShowData();
	container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Is Compact " << container.IsCompact() << "\n";
	std::cout << "\n";

	//std::cout << "Allocate\n";
	//ent1.Allocate(container, 9);
	////container.ShowData();
	//std::cout << "\n";

	//std::cout << "Change\n";
	//for (unsigned int i = 0; i < ent1.Length(); i++) { ent1[i] = 9; }
	////container.ShowData();
	//std::cout << "\n";
}



int main()
{
	//Test_Container_Base();
	//Test_Container_Fixed();
	//Test_Container_Fit();
	Test_Container_Binary();

	//Test_EntryContainer_Dynamic();

	std::cout << "\nmain() return\n";
	return 0;
}
