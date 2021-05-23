/*
 * project2.cpp
 *
 * The implementation file where you will implement your code for Project 2.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file, or the autograder will fail. You may add helper functions for
 * any function other than Sum in Question 1.
 */

#include <iostream>
#include "project2.h"
#include "recursive_list.h"

/** QUESTION 1: SUM AND PRODUCT **/

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// Your implementation of Sum should NOT be tail recursive and should NOT
// use a helper function.
//
//PSEUDOCODE:
// algorithm Sum of List
//  Input: list of numbers, or zero if list is empty
//  Output: Sum  of lists
/*  sumRecursive(List)
	{

		if ListIsEmpty
			return List 
		else 
			value = ListFirst(list)  //getting first element of list
			new_list = ListRest(list) //getting remaining elements of list
		return value+sumRecursive(new_list)
	}
*/     
// COMMENTS:
// We add first element with sum(n-1) elements reduces the problem into a tail recursive function
// sum of all elements = sum of first element+ sum of remaining elements i.e n-1.
// sum of remaining elements will again recursively call the  sum function to calculate the final sum

int Sum(RecursiveList list) {
	if (ListIsEmpty(list))
		return 0;
	return ListFirst(list) + Sum(ListRest(list));
}

// EFFECTS: returns the product of each element in list, or one if the list is
//          empty
//PSEUDOCODE:
// algorithm Product of List
//  Input: list of numbers, or zero if list is empty
//  Output: Product  of lists
/*  ProductRecursive(List)
	{

		if ListIsEmpty
			return List 
		else 
			value = ListFirst(list)  //getting first element of list
			new_list = ListRest(list) //getting remaining elements of list
		return value*ProductRecursive(new_list)
	}
*/     
// COMMENTS:
// We product first element with Product(n-1) elements reduces the problem into a tail recursive function
// Product of all elements = Product of first element+ Product of remaining elements i.e n-1.
// Product of remaining elements will again recursively call the Product function to calculate the final
// Product

int Product(RecursiveList list) {
	if (ListIsEmpty(list))
		return 1;
	return ListFirst(list) * Product(ListRest(list));
}

/** QUESTION 2: TAIL RECURSIVE SUM **/

// EFFECTS: adds the next element in the list to the sum so far
// Your implementation of TailRecursiveSumHelper MUST be tail recursive.
//
// PSEUDOCODE:
// algorithm TailRecursiveSumHelper
//   Base Case: If the list is empty retyrn the sum so far
//   Other case: will call the helper function again using the 
//	rest of the list as the list parameter,
// 	and the first element in the list + sum so far, and the sume so far parameter.
//
//PSEUDOCODE:
// algorithm TailRecusiveSumHelper
//  Input: list of numbers, or zero if list is empty
//  Output: Sum  of lists
/*  TailRecursiveSumHelper(List,Sum_so_Far)
	{

		if ListIsEmpty 						//Base Case
			return Sum_so_Far 
		else 
		{
			value = ListFirst(list) 		//extract first element of list
			sum_so_far = value+sum_till_now	//total sum=current_value+total_previous sum
			return TailRecursiveSumHelper(List,sum_so_far)
	}
*/     
// COMMENTS:
// we first extract the  first element of given list
// sum of all elements = value of current element + sum_value till now .

int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
	if (ListIsEmpty(list))
		return sum_so_far;
	return (
		TailRecursiveSumHelper(ListRest(list), ListFirst(list) + sum_so_far));
}

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
// DO NOT MODIFY THIS FUNCTION.
//
// algorithm TailRecursiveSum
//   return TailRecursiveSumHelper(list, 0)
int TailRecursiveSum(RecursiveList list) {
	return TailRecursiveSumHelper(list, 0);
}

/** QUESTION 3: FILTER ODD AND FILTER EVEN 
**/
// EFFECTS:returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
//

