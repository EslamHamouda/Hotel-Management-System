#include <iostream>
#include <stdlib.h>

using namespace std;

struct Hotel
{
	string name, location;
	int availableRooms=0, rating=0, PriceperRoom=0;

};
Hotel* v;
void addHotel(int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "----------------------------------------------------------" << endl;
		cout << i+1 <<" Name-==>";
		cin >> v[i].name; 
		cout << i+1 <<" Number of available rooms-==>";
		cin >> v[i].availableRooms; 
		cout << i+1 <<" Location-==>";
		cin >> v[i].location; 
		cout << i+1 <<" Rating-==>";
		cin >> v[i].rating; 
		cout << i+1 <<" Price per Room-==>";
		cin >> v[i].PriceperRoom; 
		cout << "----------------------------------------------------------" << endl;
	}
}

void bubbleSort(int size) 
{
	bool flag = false;
	for (int i = 0; i < size-1; i++) //n
	{
		for (int j = 0; j < size-i-1; j++) //(n-1)*(n)
		{
			if (v[j].name>v[j+1].name) //(n-1)*(n-1)
			{
				
				swap(v[j], v[j + 1]); //(n-1)*(n-1)
				flag = true; 
			}
		}
		if (flag==false) 
		{
			break; 
		}
	}
}

void selectionSort(int size)
{
	int min;
	for (int i = 0; i < size-1; i++) //n
	{
		 min=i; //n-1
		for (int j = i+1; j < size; j++) //(n-1)*n
		{
			if (v[j].rating<v[min].rating) //(n-1)*(n-1)
			{
				min = j; //(n-1)*(n-1)
				
			}	 
		}
		swap(v[min], v[i]); //n-1
	}
}

void inseartionSort(int size)
{
	Hotel key; int j;
	for (int i = 1; i < size; i++)  //n
	{
		key = v[i];  //n-1
		j = i - 1; //n-1
		while (j>=0&&v[j].availableRooms>key.availableRooms) //(n-1)*n
		{
			v[j + 1] = v[j]; //(n-1)*(n-1)
			j = j - 1;  //(n-1)*(n-1)
		}
		v[j + 1] = key; //n-1
	}
}

void merge(int l, int m, int r)
{
	int s1 = m - l + 1; //1
	int s2 = r - m; //1
	Hotel* arr1 = new Hotel[s1];  Hotel* arr2 = new Hotel[s2];
	for (int i = 0; i < s1; i++) //n
		arr1[i] = v[l + i];  //n-1
	for (int j = 0; j < s1; j++) //n
		arr2[j] = v[m + 1 + j]; //n-1
	int i = 0, j = 0, k = l; //1
	while (i<s1&&j<s2) //n
	{
		if (arr1[i].PriceperRoom<=arr2[j].PriceperRoom) //n-1
		{
			v[k] = arr1[i]; //n-1
			i++; //n-1
		}
		else
		{
			v[k] = arr2[j]; //n-1
			j++; //n-1
		}
		k++; //n-1
	}
	while (i < s1) { //n
		v[k] = arr1[i]; //n-1
		i++; //n-1
		k++; //n-1
	}
	while (j < s2) { //n
		v[k] = arr2[j]; //n-1
		j++; //n-1
		k++; //n-1
	}
}
void mergeSort(int l, int r) 
{
	if (l<r) 
	{
		int m = l + (r - l) / 2;
		mergeSort(l, m); //log n
		mergeSort(m + 1, r); //log n
		merge(l, m, r); //n
	}
}

int binarysearch(int l, int r, string target)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (v[m].name == target)
		{
			return 1;
		}
		else if (v[m].name > target)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}

	}
	return -1;
}

