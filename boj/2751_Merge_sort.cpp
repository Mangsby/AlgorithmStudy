#include <iostream>
#include <vector>

std::vector<int> Merge(
		const std::vector<int>& subArray1,
		const std::vector<int>& subArray2)
{
	std::vector<int> array;
	auto it1 = subArray1.begin(); 
	auto it2 = subArray2.begin();
	for(int n=0; n < subArray1.size() + subArray2.size(); n++)
	{
		if(it1 != subArray1.end() && (it2 == subArray2.end() || *it1 < *it2))
		{
			array.push_back(*it1);
			it1++;
		}
		else
		{
			array.push_back(*it2);
			it2++;
		}
	}

	return array;
}

void MergeSort(std::vector<int>& array)
{
	if(array.size() == 1) return;

	auto mid = array.size() / 2;
	
	std::vector<int> subArray1(array.begin(), array.begin() + mid);
	std::vector<int> subArray2(array.begin() + mid, array.end());
	MergeSort(subArray1);
	MergeSort(subArray2);
	array = std::move(Merge(subArray1, subArray2));
}

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> array(n);
	for(int i=0; i<n; i++)
	{
		std::cin >> array[i];
	}

	MergeSort(array);
	for(const auto& it : array)
	{
		std::cout << it << '\n';
	}

	return 0;
}
