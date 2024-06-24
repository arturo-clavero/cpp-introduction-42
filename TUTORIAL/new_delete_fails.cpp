#include <iostream>

void	failed_alloc_seg_fault(void)
{
	int	*large_array{};

	std::cout<<"it's about to segfault...\n";
	large_array = new int [100000000000000];
	std::cout<<"you won't see this message\n";
}

void	failed_alloc_exception_v1(void)
{
	int	*large_array{};

	try
	{
		large_array = new int [100000000000000];
	}
	catch (std::exception)
	{
		std::cout<<"Error execpt\n";
	}
}

void	failed_alloc_exception_v2(void)
{
	int	*large_array{};

	try
	{
		large_array = new int [100000000000000];
	}
	catch (std::exception& ex)
	{
		std::cout<<"Error execpt: "<<ex.what()<<std::endl;
	}
}

void	failed_alloc_nothrow(void)
{
	int	*large_array{};

	large_array = new(std::nothrow) int [100000000000000];
	if (!large_array)
		std::cout<<"Error nothrow\n";
}

void	multiple_delete_ok(void)
{
	int	*pointer {new int (2)};
	std::cout<<"\nnum is : "<<*pointer<<"\n";
	for (int i = 0; i < 1000; i++)
	{
		std::cout<<"delete, ";
		delete pointer;
		pointer = nullptr;
	}
	std::cout<<std::endl;
}


void	multiple_delete_fail(void)
{
	int	*pointer {new int (2)};
	std::cout<<"\nnum is : "<<*pointer<<"\n";
	for (int i = 0; i < 1000; i++)
	{
		std::cout<<"deleting ... \n";
		delete pointer;
	}
	std::cout<<std::endl;
}


int	main(void)
{
	failed_alloc_exception_v1();
	failed_alloc_exception_v2();
	failed_alloc_nothrow();
	multiple_delete_ok();
	//multiple_delete_fail();
	//failed_alloc_seg_fault();
	std::cout <<"\nprogram exited succesfully!\n";
}