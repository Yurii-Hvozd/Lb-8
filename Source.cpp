#include "Array.h"


int main()
{
	Array<int> intArr;
	cout << intArr;
	intArr.count_difference_of_averages();

	Array<double> doubleArr(5);
	cout << doubleArr;
	doubleArr.init_Array();
	cout << doubleArr;
	intArr.count_difference_of_averages();


	return 0;
}
