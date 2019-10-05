/*
 * Test Cases for SDE Amazon Program
 */

#include <iostream>
#include <vector>
#include <cstring>

#include <unordered_map>
#include <map>
#include <unordered_set>

#include <stack> 
#include <queue> 

#include <time.h>
#include <algorithm>
#include <cmath>

#include "ArraySubset.h"

using namespace std;



//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}//constructor
};
 
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {

	public:

		//Bubble Sort (small -> big)
		//Complexity O(n^2)
		void BubbleSort()
		{

			clock_t begin = clock();

			int n;
		    cout<<"Enter num of element of the matrix :";
		    cin>>n;
		    int arr[n];
		    cout<<"Enter array values:\n";

		    //get matrix values
		    for(int i=0;i<n;i++)
				cin>>arr[i];

			//if we wanted big -> small then for the second loop j=1;j<size-i
			for(int i=0;i<n-1;i++)
		    {
		        for(int j=0;j<n-i-1;j++)
		        {
		            if(arr[j]>arr[j+1])
		            {
		                int temp=arr[j];
		                arr[j]=arr[j+1];
		                arr[j+1]=temp;
		            }
		        }
		    }

		    cout<<"After Bubble sort the array is :\n";
		    for(int i=0;i<n;i++)
		    	cout<<arr[i]<<" ";

		    clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "Time elapsed is "<< elapsed_secs*1000 << "ms" << endl;

		}


		//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
		//You may assume that each input would have exactly one solution, and you may not use the same element twice.
		//Complexity with brute force implementation O(n^2)
		vector<int> twoSum(vector<int>& nums, int target)
		{

			clock_t begin = clock();

			vector<int> res;

			if(nums.size()==0)
			{
				cout << "Empty vector" << endl;
				return res;
			}

			for(int i=0;i<nums.size();i++)
			{
				for(int j=i+1;j<nums.size();j++)
				{
					if(nums.at(i)+nums.at(j)==target)
					{
						res.push_back(i);
						res.push_back(j);

						cout << "Answer for twoSum is : ";
		        		for (auto it = res.begin(); it != res.end(); ++it) 
	        				cout << *it << " ";

						clock_t end = clock();
						double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
						cout << "\nTime elapsed for twoSum-O(n^2) is "<< elapsed_secs*1000 << "ms" << endl;

						Solution sol;
						vector<int> reshash = sol.twoSumHash(nums, target);// call function to solve with Hash Table

						return res;
					}
				}

			}

			cout << "Failed to find a solution for this vector values.\n";
			return res;

		}

		//Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices 
		//of hash table that is why performance of data structure depends on hash function a lot but on an average the
		//cost of search, insert and delete from hash table is O(1).
		//
		//std::map uses a binary tree implementation to keep the keys sorted,
		//so retrieval and insertion is O(logn) NOT O(1) unlike std::unordered_map which uses hashing.
		//Complexity with Hash Table implementation O(n)
		vector<int> twoSumHash(vector<int>& nums, int target)
		{

			clock_t begin = clock();

			//key will be of int type and mapped value will be of int type
			std::unordered_map<int, int> lookup;
			for (int i = 0; i < nums.size(); i++)
			{
				auto it = lookup.find(target - nums[i]);
				if (it != lookup.end())
				{
					cout << "\nAnswer for twoSumHash is : " << it->second << " " << i;

					clock_t end = clock();
					double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
					cout << "\nTime elapsed for twoSumHash-O(n) is "<< elapsed_secs*1000 << "ms" << endl;

					//it->first stores the key part and it->second stores the value part
					return std::vector<int> ({it->second, i});
				} 
				else 
				{
					lookup[nums[i]] = i;
				}
			}

			cout << "Failed to find a solution for this vector values.\n";
			return std::vector<int>();

		 //    AN IMPLEMENTATION WITH unordered_set. NO WAY TO RETURN THE POSITION IN TABLE BUT ONLY THE VALUE !!!
		 //    unordered_set<int> s;

		 //    for (int i = 0; i < nums.size(); i++)
		 //    {
		 //        int temp = target - nums.at(i); 

		 //        //find returns end iterator if key is not found, else it returns iterator to that key 
		 //        if (s.find(temp) != s.end()) 
		 //        {
		 //            cout << "Pair is (" << nums.at(i) << ", " << temp << ")" << endl;
		 //            break;
		 //        }
		 //        s.insert(nums.at(i)); 
		 //    } 
		 //    vector<int> res;
		 //    return res;

		}


		//Two linked lists with non-negative integer values. Each node contains a single digit and digits are stored in reverse order.
		//Add the two numbers and return it as a linked list.
		//Complexity O(max(m,n)), with m and n representing the length of l1 and l2 respectively
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
	        ListNode *top, *cur, *prev;
	        cur=new ListNode(0);
	        prev = new ListNode(0);
	        top = new ListNode(0);
	        top=cur;
	        int rem=0;
	        while(1)
	        {
	            if (l1==NULL && l2 == NULL) {
	                if(cur->val==0)
	                	prev->next=NULL;
	                break;
	            }
	            if (l1!=NULL && l2!=NULL)
	            {
	                cur->val += (l1->val + l2->val);
	                cur->next=new ListNode((cur->val)/10);
	                cur->val%=10;

	                prev=cur;
	                cur=cur->next;
	                l1=l1->next;
	                l2=l2->next;
	            }
	            else if(l1==NULL)
	            {
	                cur->val+=l2->val;
	                cur->next=new ListNode(cur->val/10);
	                cur->val%=10;

	                prev=cur;
	                cur=cur->next;
	                l2=l2->next;
	            }
	            else 
	            {
	                cur->val+=l1->val;
	                cur->next =new ListNode((cur->val)/10);
	                cur->val%=10;
	              
	                prev=cur;
	                cur=cur->next;
	                l1=l1->next;
	            }
	        }
	        return top;
    	}



    	//Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
    	//We divided the input by 10 for every iteration, so the time complexity is O(n)
    	bool isPalindrome(int x)
    	{
        
    		clock_t begin = clock();

	        if(x<0)
	    		return 0;
	        else if(x<10)
	            return 1;

    		int i=x,n=0;
    		while(i>0)
    		{
                if (n > 2147483647/10 || n < (-2147483647)/10) return 0; // int overflow check
    			n=(int(i)%10) + n*10;
    			i/=10;
    		}

    		if(n==x)
    			return 1;
    		else
    			return 0;

	    	clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime elapsed for isPalindrome-O(n)-> (with n num of values in integer) is "<< elapsed_secs*1000 << "ms" << endl;

    	}

    	//Given a number n, find the smallest number that has same set of digits as n, and is greater than n.
    	//If instead of doing simple sort, we apply some clever technique to do it in linear time, the Complexity would be O(n)
    	void nextGreaterNumber(char digits[], int n)
    	{

    		clock_t begin = clock();
    		char x_swap;
    		int pos;//first digit that is smaller than the digit next to it - position

    		for(int i=n-2; i>0; i--)
    		{
    			if(digits[i]>=digits[i+1])
    			{
    				x_swap=digits[i];
    				digits[i]=digits[i+1];
    				digits[i+1]=x_swap;
    			}
    			else//last digit that needs to be swaped
    			{
    				x_swap=digits[i];
    				digits[i]=digits[i+1];
    				digits[i+1]=x_swap;
    				pos = i+1;//store the next position of that digit (as it is swapped now and we want to keep the last swap value)
    				break;
    			}
    		}

    		sort(digits + pos, digits + n);//O(nlogn) - quicksort

    		cout << "Final char string : " << digits << endl;


    		clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime elapsed for nextGreaterNumber-O(n) is "<< elapsed_secs*1000 << "ms" << endl;

    	}



    	//merge sort always divides the array into two halves and take linear time to merge two halves.
    	//T(n) = 2T(n/2) + Θ(n) -> falls in case II of Master Method
    	//Time complexity of Merge Sort is O(nLogn) in all 3 cases (worst, average and best)
		void merge(int arr[], int l, int m, int r) 
		{ 

			cout<< "\nWE MERGE!!! --------> ";

		    int i, j, k; 
		    int n1 = m - l + 1; 
		    int n2 =  r - m; 
		  
		    /* create temp arrays */
		    int L[n1], R[n2]; 
		  
		    /* Copy data to temp arrays L[] and R[] */
		    for (i = 0; i < n1; i++) 
		        L[i] = arr[l + i]; 
		    for (j = 0; j < n2; j++) 
		        R[j] = arr[m + 1+ j]; 
		  
		    /* Merge the temp arrays back into arr[l..r]*/
		    i = 0; // Initial index of first subarray 
		    j = 0; // Initial index of second subarray 
		    k = l; // Initial index of merged subarray 
		    while (i < n1 && j < n2) 
		    { 
		        if (L[i] <= R[j]) 
		        { 
		            arr[k] = L[i]; 
		            i++; 
		        } 
		        else
		        { 
		            arr[k] = R[j]; 
		            j++; 
		        } 
		        k++; 
		    } 
		  
		    /* Copy the remaining elements of L[], if there 
		       are any */
		    while (i < n1) 
		    { 
		        arr[k] = L[i]; 
		        i++; 
		        k++; 
		    } 
		  
		    /* Copy the remaining elements of R[], if there 
		       are any */
		    while (j < n2) 
		    { 
		        arr[k] = R[j]; 
		        j++; 
		        k++; 
		    } 

		    Solution sol;
			printf("Current MERGED array is : ");
			for (i=0; i < r+1; i++) 
		    	printf("%d ", arr[i]); 
			printf("\n"); 

		} 
		  
		//l is for left index and r is right index of the sub-array of arr to be sorted
		void mergeSort(int arr[], int l, int r) 
		{ 

		    if (l < r) 
		    { 

		    	Solution sol;
				printf("\nCurrent array is : ");
		    	for (int i=l; i < r+1; i++) 
		        	printf("%d ", arr[i]); 
		    	printf("\n"); 

		        // Same as (l+r)/2, but avoids overflow for large l and h 
		        int m = l+(r-l)/2; 
		        
		        // Sort first and second halves 
		        sol.mergeSort(arr, l, m); 
		        sol.mergeSort(arr, m+1, r); 
		  
		        sol.merge(arr, l, m, r); 
		    } 
		} 



		//Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
		//Complexity is O(m), with m being the number of values of the longest array
		void mergeArrays(vector<int>& nums1, int m, vector<int>& nums2, int n) 
	    {

	    	clock_t begin = clock();
    		
	        int i=m-1,j=n-1,z=n+m-1;
	        while(i>=0 && j>=0)
	            nums1[z--]=nums1[i]>nums2[j] ? nums1[i--] : nums2[j--];
	        while(j>=0)
	            nums1[z--]=nums2[j--];


	        cout << "Answer for mergeArrays is : ";
		    for (auto it = nums1.begin(); it != nums1.end(); ++it) 
	        	cout << *it << " ";
	        cout << endl;

	        clock_t end = clock();
			double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
			cout << "\nTime elapsed for mergeArrays-O(m) is "<< elapsed_secs*1000 << "ms" << endl;

	    }



	    //Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
	    //We look at each element of the array 1 time, so the time complexity is O(n)
   		vector<int> spiralOrder(vector<vector<int>>& matrix)
   		{
	        vector<int> res;
	        int left=0, top=0, right=matrix[0].size()-1, bottom=matrix.size()-1;

	        if(matrix.empty())
	        	return res;

	        while(top<=bottom && left<=right)
	        {

	        	for(int j=left; j<=right; j++)
	        		res.push_back(matrix[top][j]);
	        	top++;

	        	for(int i=top; i<=bottom; i++)
	        		res.push_back(matrix[i][right]);
	        	right--;

	        	if(top<=bottom)
	        	{
		        	for(int j=right; j>=left; j--)
		        		res.push_back(matrix[bottom][j]);
		        	bottom--;
	        	}

	        	if(left<=right)
	        	{
		        	for(int i=bottom; i>=top; i--)
		        		res.push_back(matrix[i][left]);
		        	left++;
	        	}

	        }

	        return res;   
	        
    	}


    	//Given an expression string examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in it.
		//For example, the program should print 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”
		//Time Complexity: O(n) and Auxiliary Space: O(n) for stack.
    	bool braceExpansion(char expression[], int n)
    	{
    		stack<char> s;
    		char b1='{', b2='[', b3='(';

    		n--;
    		while(n>=0)
    		{
    			if(expression[n]!=b1 && expression[n]!=b2 && expression[n]!=b3)
    				s.push(expression[n]);
    			else
    			{
    				if(s.top()=='}' && expression[n]=='{')
    					s.pop();
    				else if(s.top()==']' && expression[n]=='[')
    					s.pop();
    				else if(s.top()==')' && expression[n]=='(')
    					s.pop();
    				else
    				{
    					cout << endl << "The unbalance is found at position : " << n << endl << "and current stack is : " ;
    					while( !s.empty() )
						{
						     cout << s.top() << " ";
						     s.pop(); 
						}
    					return false;
    				}
    			}

				n--;
    		}


    		return true;
    	}
        

    	//Give a N*N square matrix, return an array of its anti-diagonals.
    	//If the matrix is [[1 2 3], [4 5 6], [7 8 9]] , the output should Return the following : [ [1], [2, 4], [3, 5, 7], [6, 8], [9] ]
    	//Time Complexity: O(n*m)
        void antiDiagonals(int data[][4], int n)
        {
        	int r_i=0;
        	int i=0, j=0;// i is rows and j is columns
        	cout << "The anti-diagonals of the matrix are : " << endl;
        	while(true)
        	{
        		if(j<n && i==0)
				{
					while(i<=r_i)//we take into consideration how i increases as we move down each diagonal
	        		{
	        			cout << data[i][j] << " ";
	        			j--;
	        			i++;
	        		}
	
	        		r_i++;
	        		j=r_i; i=0;
	        		cout << endl;
	        	}
	        	else
	        	{

	        		if(j==n)//first time we get in this if
	        		{
	        			i++; j--;//i=1 and j=3, considering n=4
	        			r_i=1;//r_j will stay locked in (n-1)
	        		}

	        		while(j>=r_i)//we take into consideration how j decreases as we move down each diagonal
	        		{
	        			cout << data[i][j] << " ";
	        			j--;
	        			i++;
	        		}
	
	        		r_i++;
	        		j=n-1; i=r_i;
	        		cout << endl;

	        		if(i==n)//we did our job here and we leave
	        			break;
	        	}

        	}
        	
        }


       	//Given two binary trees, write a function to check if they are the same or not.
		//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
		//Solved with BFS traversal and a queue. Time complexity: O(n)
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
        
	        if(p==NULL && q==NULL)
	            return true;
	        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
	            return false;
	            
	        
	        queue<TreeNode*> q1, q2;
	        q1.push(p);
	        q2.push(q);

	        if(p->val != q->val) return false;//just the root
	        
	        while(!q1.empty() && !q2.empty())
	        {
	            TreeNode* node1 = q1.front();
	            TreeNode* node2 = q2.front(); 
	            q1.pop();
	            q2.pop();
	    
	            
	            if (node1->left != NULL && node2->left != NULL)
	            {    
	                if(node1->left->val == node2->left->val)
	                {
	                    q1.push(node1->left);
	                    q2.push(node2->left);
	                }
	                else
	                    return false;
	            }
	            else if((node1->left == NULL && node2->left != NULL) ||  (node1->left != NULL && node2->left == NULL))
	                return false;
	            

	            if (node1->right != NULL && node2->right != NULL)
	            {    
	                if(node1->right->val == node2->right->val)
	                {
	                    q1.push(node1->right);
	                    q2.push(node2->right);
	                }
	                else
	                    return false;
	            }
	            else if((node1->right == NULL && node2->right != NULL) ||  (node1->right != NULL && node2->right == NULL))
	                return false;

	        }
	        
	        return true;
    }



    //Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center). For example, this binary tree [1,2,2,3,4,4,3] is symmetric.
    //Solved by using Inorder Depth First Traversal and a stack. Time Complexity: O(n)
    bool isSymmetricTree(TreeNode* root)
    {

        if(root==NULL || (root->left==NULL && root->right==NULL))
            return true;
        
        stack<TreeNode*> sl, sr;
        
        TreeNode* nodel = root;
	    TreeNode* noder = root;
        
        while(!sl.empty() || nodel!=NULL)
        {
            
            //move nodel to the full bottom left node and noder to the full bottom right
            while(nodel!=NULL || noder!=NULL)
            {
                
                if((nodel==NULL && noder!=NULL) || (noder==NULL && nodel!=NULL))
                    return false;
                
                sl.push(nodel); sr.push(noder); 
                nodel=nodel->left; noder=noder->right;
            }
            
            //nodel and noder logically show NULL
            nodel=sl.top(); noder=sr.top();
            
            //we delete that node
            sl.pop(); sr.pop();
            
            if(nodel->val!=noder->val)
                return false;
            
            nodel=nodel->right;//next one will be the right
            noder=noder->left;//next one will be the left
                
        }
        
        return true;
    }



    //Invert a binary tree.
    TreeNode* invertTree(TreeNode* root)
    {
        if(root==NULL)
            return root;
        
        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                swap(p->left, p->right);
            }
        }
        return root;
    }

    //print tree by doind an inorder DFS traversal
    void inorderPrintTree(TreeNode *root)
    {
	   if (root != NULL)
	   {   
	      inorderPrintTree(root->left);
	      cout<<root->val<<" ";
	      inorderPrintTree(root->right);
	   }
	} 


	//Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0
	//Find all unique triplets in the array which gives the sum of zero.
	//Complexity 
	vector<vector<int>> threeSum(vector<int>& nums)
    {

        sort(nums.begin(), nums.end());//O(nlogn)

        vector<vector<int>> res;

        for (unsigned int i=0; i<nums.size(); i++) {
            if ((i>0) && (nums[i]==nums[i-1]))
                continue;
            unsigned int l = i+1, r = nums.size()-1;
            while (l<r) {
                int s = nums[i]+nums[l]+nums[r];
                if (s>0) r--;
                else if (s<0) l++;
                else {
                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    //for the next two whiles, the expression after the && is for the error created by input [0,0,0]
                    while (nums[l]==nums[l+1] && l<(nums.size()-2)) l++;
                    while (nums[r]==nums[r-1]  && r>1) r--;
                    l++; r--;
                }
            }
        }

        cout<< "Outcome vector : \n";
		for (int i = 0; i < res.size(); i++)
		{ 
	        for (int j = 0; j < res[i].size(); j++) 
	            cout << res[i][j] << " ";
	    
	        cout << endl; 
	    }

        return res;
    }


    //Given a linked list, remove the n-th node from the end of list and return its head.
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        
        stack<ListNode*> s;
        ListNode* temp = head;
        ListNode* temp2 = NULL;
        
        if(n<1)
            return temp2;

        while(temp->next!=NULL)
        {
            s.push(temp);
            temp=temp->next;
        }

        s.push(temp);//push the last element of the while
        
        int i=n;
        //has 1 indexing
        while(i>=1)
        {
            if(i==2)
                temp2=s.top();//the node before the one we look to toss away
            else if(i==1)//the node we look to toss away
            {
                temp=s.top();
                temp->next=NULL;
            }
            
            
            s.pop();
            if(!s.empty())
                temp=s.top();//the node after the one we look to toss away
            i--;
        }
        
        if(temp->next==NULL)
            return temp2;
        else
        {
            temp->next=temp2;
            return head;
        }



  //       //a more elegant solution is as follows
  //       if(!head->next) return NULL; // Since n is always valid so if size of listis 1 n will be 1 so we can return NULL. 
        
  //       ListNode* n1 = head; // First pointer
  //       ListNode* n2 = head; // Second Pointer
        
  //       int c = 0;
		// // Take second pointer n2  to that node such that n2-n1 = n.
  //       while(c != n)
  //       {
  //           n2 = n2->next;
  //           c++;
  //       }
        
		// // If n2 reached the end of the list, it means we have to remove the head of the list.
  //       if(n2 == NULL)        
  //           return n1->next;
        
		// // Taking n2 to end of the list and n1 n places before the end.
  //       while(n2->next != NULL)
  //       {
  //           n1 = n1->next;
  //           n2 = n2->next;
  //       }
  //       // deleting nth node.
  //       n1->next = n1->next->next;
  //       return head;

    }


    //Print a tree in level order.
    //Time Complexity: O(n)
    void levelOrderTreePrint(TreeNode* root)
    {
    	cout<< "Print Tree in level order : ";

    	queue<TreeNode*> q;
    	q.push(root);

    	while(!q.empty())
    	{
    		TreeNode* temp = q.front();
    		q.pop();
    		cout << temp->val << " ";

    		if(temp->left!=NULL)
    			q.push(temp->left);

    		if(temp->right!=NULL)
    			q.push(temp->right);
    	}
    }


    //Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].
    //T(n) = T(n/2) + c   =>   Time Complexity: O(logn)
    void binarySearch(int arr[], int x, int size)
    {

    	clock_t begin = clock();
    	int f=0;

    	for(int i=0; i<size; i++)
    	{
    		if(x==arr[i])
    		{
    			f=1;
    			break;
    		}
    	}

    	if(f==0)
    		cout << "Didn't found it!" << endl;
    	else
    		cout << "Found it!" << endl;

	    clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "Time elapsed for a linear search O(n) is "<< elapsed_secs*1000 << "ms" << endl;

		//we start working with Binary Search
		begin = clock();

		int l = 0, r = size-1;
		f=0;

    	while(l<=r)
    	{
    		int z = l + (r-l)/2;//mid

    		if(x>arr[z])
    			l=z+1;

    		if(x<arr[z])
    			r=z-1;

    		if(x==arr[z])
    		{
    			f=1;
    			break;
    		}
    	}

    	if(f==0)
    		cout << "Didn't found it!" << endl;
    	else
    		cout << "Found it!" << endl;

		end = clock();
		elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		cout << "Time elapsed for Binary Search O(logn) is "<< elapsed_secs*1000 << "ms" << endl;

    }


    //Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a^2 + b^2 = c^2.
    //Time Complexity: O(n^2)
    bool pythagoreanTriplet(int arr[], int size)
    {

    	unordered_map<int,int> um;
    	um[arr[0]] = 0;

    	for(int i=0; i<size; i++)
    	{
    		for(int j=i+1; j<size; j++)
    		{
    			if(um.find(arr[i]^2 + arr[j]^2)!=um.end())
    			{
    				cout << "\nFound values that satisfy a^2 + b^2 = c^2!" << endl;
    				cout << "a^2 = " << pow(arr[i],2) << ", b^2 = " << pow(arr[j],2) << ", c^2 = " << pow(arr[i],2) + pow(arr[j],2) << endl;
    				return true;
    			}
    			else
    				um[arr[j]] = j;
    		}
    		
    	}

    	return false;
    }



    //Print k largest elements in an array. Elements in array can be in any order. For example, if given array is [1, 23, 12, 9, 30, 2, 50]
	//and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.




};


