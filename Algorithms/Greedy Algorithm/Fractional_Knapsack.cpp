#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int value;
  int weight;
};

bool cmp(pair<double,Item> a, pair<double,Item> b){
    return a.first > b.first;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
  vector<pair<double,Item>> v;
   
  for(int i = 0; i < n; i++){
    double perUnitValue = (1.0*arr[i].value)/arr[i].weight;
    pair<double,Item> p = make_pair(perUnitValue,arr[i]);
    v.push_back(p);
  }

  sort(v.begin(),v.end(), cmp);
  
  double totalValue = 0;

  for (int i = 0; i < n; i++)
  {
    if(v[i].second.weight > W){

      totalValue += W*v[i].first;
      W = 0;

    }else{
      totalValue += v[i].second.value;
      W = W - v[i].second.weight;
    }
  }

  return totalValue;
  
}

int main()
{

  Item arr[5];

  Item i1, i2, i3, i4, i5;
  i1.value = 60;
  i1.weight = 10;
  i2.value = 100;
  i2.weight = 20;
  i3.value = 120;
  i3.weight = 30;
  int W = 50;

  arr[0] = i1;
  arr[1] = i2;
  arr[2] = i3;

  cout << fractionalKnapsack(W, arr, 3);

  return 0;
}