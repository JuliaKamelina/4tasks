#include <gtest/gtest.h>
#include "func.h"

TEST(reverseNumber, can_reverse_numder) {
  int x = 123;
  int expX = 321;
  
  int y = reverseNumber(x);
  
  EXPECT_EQ(expX, y);
}

TEST(reverseNumber, can_reverse_negative_number) {
  int x = -123;
  int expX = -321;
  
  int y = reverseNumber(x);
  
  EXPECT_EQ(expX, y);
}

TEST(reverseNumber, number_ends_with_0) {
  int x = 10;
  int expX = 1;
  
  int y = reverseNumber(x);
  
  EXPECT_EQ(expX, y);
}

TEST(findPref, can_find_prefix) {
  char *s[] = {"abcd", "ab6c", "addf", "aadhg"};
  char *expPref = {"a"};
 
  char *pref = findPref(s, 4);

  for (int i = 0; pref[i] != 0; i++)
    EXPECT_EQ(pref[i], expPref[i]);
}

TEST(findPref, prefix_doest_exist) {
  char *s[] = {"abcd", "ab6c", "cddf"};
 
  char *pref = findPref(s, 3);
  
  EXPECT_EQ(0, *pref);
}

TEST(reverseList, can_reverse_pairs) {
  CNode list[4];
  CNode expList[4];
  
  for (int i = 0; i < 3; i++) {
    list[i].next = &list[i + 1];
    list[i].data = i + 1;
    expList[i].next = &expList[i + 1];
  }
  
  list[3].data = 4;
  list[3].next = NULL;
  
  expList[3].next = NULL;
  expList[0].data = 2;
  expList[1].data = 1;
  expList[2].data = 4;
  expList[3].data = 3;

  reverseList(list);
  
  for (int i = 0; i < 4; i++)
    EXPECT_EQ(list[i].data, expList[i].data);
}

TEST(reverseList, can_revers_when_odd_number_of_nodes) {
  CNode list[5];
  CNode expList[5];
  
  for (int i = 0; i < 4; i++) {
    list[i].next = &list[i + 1];
    list[i].data = i + 1;
    expList[i].next = &expList[i + 1];
  }
  
  list[4].data = 5;
  list[4].next = NULL;
  
  expList[4].next = NULL;
  expList[0].data = 2;
  expList[1].data = 1;
  expList[2].data = 4;
  expList[3].data = 3;
  expList[4].data = 5;
  
  reverseList(list);
  
  for (int i = 0; i < 5; i++)
    EXPECT_EQ(list[i].data, expList[i].data);
}

TEST(reverseList, throws_when_empty_list) {
  CNode *list = 0;
  
  ASSERT_ANY_THROW(reverseList(list));
}

TEST(findSumElements, can_find_elements) {
  const int n = 5;
  int a[5] = {-1, 0, 2, 3, 6};
  int sum = 5;
  
  int *res = findSumElements(a, n, sum);
  
  for (int i = 0; i < n; i++)
    if (res[i] >= 0)
      EXPECT_EQ(a[i] + a[res[i]], sum);
}

TEST(findSumElements, throws_when_elements_doest_exist) {
  const int n = 5;
  int a[5] = {-1, 0, 2, 3, 6};
  int sum = 50;
  
  int *res = 0;
  ASSERT_ANY_THROW(findSumElements(a, n, sum));
}

int main(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}