int main()
{

	cout << "###################################\n";
  	cout << "Let's get the learning going bro!!!\n";
  	cout << "###################################\n";

    Solution sol;// object of general Solution class

    while(true)
    {

    	cout << "1->BubbleSort, 2->twoSum, 3->arraySubset, 4->isPalindrome, 5->string delimiter, 6->nextGreaterNumber, 7->classic merge sort, 8->mergeArrays, "
    	"9->spiralOrder, 10->braceExpansion, 11->antiDiagonals, 12->isSameTree, 13->isSymmetricTree, 14->invertTree, 15->threeSum, 16->levelOrderTreePrint, "
    	"17->binarySearch, 18->pythagoreanTriplet, 19->, 20->, 21->\n";
    	cout << "#################################\n";
    	cout << "Make the choice from the list : ";
    	int choice;
    	cin>>choice;

    	switch(choice)
    	{
	        case 1: sol.BubbleSort(); 
	        		break;
	        case 2: {	vector<int> nums;
		        		int n=0;
					    cout<<"Enter vector values (-1 to quit, -2 for random vector):\n";

					    //get vector values until -1 or -2 is pressed
					    while (true)
	     				{
	        				cin >> n;
	        				if(n==-1)
	        					break;
	        				else if(n==-2)
	        				{
	        					nums.clear();
	        					srand((unsigned)time(NULL));
								int a = rand() % 300 + 100; //generate random vector of 100 to 300 values
								for (int i=0; i < a; i++)
								{
							        int b = rand() % 3000 + 1;//each value is inside the [1,3000] scope
							        nums.push_back(b);
	   							}
	   							break;
	        				}

	        				nums.push_back(n);
	     				}

	     				//print the vector
	     				cout<<"Current vector is : ";
	     				for (auto it = nums.begin(); it != nums.end(); ++it) 
	        				cout << *it << " ";

		        		int target;
						cout<<"\nEnter value of target : ";
						cin>>target;

		        		vector<int> ans = sol.twoSum(nums, target);
		        
		        		break;
	        		}
	        case 3: {	int arr1[500], arr2[3];
						int n1 = sizeof(arr1)/sizeof(arr1[0]);
						int n2 = sizeof(arr2)/sizeof(arr2[0]);

		        		srand((unsigned)time(NULL));
						for (int i=0; i < n1; i++)
						{
					        int b = rand() % 300 + 1;
					        arr1[i]=b;
						}

						for (int i=0; i < n2; i++)
						{
					        int b = rand() % 300 + 1;
					        arr2[i]=b;
						}

						cout<<"Current array1 is : ";
	     				for (int i=0; i<n1; i++) 
	        				cout << arr1[i] << " ";
	        			cout<<"\nCurrent array2 is : ";
	     				for (int i=0; i<n2; i++) 
	        				cout << arr2[i] << " ";

	        			ArraySubset as;
		        		as.arraySubset(arr1, arr2, n1, n2);
		        		break;
	        		}
	        case 4: {	srand((unsigned)time(NULL));
	        			int x = 1234554321;
	        			bool a = sol.isPalindrome(x);
	        			break;
					}
			case 5: {	std::string s = "scott>=tiger>=mushroom";
						std::cout << s << std::endl;
						std::string delimiter = ">=";

						size_t pos = 0;
						std::string token;
						while ((pos = s.find(delimiter)) != std::string::npos) {
						    token = s.substr(0, pos);
						    std::cout << token << std::endl;
						    s.erase(0, pos + delimiter.length());
						}
						std::cout << s << std::endl;
						break;
					}
			case 6: {	char digits[] = "534976";
						cout << "Beginning char string : " << digits << endl;
    					int n = strlen(digits);
						sol.nextGreaterNumber(digits, n);
						break;
					}
			case 7: {	int arr[] = {38,27,43,3,9,82,10}; 
					    int arr_size = sizeof(arr)/sizeof(arr[0]); 
					  
					    sol.mergeSort(arr, 0, arr_size - 1); 
					  
					    printf("\nSorted array is \n");
					    for (int i=0; i < arr_size; i++) 
				        	printf("%d ", arr[i]); 
				    	printf("\n"); 
					    break;
					}
			case 8: {	vector<int> arr1 = {1,2,3,0,0,0}, arr2 = {2,5,6};
						int m=3, n=3;

						cout << "First vector :";
		    			for (auto it = arr1.begin(); it != arr1.end(); ++it) 
	        				cout << *it << " ";
	        			cout << endl;

	        			cout << "Second vector :";
		    			for (auto it = arr2.begin(); it != arr2.end(); ++it) 
	        				cout << *it << " ";
	        			cout << endl;

						sol.mergeArrays(arr1,m,arr2,n);
						break;
					}
			case 9: {	vector<vector<int>> matrix = {{1, 2, 3, 4},{5, 6, 7, 8},{9,10,11,12}};
						//vector<vector<int>> matrix = {{3},{2}};

						cout<< "Initial 2D vector : \n";
						for (int i = 0; i < matrix.size(); i++)
						{ 
					        for (int j = 0; j < matrix[i].size(); j++) 
					            cout << matrix[i][j] << " ";
					    
					        cout << endl; 
					    }

						vector<int> res = sol.spiralOrder(matrix);
						cout << "Answer for spiralOrder is : ";
		        		for (auto it = res.begin(); it != res.end(); ++it) 
	        				cout << *it << " ";
						break;
					}
			case 10: {	char expression[] = "[()]{}{[()()]()}";
						//char expression[] = "[(])";
						cout << "Beginning char string : " << expression << endl;
    					int n = strlen(expression);
						bool ans = sol.braceExpansion(expression, n);
						if(ans)
							cout << endl << "Balanced!" << endl;
						else
							cout << endl << "Not balanced!" << endl;
						break;
					}
			case 11: {	int data[][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

			 			int rows =  sizeof data / sizeof data[0]; // 2 rows  
  						int cols = sizeof data[0] / sizeof(int); // 5 cols

						cout << "Initial matrix is : " << endl;
						for (int i = 0; i < rows; i++) 
					       for (int j = 0; j < cols; j++) 
					  			// Prints ' ' if j != cols-1 else prints '\n'           
					          	cout << data[i][j] << " \n"[j == cols-1]; 

						sol.antiDiagonals(data, rows);
						break;
					}
			case 12: {	TreeNode *root = new TreeNode(1); 
					    root->left = new TreeNode(2); 
					    root->right = new TreeNode(3); 
					    root->left->left = new TreeNode(4); 
					    root->left->right = new TreeNode(5);

					    cout << endl << "First Tree in Inorder is :" << endl;
						sol.inorderPrintTree(root);

					    TreeNode *root2 = new TreeNode(1); 
					    root2->left = new TreeNode(2); 
					    root2->right = new TreeNode(3); 
					    root2->left->left = new TreeNode(4);
					    root2->left->left = new TreeNode(14);

					    cout << endl << "Second Tree in Inorder is :" << endl;
						sol.inorderPrintTree(root2);

					    bool ans = sol.isSameTree(root, root2);
					    if(ans)
							cout << endl << "Same!" << endl;
						else
							cout << endl << "Not same!" << endl;
						break;
					}
			case 13: {	TreeNode *root = new TreeNode(1); 
					    root->left = new TreeNode(2);  
					    root->left->left = new TreeNode(3); 
					    root->left->right = new TreeNode(4);
					    root->right = new TreeNode(2); 
					    root->right->left = new TreeNode(4); 
					    root->right->right = new TreeNode(3);

					    cout << endl << "Tree in Inorder is :" << endl;
						sol.inorderPrintTree(root);

						bool ans = sol.isSymmetricTree(root);
						if(ans)
							cout << endl << "Same!" << endl;
						else
							cout << endl << "Not same!" << endl;
						break;
					}
			case 14: {	TreeNode *root = new TreeNode(1); 
					    root->left = new TreeNode(2);  
					    root->left->left = new TreeNode(3); 
					    root->left->right = new TreeNode(4);
					    root->right = new TreeNode(5); 
					    root->right->left = new TreeNode(6); 
					    root->right->right = new TreeNode(7);

					    cout << endl << "The Inorder Print of Tree is :" << endl;
						sol.inorderPrintTree(root);

						TreeNode *ans = sol.invertTree(root);

						cout << endl << "The Inverted Tree in Inorder is :" << endl;
						sol.inorderPrintTree(ans);

						break;
					}
			case 15: {	vector<int> temp = {-1,0,1,2,-1,-4};
						cout << "Initial vector : ";
		    			for (auto it = temp.begin(); it != temp.end(); ++it) 
	        				cout << *it << " ";
	        			cout << endl;

						vector<vector<int>> ans = sol.threeSum(temp);

						break;
					}
			case 16: {	TreeNode *root = new TreeNode(1); 
					    root->left = new TreeNode(2);  
					    root->left->left = new TreeNode(3); 
					    root->left->right = new TreeNode(4);
					    root->right = new TreeNode(5); 
					    root->right->left = new TreeNode(6); 
					    root->right->right = new TreeNode(7);
						
						sol.levelOrderTreePrint(root);

						break;
					}
			case 17: {	int arr[500], x;
						int n1 = sizeof(arr)/sizeof(arr[0]);

		        		srand((unsigned)time(NULL));
						for (int i=0; i < n1; i++)
						{
					        int b = rand() % 600 + 1;
					        arr[i]=b;
						}

						sort(arr,arr+n1);

						x = rand() % 600 + 1;

						cout<<"Current array is : ";
	     				for (int i=0; i<n1; i++) 
	        				cout << arr[i] << " ";
	        			cout<< endl << "Value to be searched is : " << x <<endl;
	     				
						sol.binarySearch(arr, x, n1);

						break;
					}
			case 18: {	int arr[100];
						int n1 = sizeof(arr)/sizeof(arr[0]);

		        		srand((unsigned)time(NULL));
						for (int i=0; i < n1; i++)
					        arr[i] = rand() % 200 + 1;

						cout<<"Current array is : ";
	     				for (int i=0; i<n1; i++) 
	        				cout << arr[i] << " ";

						bool ans = sol.pythagoreanTriplet(arr, n1);

						break;
					}
			case 19: {	

						break;
					}
			case 20: {	

						break;
					}
			case 21: {	

						break;
					}
			case 22: {	

						break;
					}
	        
    	}

		cout << "\n\n#################################\n";

		

    }


    return 0;
}