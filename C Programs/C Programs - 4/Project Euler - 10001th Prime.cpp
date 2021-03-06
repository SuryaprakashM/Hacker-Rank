#include <cstdio>
#include <vector>

using namespace std;

vector <int> prime;

void precompute_primes()
{
    vector <int> is_prime(1e6 + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 1e6; multiple +=i)
            {
                is_prime[multiple] = false;
            }
            prime.push_back(i);
        }
    }
}

void solve()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", prime[n - 1]); //0-Indexed
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    precompute_primes();

    while(no_of_test_cases--)
        solve();

    return 0;
}
