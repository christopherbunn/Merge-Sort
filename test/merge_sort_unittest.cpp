#include "merge_sort.h"
#include "gtest/gtest.h"

bool ArraysMatch (int *A, int *B, int size){
	bool returnBool = true;
	for (int k = 0; k < size; k++){
	  if (A[k] != B[k]){
	  	std::cout << " DONT WORK AT POSITION: " << k << "EXPECTED "<< A[k] << " GOT " << B[k] << std::endl;
	  	returnBool = false;
	  }
	}
	return returnBool;
}

TEST(MergeSortTest, JustZero){
  int start[1] = {0};
  int expected_result[1] = {0};
  int *gathered_result = MergeSort(start,1);
  EXPECT_TRUE(ArraysMatch(expected_result, gathered_result, 1));
}

TEST(MergeSortTest, Backwards){
  int start[9] = {9,8,7,6,5,4,3,2,1};
  int expected_result[9] = {1,2,3,4,5,6,7,8,9};
  int *gathered_result = MergeSort(start,9);
  EXPECT_TRUE(ArraysMatch(expected_result, gathered_result, 9));
}

TEST(MergeSortTest, AllEights){
  int start[6] = {8,8,8,8,8,8};
  int expected_result[6] = {8,8,8,8,8,8};
  int *gathered_result = MergeSort(start,6);
  EXPECT_TRUE(ArraysMatch(expected_result, gathered_result, 6));
}

TEST(MergeSortTest, Empty){
  int start[0] = {};  
  int expected_result[0] = {};
  int *gathered_result = MergeSort(start,0);
  //EXPECT_TRUE(ArraysMatch(expected_result, gathered_result, 0));
  ASSERT_DEATH(MergeSort(start,0), "");
}

