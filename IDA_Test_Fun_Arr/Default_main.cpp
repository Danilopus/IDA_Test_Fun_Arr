#include <iostream>
#include <ctime>
#include <cstdlib>


int Get_Int();
int Get_Dbl();

int Random_Number_Int(int Range_min, int Range_max) 
{
	//srand(time(NULL));
	return Range_min + rand() % (Range_max - Range_min + 1); 
}
template <typename any_type> void Fill_Array_Random(any_type arr[], int Size, any_type Range_min, any_type Range_max)
{
	for (int i = 0; i < Size; i++)
		arr[i] = Random_Number_Int(Range_min, Range_max);
}
template <typename any_type> void Array_COUT(any_type arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename any_type> void clear_arr(any_type arr[], int Size, any_type Key_Value)
{
	int key_counter=0;
	for (int i = 0; i < Size; i++)
		if (arr[i] == Key_Value)
		{
			arr[i] = 0;
			key_counter++;
		}
	if (key_counter == 0) std::cout << "\n No Key Value found\n";
	else std::cout << "\n Make "<< key_counter << " replacements with 0\n";
}
 
template <typename any_type> any_type index_sum(any_type arr[], any_type arr2[], int Size, int Size2, int index_to_summ)
{
	if (index_to_summ >= Size || index_to_summ >= Size2 || index_to_summ < 0)
	{
		std::cout << "\nERROR\n";
		return 0;
	}
		 return arr[index_to_summ] + arr2[index_to_summ];
 }

template <typename any_type> double mean_arr(any_type arr[], int Size)
{
	any_type Array_min= arr[0], Array_max=arr[0];
	for (int i = 0; i < Size; i++)
	{
		if (arr[i] < Array_min) Array_min = arr[i];
		if (arr[i] > Array_max) Array_max = arr[i];		
	}
	return double(Array_min + Array_max)/2.0;
}

template <typename any_type> void prime_range(any_type Range_min, any_type Range_max)
{
		for (any_type i = Range_min; i <= Range_max; i++)
	{
		int Divider_Count = 0;
		for (any_type k = 1; k <= i; k++)
			if (i % k == 0) Divider_Count++;
		if (Divider_Count == 2)
			std::cout << i << ", ";
	}
	std::cout << "\b\b.\n";
}

template <typename any_type> void permute_arr(any_type arr[], int Size)
{
	if (Size % 2)
		for (int i = 0; i < Size / 2; i++)
			std::swap(arr[i], arr[Size / 2 + i+1]);
	else
		for (int i = 0; i < Size / 2; i++)
			std::swap(arr[i], arr[Size / 2 + i]);
}

int main()
{
	srand(time(NULL));
	int const Size = 20;
	int Range = 99;	
	int Random_Array[Size] = {};
	Fill_Array_Random(Random_Array, Size, -Range, Range);
		
	do
	{
		system("cls");
		std::cout << "***\tTest: Functions and Arrays\t***\n";

		std::cout << "\nPrimary Random Array[" << Size << "] is ready:";
		Array_COUT(Random_Array, Size);

		std::cout << "\n\n" << "1. clear_arr()";
		std::cout << "\n" << "2. index_sum()";
		std::cout << "\n" << "3. mean_arr()";
		std::cout << "\n" << "4. prime_range()";
		std::cout << "\n" << "5. permute_arr()";
		std::cout << "\n\n";
		std::cout << "\n" << "0. Exit";
		std::cout << "\n\n";
		int User_Choice = Get_Int();
		if (User_Choice == 0) break;
		else if (User_Choice == 1)
		{
			std::cout << "\n" << "Key Value = ";
			int Key_Value = Get_Int();
			clear_arr(Random_Array, Size, Key_Value);
			Array_COUT(Random_Array, Size);
		}
		else if (User_Choice == 2)
		{
			int const Size2 = 10;
			int Random_Array2[Size2] = {};
			Fill_Array_Random(Random_Array2, Size2, -Range, Range);
			std::cout << "\nSecondary Random Array[" << Size2 << "] is ready:";
			Array_COUT(Random_Array2, Size2);
			std::cout << "\n" << "Index of elements to summ = ";
			int Key_Value = Get_Int();
			std::cout << "\n" << "Summ of elements with index [" << Key_Value << "] = " << index_sum(Random_Array, Random_Array2, Size, Size2, Key_Value);
		}
		else if (User_Choice == 3)
		{
			std::cout << "\n" << "Average of maximum and minimum elements = " << mean_arr(Random_Array, Size );
		}
		else if (User_Choice == 4)
		{
			std::cout << "\n" << "Finding prime numbers from ";
			int Range_from = Get_Int();
			std::cout << "\n" << "Finding prime numbers to ";
			int Range_to = Get_Int();

			std::cout << "\n" << "Prime numbers in range [" << Range_from<< ".." << Range_to<<"]:\n";
			prime_range(Range_from,  Range_to);
		}
		else if (User_Choice == 5)
		{
			std::cout << "\n" << "Changing elements with places...";
			permute_arr(Random_Array, Size);
			Array_COUT(Random_Array, Size);
		}
		std::cout << "\n\n";
		system("pause");
	} while (true);	
	return 0;
}

int Get_Int()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
	}
	return a;
}
int Get_Dbl()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
	}
	return a;
}