//PSEUDOCODE:
// algorithm FilterOdd
//   Base Case: If there are no elements in the list, 
//				it returns and creates a new list, containing odd numbers
//   Other case: If list is not empty, 
//				loop through each element in the list, 
//				and test if element in the list has a modulo of 1, 
//				then returns Filter Odd in order found.
//
/*
	if ListIsEmpty(list)
		return list			//Base Case
	if(length of List==1){
		if(listfirst(list) %2==1)
		return list					//if the only element of list is odd return the list
		return MakeList();			//else create the list
									//return MakeList()
	}

	if(length of List >1){				//if the length is greater than 1
		if(listfirst(list) %2==1)			
		return return MakeList(ListFirst(list),FilterOdd(ListRest(list)))	//Make the recursive call 
	}
	return FilterOdd(ListRest(list))

	*/
// COMMENTS:
/*
	if the list length is of 0 or 1 then it falls under base cases 
	for length of list =0 
	we return the list itself
	for length of list==1
	we return the list if the only element is odd number 
	else we return the empty list
*/


RecursiveList FilterOdd(RecursiveList list) {
  if(ListIsEmpty(list)){
    return list;
	}
	//if one element in the list
	if(ListIsEmpty(ListRest(list))){
			if (ListFirst(list) % 2 == 1){
			  return list;
			}
			//returns empty list if the solo element is even 
			return MakeList();
	}
	//BreakDown:
	if (ListFirst(list) % 2 == 1){
			  return MakeList(ListFirst(list),FilterOdd(ListRest(list)));
	}
	return FilterOdd(ListRest(list));

}

// EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
//
//PSEUDOCODE:
// algorithm FilterEven
//   Base Case: If there are no elements in the list, 
//				it returns and creates a new list, containing even numbers
//   Other case: If list is not empty, 
//				loop through each element in the list, 
//				and test if element in the list has a modulo of 0, 
//				then returns Filter Odd in order found.
//
/*
	if ListIsEmpty(list)
		return list			//Base Case
	if(length of List==1){
		if(listfirst(list) %2==0)
		return list					//if the only element of list is odd return the list
		return MakeList();			//else create the list
									//return MakeList()
	}

	if(length of List >1){				//if the length is greater than 1
		if(listfirst(list) %2==0)			
		return return MakeList(ListFirst(list),FilterOdd(ListRest(list)))	//Make the recursive call 
	}
	return FilterEven(ListRest(list))

	*/
// COMMENTS:
/*
	if the list length is of 0 or 1 then it falls under base cases 
	for length of list =0 
	we return the list itself
	for length of list==0
	we return the list if the only element is even number 
	else we return the empty list
*/
//

RecursiveList FilterEven(RecursiveList list) {
if(ListIsEmpty(list)){
    return list;
	}
	//if one element in the list
	if(ListIsEmpty(ListRest(list))){
			if (ListFirst(list) % 2 == 0){
			  return list;
			}
			//returns empty list if the solo element is odd 
			return MakeList();
	}
	//BreakDown:
	if (ListFirst(list) % 2 == 0){
			  return MakeList(ListFirst(list),FilterEven(ListRest(list)));
	}
	return FilterEven(ListRest(list));
}

/* QUESTION 4: REVERSE 
// EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
//
//PSEUDOCODE:
// algorithm Reverse
//   If(ListEmpty(list))
//    return list
//   if((ListIsEmpty(ListRest(list))))
//    return list
//    else 
//    return MakeList((ListFirst(Reverse(ListRest(list),MakeList(ListFirsrt(list),MakeList()))))

// COMMENTS:
	if the list is empty return the empty list
	if the list contains only one element return the list 
	
	if theres 2 or more elements in the list append 
	reversearray on a smaller portion to a list 
	containing the first element of your list

*/

