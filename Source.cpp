#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>

std::vector<int> readFile(); //Read file contents, push to vector.
std::vector<std::vector<int>> sortTriangle(std::vector<int> triangle); //Sorts entered number triangle into order, layer by layer.
int findLowestPath(std::vector<std::vector<int>> layers); //Finds lowest num per layer (at first index of each layers list).
int findHighestPath(std::vector<std::vector<int>> layers); //Finds highest num per layer (at last index of each layers list).
int checkIntInput(int check); //check input for 1 or 0, specific to this programs logic, unless you just want to check for an input of 0 or 1 of course :)

int main()
{
	while (true)
	{
		int num{};
		bool flag{};

		std::cout << "\nPlease enter 0 for lowest path, or 1 for highest path\n";
		std::cin >> num;

		num = checkIntInput(num);

		switch (num)
		{
		case 0:
			std::cout << "\n Total sum of path = " << findLowestPath(sortTriangle(readFile())) << "\n";
			break;
		case 1:
			std::cout << "\n Total sum of path = " << findHighestPath(sortTriangle(readFile())) << "\n";
			break;
		}

		int check{};

		std::cout << "\nFind seperate path ? 0 for NO, 1 for YES\n";
		std::cin >> check;

		check = checkIntInput(check);
		if (check == 0)
		{
			break;
		}
	}

}


std::vector<int> readFile() //Read file contents, push to vector, return vector.
{
	std::vector<int> fileContents{};
	std::ifstream myFile;
	std::string path;

	bool flag = false;

	int temp{};
	while (flag == false)
	{
		std::cout << "\nplease enter your file path\n";
		std::cin >> path;
		path.erase(remove(path.begin(), path.end(), '"'), path.end());
		myFile.open(path);

		if (!myFile)
		{
			std::cout << "\n Error Opening File. \n";
		}
		else
		{
			flag = true;
		}
	}
		while (myFile >> temp)
		{
			fileContents.push_back(temp);
		}

	return fileContents;
}
std::vector<std::vector<int>> sortTriangle(std::vector<int> triangle) //Sorts entered number triangle into order, layer by layer.
{

	std::vector<std::vector<int>> layers;
	for (int i = 0; i < triangle.size(); i++)
	{
		std::vector<int> newVector{};
		for (int l = 0; l < i; l++)
		{
			newVector.push_back(triangle[0]);
			triangle.erase(triangle.begin());
		}
		std::sort(newVector.begin(), newVector.end());
		layers.push_back(newVector);	
	}

	return layers;
}

int findLowestPath(std::vector<std::vector<int>> layers) //Finds lowest num per layer (at first index of each layers list).
{
	int sum = 0;
	for (int i = 0; i < layers.size(); i++)
	{
		for (int l = 0; l < layers[i].size(); l = layers[i].size()) //DO NOT TOUCH THIS LOOP, to do with addressing 2d vectors.
		{
			std::cout << "\nlayer " << i << " " << layers[i][0] << "\n";
			sum += layers[i][0];
		}
	};
	
	return sum;
}
int findHighestPath(std::vector<std::vector<int>> layers) //Finds highest num per layer (at last index of each layers list).
{
	int sum = 0;
	for (int i = 0; i < layers.size(); i++)
	{
		for (int l = 0; l < layers[i].size(); l = layers[i].size()) //DO NOT TOUCH THIS LOOP, to do with addressing 2d vectors.
		{
			std::cout << "\nlayer " << i << " " << layers[i][i - 1] << "\n";
			sum += layers[i][i-1];
		}
	};
	
	return sum;
}


int checkIntInput(int check) //check input for 1 or 0, specific to this programs logic, unless you just want to check for an input of 0 or 1 of course :)
{
	while (std::cin.fail() || (check > 1 || check < 0))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\n Bad entry, please enter 0 or 1 \n";
		std::cin >> check;
	}

	return check;
}