int binarysearch2(int l, int r, string target)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (v[m].location == target)
		{
			return 1;
		}
		else if (v[m].location > target)
		{
			r = m - 1;
		}
		else
		{
			l = m + 1;
		}

	}
	return -1;
}
void DisplayAll(int n)
{
	cout << "\t\t\tAll hotels" << endl;
	cout <<"----------------------------------------------------------" << endl;
	for(int i=0; i<n; i++)
	{
		cout << i + 1 << " Name: "; cout << v[i].name<<endl;

		cout << i + 1 << " Number of available rooms: "; cout << v[i].availableRooms << endl;
		cout << i + 1 << " Location: "; cout << v[i].location<<endl;
		cout << i + 1 << " Rating: "; cout << v[i].rating << endl;
		cout << i + 1 << " Price per Room: "; cout << v[i].PriceperRoom << endl;
		cout << "----------------------------------------------------------" << endl;
	}
}
int main()
{
	cout << "\t\t*************************************************************************************\n";
	cout << "\t\t\t\t\t\tHotel Management System\n";
	cout << "\t\t*************************************************************************************\n";
	cout << "\t\t   Welcome to Hotel Management System please add hotel first to use next functions\n\n";
	int choice, size;
	char c;
	do
	{
		cout << "-==>Enter (1) to add hotel:\n";
		cout << "-==>Enter (2) to sort hotels by name using (bubble sort):\n";
		cout << "-==>Enter (3) to sort hotels by rating using (selection sort):\n";
		cout << "-==>Enter (4) to sort hotels by maximum number of available rooms using (insertion sort):\n";
		cout << "-==>Enter (5) to sort hotels by price per room using (merge sort):\n";
		cout << "-==>Enter (6) to disblay all hotels:\n";
		cout << "-==>Enter (7) to clear screen:\n";
		cout << "-==>Enter (0) to exit:\n";
		cout << "-==>Your choice:\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "-==>Please enter number of hotels:\n";
			cin >> size;
			v = new Hotel[size];
			cout << "-==>Please enter name, Number of available rooms, Location, Rating, Price per Room for each hotel\n";
			addHotel(size);
			cout << "-==>(Great well done)"<<char(3)<<"\n";
			cout << "----------------------------------------------------------" << endl;
			break;
		case 2:
			bubbleSort(size);
			cout << "-==>(Great well done)" << char(3) << "\n";
			cout << "-==>Are you want to search about hotel?(Y/N)\n";
			cin >> c;
			if (c=='Y'||c=='y')
			{
				cout << "-==>Please enter hotel name:\n";
				string s;
				cin >> s;
				int result = binarysearch(0, size - 1,s);
				if (result==1)
				{
					cout << "-==>Avaliable"<<char(2)<<"\n";
				}
				else
				{
					cout << "-==>Not avaliable" << char(2) << "\n";
				}
			}
			else if (c=='N'||c=='n')
			{
				continue;
			}
			break;
		case 3:
			selectionSort(size);
			cout << "-==>(Great well done)" << char(3) << "\n";
			cout << "-==>Are you want to search about location?(Y/N)\n";
			cin >> c;
			if (c == 'Y' || c == 'y')
			{
				cout << "-==>Please enter location:\n";
				string s;
				cin >> s;
				int result = binarysearch2(0, size - 1, s);
				if (result == 1)
				{
					cout << "-==>Avaliable" << char(2) << "\n";
				}
				else
				{
					cout << "-==>Not avaliable" << char(2) << "\n";
				}
			}
			else if (c == 'N' || c == 'n')
			{
				continue;
			}
			break;
		case 4:
			inseartionSort(size);
			cout << "-==>(Great well done)" << char(3) << "\n";
			cout << "-==>Are you want to search about location?(Y/N)\n";
			cin >> c;
			if (c == 'Y' || c == 'y')
			{
				cout << "-==>Please enter location:\n";
				string s;
				cin >> s;
				int result = binarysearch2(0, size - 1, s);
				if (result == 1)
				{
					cout << "-==>Avaliable" << char(2) << "\n";
				}
				else
				{
					cout << "-==>Not avaliable" << char(2) << "\n";
				}
			}
			else if (c == 'N' || c == 'n')
			{
				continue;
			}
			break;
		case 5:
			mergeSort(0, size - 1);
			cout << "-==>(Great well done)" << char(3) << "\n";
			cout << "-==>Are you want to search about hotel?(Y/N)\n";
			cin >> c;
			if (c == 'Y' || c == 'y')
			{
				cout << "-==>Please enter hotel name:\n";
				string s;
				cin >> s;
				int result = binarysearch(0, size - 1, s);
				if (result == 1)
				{
					cout << "-==>Avaliable" << char(2) << "\n";
				}
				else
				{
					cout << "-==>Not avaliable" << char(2) << "\n";
				}
			}
			else if (c == 'N' || c == 'n')
			{
				continue;
			}
			break;
		case 6:
			DisplayAll(size);
			break;
		case 7:
			system("CLS");
			break;
		}
	} while (choice!=0);
	
}
