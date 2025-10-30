#include <vector>

class GeradorPrimos {
public:
    GeradorPrimos(int n=1000000) : n(n){
        primos = sieve(n);
    }
    // retorna o menor primo > a
    int proximo(int a){
        //todo: considerar que n pode ser muito grande!
        if(a >= primos[primos.size()-1]){
            n = n*2;
            primos = sieve(n);
        }

        int i = buscar(a);
        //std::cout << i << std::endl;

        return primos[i];
    }
    
private:
    int buscar(int a){
        int l = 0, r = primos.size()-1;
        while(l <= r){
            //std::cout << l << " " << r << std::endl;
            int m = (l+r)/2;
            if(primos[m] == a) return m;
            if(a < primos[m]) r = m-1;
            else l = m+1;
        }
        return l;
    }
    std::vector<int> sieve(int n){
        std::vector<int> primes;
        std::vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for(int i = 2; i <= n; i++){
            if(is_prime[i]){
                primes.push_back(i);
                for(int j = i*2; j <= n; j += i){
                    is_prime[j] = false;
                }
            }
        }
        return primes;
    }
    int n;
    std::vector<int> primos;  
};

