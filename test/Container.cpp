
#include <iostream>

#include "Miscellaneous/Container/Dynamic.hpp"

#include "Miscellaneous/EntryContainer/Dynamic.hpp"

#include "../src/Miscellaneous/Container/Behaviour.cpp"



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
	bool ret = container.Insert(item);
	std::cout << "insert " << item << " return " << ret << "\n";
	ContainerData(container);
}
void ContainerRemove(Container::Dynamic<int> & container, unsigned int idx)
{
	std::cout << "\n";
	bool ret = container.Remove(idx);
	std::cout << "remove " << idx << " return " << ret << "\n";
	ContainerData(container);
}

void ContainerData(EntryContainer::Dynamic<int> & container)
{
	std::cout << "Limit: " << container.Limit() << "\n";
	std::cout << "Count: " << container.Count() << "\n";
	for (unsigned int i = 0; i < container.Limit(); i++)
	{
		if (i != 0) { std::cout << " "; }
		std::cout << container[i];
	}
	if (container.Limit() != 0) { std::cout << "\n"; }
}



void Test_Contnainer_Function_Resize()
{
	std::cout << "################################\n";
	std::cout << "Container Function Resize\n";
	std::cout << "################################\n";

	Container::Dynamic<int> cont;
	cont.Insert(0);
	cont.Insert(1);
	cont.Insert(2);

	ContainerData(cont);
	std::cout << "##  " << "ResizeLimit(12)" << '\n';
	cont.ResizeLimit(12);
	ContainerData(cont);
}
void Test_Contnainer_Function_InsertGap()
{
	std::cout << "################################\n";
	std::cout << "Container Function InsertGap\n";
	std::cout << "################################\n";

	Container::Dynamic<int> cont;
	cont.Insert(0);
	cont.Insert(1);
	cont.Insert(2);
	cont.Insert(3);
	cont.Insert(4);
	cont.ResizeLimit(12);

	ContainerData(cont);
	std::cout << "##  " << "InsertGap(Container::Entry(2, 3))" << '\n';
	cont.InsertGap(Container::Entry(2, 3));
	ContainerData(cont);
}
void Test_Contnainer_Function_RemoveGap()
{
	std::cout << "################################\n";
	std::cout << "Container Function RemoveGap\n";
	std::cout << "################################\n";

	Container::Dynamic<int> cont;
	cont.Insert(0);
	cont.Insert(1);
	cont.Insert(2);
	cont.Insert(3);
	cont.Insert(4);
	cont.Insert(5);
	cont.Insert(6);
	cont.Insert(7);
	cont.Insert(8);

	ContainerData(cont);
	std::cout << "##  " << "RemoveGap(Container::Entry(3, 3))" << '\n';
	cont.RemoveGap(Container::Entry(3, 3));
	ContainerData(cont);
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

	std::cout << "Swap" << " " << "Constructor" << "\n";
	Container::Base<int> cont1;;
	cont0.Swap(cont1);
	std::cout << "cont0: "; ContainerData(cont0);
	std::cout << "cont1: "; ContainerData(cont1);
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
	ContainerData(container);
	//container.ShowEntrys();

	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent0(container, 4);
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent1(container, 3);
	//container.ShowEntrys();
	ContainerData(container);
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent2(container, 2);
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent3(container, 5);
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent4(container, 5);
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent0.Length(); i++) { ent0[i] = 1; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent1.Length(); i++) { ent1[i] = 2; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent2.Length(); i++) { ent2[i] = 3; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent3.Length(); i++) { ent3[i] = 4; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent4.Length(); i++) { ent4[i] = 5; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Dispose\n";
	ent1.Dispose();
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Dispose\n";
	ent3.Dispose();
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent0.Length(); i++) { ent0[i] = 10; }
	for (unsigned int i = 0; i < ent2.Length(); i++) { ent2[i] = 20; }
	for (unsigned int i = 0; i < ent4.Length(); i++) { ent4[i] = 30; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
	
	std::cout << "Is Compact " << container.IsCompact() << "\n";
	std::cout << "\n";

	std::cout << "Compact Here\n";
	//container.MakeCompact();
	container.CompactHere();
	ContainerData(container);
	//container.ShowEntrys();
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
void Test_EntryContainer_EntryCopy()
{
	EntryContainer::Dynamic<int> container;
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Allocate\n";
	EntryContainer::Entry<int> ent0(container, 4);
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	//std::cout << "Copy\n";
	//EntryContainer::Entry<int> ent1(ent0);
	//ContainerData(container);
	//container.ShowEntrys();
	//std::cout << "\n";

	std::cout << "Copy\n";
	EntryContainer::Entry<int> ent2;
	ent2 = ent0;
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Change\n";
	for (unsigned int i = 0; i < ent0.Length(); i++) { ent0[i] = i; }
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Compact\n";
	container.CompactHere();
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Dispose\n";
	ent0.Dispose();
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	//std::cout << "Dispose\n";
	//ent1.Dispose();
	//ContainerData(container);
	//container.ShowEntrys();
	//std::cout << "\n";

	std::cout << "Dispose\n";
	ent2.Dispose();
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";

	std::cout << "Compact\n";
	container.CompactHere();
	ContainerData(container);
	//container.ShowEntrys();
	std::cout << "\n";
}
void Test_EntryContainer_Changed()
{
	EntryContainer::Dynamic<int> container;

	std::cout << "changed " << container.Changed << "\n";
	std::cout << "Entry()\n";
	EntryContainer::Entry<int> entry(container, 1);
	std::cout << "changed " << container.Changed << "\n";
	std::cout << '\n';

	container.Changed = false;
	std::cout << "changed " << container.Changed << "\n";
	std::cout << "Entry operator*\n";
	*entry = 123;
	std::cout << "changed " << container.Changed << "\n";
	std::cout << '\n';

	container.Changed = false;
	std::cout << "changed " << container.Changed << "\n";
	std::cout << "Entry operator[]\n";
	entry[0] = 123;
	std::cout << "changed " << container.Changed << "\n";
}



int main()
{
	//Test_Contnainer_Function_Resize();
	//Test_Contnainer_Function_InsertGap();
	//Test_Contnainer_Function_RemoveGap();

	//Test_Container_Base();
	//Test_Container_Fixed();
	//Test_Container_Fit();
	//Test_Container_Binary();

	//Test_EntryContainer_Dynamic();
	//Test_EntryContainer_EntryCopy();
	Test_EntryContainer_Changed();

	std::cout << "\nmain() return\n";
	return 0;
}
