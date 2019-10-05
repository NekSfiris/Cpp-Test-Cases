/*
 * Test Cases for SDE Amazon Program
 */

#include <iostream>

#include <map>

#include <time.h>


using namespace std;


class ArraySubset{

	public:

    	//Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not.
		//Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.
		//Complexity with brute force implementation O(n*m)
		void arraySubset(int arr1[], int arr2[], int n1, int n2)
		{

			clock_t begin = clock();

			int sum=0;

			for(int i=0;i<n2;i++)
			{
				for(int j=0;j<n1;j++)
				{
					if(arr2[i]==arr1[j])
					{
						sum+=1;
						break;
					}
				}
			}

			if(sum==n2)
				cout << endl << "arr2 is a subset of arr1" << endl;
			else
				cout << endl << "arr2 is not a subset of arr1" << endl;

		    clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "Time elapsed for arraySubset-O(m*n) is "<< elapsed_secs*1000 << "ms" << endl;

			ArraySubset::arraySubsetBST(arr1, arr2, n1, n2);

		}


		//map internally store elements in a balanced BST.
		//Complexity with arraySubsetBST is O(n)
		void arraySubsetBST(int arr1[], int arr2[], int n1, int n2)
		{
			
		    map<int, int> mp1; 
		  
		  	//O(n1) --- Add at each key/value pair the times each key is present in array
		    for (int i = 0; i < n1; i++) 
		        mp1[arr1[i]]++; 

		  	clock_t begin = clock();

		    for (int i = 0; i < n2; i++)
		    { 
		        // if arr2[i] is not present in map 
		        // then array arr2[] can not be a 
		        // subset of array arr1[] 
		        if (mp1.find(arr2[i]) == mp1.end())
		        { 
		            cout << endl << "arr2 is not a subset of arr1" << endl;
		            break; 
		        }
		        // if if arr2[i] is present in map 
		        // decrement by one 
		        else
		        { 
		            mp1[arr2[i]]--; 
		  
		            if (mp1[arr2[i]] == 0) 
		                mp1.erase(mp1.find(arr2[i]));

		            if(i==n2-1)
		            	cout << endl << "arr2 is a subset of arr1" << endl;
		        } 
		    } 
		  
			clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime elapsed for arraySubsetBST-O(n) is "<< elapsed_secs*1000 << "ms" << endl;

			//ISN'T AS QUICK AS I IMAGINED.. DON'T KNOW WHY THOUGH
			// unordered_set<int> s;
			// //array elements range insertion in unordered set 
			// for(int i=0; i<n1; i++)
		//  			s.insert(arr1[i]); 
			
		//  		clock_t begin = clock();

		 //    for (int i = 0; i < n2; i++)
		 //    {
		 //        //find returns end iterator if key is not found, else it returns iterator to that key 
		 //        if (s.find(arr2[i]) != s.end()) 
		 //        {
		 //        	//means that we are at the last element which is in arr1 and all elements before that are also in arr1
		 //        	if(i==n2-1)
		 //        	{
			//             cout << endl << "arr2 is a subset of arr1" << endl;
			// 			clock_t end = clock();
			// 			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			// 			cout << "\nTime elapsed for arraySubsetBST-O(n) is "<< elapsed_secs*1000 << "ms" << endl;
			// 		}
			// 	} 
			// 	else
			// 	{
			// 		cout << endl << "arr2 is not a subset of arr1" << endl;
			// 		break; 
			// 	}
			// }

		}
 
 };
