#include "func.h"
#include <stdexcept>

int reverseNumber(int x) {
	int res = 0;
	while (x != 0) {
		res = res*10 + x%10;
		x = x/10;
	}
	return res;
}

char * findPref(char **s, int count) {
	int num = 0;
	int j = 0;
	bool f = true;
	
	while (s[0][j] != 0) {
	  char c = s[0][j];
	  for (int i = 1; i < count; i++)
	    if (c != s[i][j]) {
	      f = false;
	      break;
	    }

	  if (f) {
	    num++;
	    j++;
	  } else
	      break;
	}
	
  char *res = new char[num + 1];
  for (int i = 0; i < num; i++)
	  res[i] = s[0][i];
	res[num] = 0;
	
	return res;
}

void reverseList(CNode *list) {
  if (list != 0) {
    int tmp;
    CNode *node = 0;

    while((list != 0) && (list->next != 0)) {
      node = list;
      tmp = node->data;
      list = list->next;
      node->data = list->data;
      list->data = tmp;
      list = list->next;
    }
  } else
     throw std::logic_error("List is empty");
}
 
int * findSumElements(int b[], int n, int sum) { 
  int *res = new int[n];
  bool f = false;
  for (int i = 0; i < n; i++)
    res[i] = -1;
  
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if ((b[i] + b[j]) == sum) {
        res[i] = j;
        f = true;
        break;
      }
  if (f)
    return res;
  else throw std::logic_error("Couldn't find any numbers");
}
