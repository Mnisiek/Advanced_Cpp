
/*
2. Wykonanie bardzo prostego programu:  

#include <vector>  
#include <algorithm>  
#include <execution>  
#include <mutex>  


int main()
{  
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::for_each(std::execution::par, vec.begin(), vec.end(),  
    [&output](int& elem) { if (elem % 2 == 0) { output.push_back(elem); } });  
}

zakończy się tragicznie z punktu widzenia programisty (core dupmed).
Wykorzystując std::lock_guard, zmodyfikuj lambda expression tak,
aby nie dochodziło do niezsynchronizowanego dostępu do wektora wyjściowego.
Porównaj wydajność przy wykorzystaniu polityki typu seq.  
*/