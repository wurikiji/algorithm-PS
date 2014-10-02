bool bitmask[1000001];
bool weird(int n)
{
  vector divisors;
  divisors.push_back(1);
  for(int i = 2; i*i <= n; ++i)
  {
    if(n % i == 0)
    {
      divisors.push_back(i);
      if(n / i != i)
        divisors.push_back(n / i);
    }
  }
  if(accumulate(divisors.begin(), divisors.end(), 0) <= n) return false;

  memset(bitmask, 0, sizeof(bitmask));
      bitmask[0] = true;
      for(int i = 0; i < divisors.size(); ++i)
      {
      for(int j = n - divisors[i]; j >= 0; --j) if(bitmask[j])
      if(j + divisors[i] <= n)
      {
      bitmask[j + divisors[i]] = true;
      if(j + divisors[i] == n)
      return false;
      }
      }
      return true;
      }
      bool weird2(int n)
      {
      vector canMake;
      vector divisors;
      divisors.push_back(1);
      for(int i = 2; i*i <= n; ++i)
      {
        if(n % i == 0)
        {
          divisors.push_back(i);
          if(n / i != i)
            divisors.push_back(n / i);
        }
      }
      if(accumulate(divisors.begin(), divisors.end(), 0) <= n) return false;
      memset(bitmask, 0, sizeof(bitmask);
          canMake.clear();
          canMake.reserve(n+10);
          bitmask[0] = true;
          canMake.push_back(0);
          for(int i = 0; i < divisors.size(); ++i)
          for(int j = canMake.size()-1; j >= 0; --j)
          {
          int k = canMake[j] + divisors[i];
          if(!bitmask[k] && k <= n)
          {
          if(k == n) return false;
          bitmask[k] = true;
          canMake.push_back(k);
          }
          }
          return true;
          }
