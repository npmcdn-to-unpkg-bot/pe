#include <prime.h>

#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>

using namespace std;

/*
 * get prime number list with sieve algorhythm
 * @param[out] p Array for the list
 * @param[in]  l Length of the list
 * @return
 */
int sieve(vector<int>& p, int l) {
  int i, j, sq, limit, *s;
  double times;

  if (l < 1) {
    return 0;
  }
  if (l < 50) {
    times = 5.0;
  } else {
    times = log(l) + 2.0;
  }
  limit = static_cast<int>(floor(l * times));

  s = new int[limit];
  if (!s) {
    cerr << "failed malloc: " << __FILE__ << ":" << __LINE__ << endl;
    return 0;
  }

  sq = static_cast<int>(floor(sqrt(limit)));
  s[0] = 0;
  s[1] = 0;
  for (i = 2; i < limit + 1; ++i) {
    s[i] = 1;
  }
  for (i = 2; i < sq + 1; ++i) {
    for (j = i * i; j < limit + 1; j += i) {
      s[j] = 0;
    }
  }

  j = 0;
  for (i = 0; j < l; ++i) {
    if (s[i]) {
      p.push_back(i);
      ++j;
    }
  }

  delete [] s;
  return j;
}

/*
 * get prime number list below limit
 * @param[out] p
 * @param[in]  limit
 * @return length
 */
int sieve_below(vector<int>& p, int limit) {
  int i, j, sq, *s;

  s = new int[limit];
  if (!s) {
    cerr << "failed malloc: " << __FILE__ << ":" << __LINE__ << endl;
    return 0;
  }

  sq = static_cast<int>(floor(sqrt(limit)));
  s[0] = 0;
  s[1] = 0;
  for (i = 2; i < limit + 1; ++i) {
    s[i] = 1;
  }
  for (i = 2; i < sq + 1; ++i) {
    for (j = i * i; j < limit + 1; j += i) {
      s[j] = 0;
    }
  }

  j = 0;
  for (i = 0; i < limit + 1; ++i) {
    if (s[i]) {
      p.push_back(i);
      ++j;
    }
  }

  delete [] s;
  return j;
}

/*
 * mod_math_pow
 * @param[in] base
 * @param[in] power
 * @param[in] mod
 * @return [base]^[power] (mod [mod])
 */
int mod_math_pow(int base, int power, int mod) {
  int result = 1;

  while (power > 0) {
    if (power & 1) {
      result = result * base % mod;
    }
    base = base * base % mod;
    power >>= 1;
  }

  return result;
}

/*
 * Miller-Rabin primality test
 * @param[in] n Target number
 * @param[in] i Repeat times of the test
 * @return 1 means prime
 */
int mrpt(int n, int i) {
  int a, d, t, y;

  if (n == 2) {
    return 1;
  }
  
  assert(n <= 0xfffffff);
  if (n < 2 || (n & 1) == 0) {
    return 0;
  }

  d = n - 1;
  srand(static_cast<unsigned int>(time(NULL)));
  while ((d & 1) == 0) {
    d >>= 1;
  }

  while (i--) {
    a = rand() % (n - 1) + 1;
    t = d;
    y = mod_math_pow(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && (t & 1) == 0) {
      return 0;
    }
  }

  return 1;
}