RecursiveList Reverse(RecursiveList list) {
	if(ListIsEmpty(list)){
	  return list;
	}
	//if list one only has one element , return the list
	if((ListIsEmpty(ListRest(list)))){
	  return list;
	}
	// if theres 2 or more elements in the list append reversearray on a smaller portion to a list containing the first element of your list
	return Append(Reverse(ListRest(list)), MakeList(ListFirst(list),MakeList()));

}

// QUESTION 5: APPEND 

// EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
//
// PSEUDOCODE:
// algorithm Append
/*
	if First List is empty
	  return second_list;

	//if list one only has one element ,
	 	new_list = append(first_list,second_list) 
		 return newlist
	  
	//other wise call append recursively on a smaller sprtion of list one
	new_list = ListFirst(first_list),Append(ListRest(first_list),second_list)
	return new_list
*/
// COMMENTS:

RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
	if(ListIsEmpty(first_list)){
	  return second_list;
	}
	//if list one only has one element , append it to list 2 and return newlist
	if((ListIsEmpty(ListRest(first_list)))){
	  return MakeList(ListFirst(first_list),second_list);
	}
	//other wise call append recursively on a smaller sprtion of list one
	return MakeList(ListFirst(first_list),Append(ListRest(first_list),second_list));
}

/** QUESTION 6: CHOP **/

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//

//PSEUDOCODE:
// algorithm Chop
//   return ChopHelper(reverse(list),MakeList(), n)
// algorithm chopHelper
//   if(n>0 && ListIsEmpty(list))
//    else
//    if(n=0)
//    return reverse(list)
//    else
//    return ChopHelper(listRest(list),MakeList(ListFirst(list),new_list), n-1)
//

// COMMENTS:

RecursiveList ChopHelper(RecursiveList list, RecursiveList new_list, unsigned int n) {
  if ( n > 0 && ListIsEmpty(list) ) {
      std::cerr << "error: user passed empty list where non-empty required\n";
    }
     else {
       if (n == 0) {
            return Reverse(list);
        }
          else {
            return ChopHelper(ListRest(list), MakeList(ListFirst(list), new_list), n - 1);
        }
    }
  return MakeList();  
}
RecursiveList Chop(RecursiveList list, unsigned int n) {
    // Implement this function.
    return ChopHelper(Reverse(list), MakeList(), n);
}
/** QUESTION 7: ROTATE **/

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
	// algorithm Rotate
	//   return RotateHelper (list, MakeList(),n)
	// algorithm RotateHelper
	//  if (n > 0 && ListIsEmpty(List))
	//  RotateHelper(Recursive(new_list), MakeList(), n)
	//  else
	//   if (n =0)
	//    return Append(list, Reverse(new_list))
	//    else
	//    RotateHelper(ListRest(list), MakeList(ListFirst(list), new_list), n -1)

// COMMENTS:

RecursiveList Rotate(RecursiveList list, unsigned int n) {
    // Implement this function.
  if (n == 0){ 
        return list;
    }
    if (n==1){
        return (Append(ListRest(list),(MakeList(ListFirst(list),MakeList()))));
    }
  return Rotate(Append(ListRest(list),(MakeList(ListFirst(list),MakeList()))), n-1);

}
/** QUESTION 8: INSERT LIST **/

// REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
//
// PSEUDOCODE:
	// algorithm InsertList
	//   return InsertHelper(first_list, MakeList(), second_list,n)
	//   algorithm InsertListHelper
	//   if (n > 0 && ListIsEmpty(list))
	//   InsertHelper(Reverse(new_list), MakeList(), static_list, n)
	//   else
	//   if(n=0)
	//   return Append(Append(Reverse(new_list), static_list),list)

// COMMENTS:

RecursiveList InsertList(RecursiveList first_list,
RecursiveList second_list,
    unsigned int n) {
    if (n == 0){ 
        return Append(second_list, first_list);
    }
    if (n==1){
        return Append(MakeList(ListFirst(first_list), second_list), ListRest(first_list));
    }
    return MakeList(ListFirst(first_list),InsertList(ListRest(first_list),second_list, n-1));
}